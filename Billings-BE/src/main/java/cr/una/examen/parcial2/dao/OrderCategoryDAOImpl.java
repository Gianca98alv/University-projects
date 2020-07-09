package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.OrderCategory;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.ResultSet;
import java.sql.SQLException;

public class OrderCategoryDAOImpl implements OrderCategoryDAO {

    // Using logger for project
    final Logger logger = LogManager.getLogger(OrderCategoryDAOImpl.class);

    private final JdbcUtil jdbcUtil = JdbcUtil.instance();

    @Override
    public OrderCategory save(OrderCategory orderCategory) throws SQLException {
        long idOrderCategory;
        String sql = "INSERT INTO orderCategory (category, percentage)"
                + "VALUES('%s', %d)";
        sql = String.format(sql, orderCategory.getCategory(), orderCategory.getPercentage());
        idOrderCategory = jdbcUtil.executeAddAI(sql);
        if (idOrderCategory == 0) {
            throw new SQLException("Order Status already exist");
        }
        orderCategory.setIdOrderCategory(idOrderCategory);
        return orderCategory;
    }

    @Override
    public OrderCategory findById(Long idOrderCategory) throws SQLException {
        OrderCategory orderCategory = new OrderCategory(null);
        String sql = "SELECT * FROM orderCategory where idOrderCategory = %d";
        sql = String.format(sql, idOrderCategory);
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        if(resultSet.next()) {
            orderCategory.setIdOrderCategory(resultSet.getLong("idOrderCategory"));
            orderCategory.setCategory(resultSet.getString("category"));
            orderCategory.setPercentage(resultSet.getLong("percentage"));
        }
        return orderCategory;
    }

}

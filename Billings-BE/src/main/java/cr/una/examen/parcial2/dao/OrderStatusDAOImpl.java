package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.OrderStatus;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.ResultSet;
import java.sql.SQLException;

public class OrderStatusDAOImpl implements OrderStatusDAO {

    // Using logger for project
    final Logger logger = LogManager.getLogger(OrderStatusDAOImpl.class);

    private final JdbcUtil jdbcUtil = JdbcUtil.instance();

    @Override
    public OrderStatus save(OrderStatus orderStatus) throws SQLException {
        long idOrderStatus;
        String sql = "INSERT INTO orderstatus (status) "
                + "VALUES('%s')";
        sql = String.format(sql, orderStatus.getStatus());
        idOrderStatus = jdbcUtil.executeAddAI(sql);
        if (idOrderStatus == 0) {
            throw new SQLException("Order Status already exist");
        }
        orderStatus.setIdOrderStatus(idOrderStatus);
        return orderStatus;
    }

    @Override
    public OrderStatus findById(Long idOrderStatus) throws SQLException {
        OrderStatus orderStatus = new OrderStatus(null);
        String sql = "SELECT * FROM orderstatus where idOrderStatus = %d";
        sql = String.format(sql, idOrderStatus);
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        if(resultSet.next()) {
            orderStatus.setIdOrderStatus(resultSet.getLong("idOrderStatus"));
            orderStatus.setStatus(resultSet.getString("status"));
        }
        return orderStatus;
    }
}

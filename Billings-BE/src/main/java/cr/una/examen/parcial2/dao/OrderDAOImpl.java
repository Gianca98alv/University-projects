package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.Client;
import cr.una.examen.parcial2.model.Order;
import cr.una.examen.parcial2.model.OrderCategory;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;

public class OrderDAOImpl implements OrderDAO {

    // Using logger for project
    final Logger logger = LogManager.getLogger(OrderDAOImpl.class);

    private final JdbcUtil jdbcUtil = JdbcUtil.instance();

    public List<Order> findAll() throws SQLException {
        List<Order> ordersList = new ArrayList<>();
        ClientDAOImpl clientDAOImpl = new ClientDAOImpl();
        OrderCategoryDAOImpl orderCategoryDAOImpl = new OrderCategoryDAOImpl();
        OrderStatusDAOImpl orderStatusDAOImpl = new OrderStatusDAOImpl();
        String sql = "SELECT * FROM `order`";
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        while (resultSet.next()) {

            Order order = new Order(resultSet.getLong("idOrder"), clientDAOImpl.findById(resultSet.getLong("client")),
                    orderStatusDAOImpl.findById(resultSet.getLong("orderStatus")),
                    orderCategoryDAOImpl.findById(resultSet.getLong("orderCategory")),
                    resultSet.getInt("orderNumber"), resultSet.getDate("date") ,
                    resultSet.getFloat("cost"), resultSet.getFloat("costIVA"));

            ordersList.add(order);
        }
        return ordersList;
    }

    @Override
    public Order findById() throws SQLException {
        Order order = null;
        ClientDAOImpl clientDAOImpl = new ClientDAOImpl();
        OrderCategoryDAOImpl orderCategoryDAOImpl = new OrderCategoryDAOImpl();
        OrderStatusDAOImpl orderStatusDAOImpl = new OrderStatusDAOImpl();
        String sql = "SELECT * FROM `order`";
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        if (resultSet.next()) {
            order = new Order(resultSet.getLong("idOrder"), clientDAOImpl.findById(resultSet.getLong("idClient")),
                    orderStatusDAOImpl.findById(resultSet.getLong("orderStatus")),
                    orderCategoryDAOImpl.findById(resultSet.getLong("orderCategory")),
                    resultSet.getInt("orderNumber"), resultSet.getDate("date"),
                    resultSet.getFloat("cost"), resultSet.getFloat("costIVA"));
        }
        return order;
    }

    public Order save(Order order) throws SQLException {
        long idOrder;
        ClientDAOImpl clientDAOImpl = new ClientDAOImpl();
        OrderCategoryDAOImpl orderCategoryDAOImpl = new OrderCategoryDAOImpl();
        Client client = clientDAOImpl.findById(order.getClient().getIdClient());

        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd");
        String date = formatter.format(order.getDate());

        if(client.getIva()) {
            OrderCategory orderCategory = orderCategoryDAOImpl.findById(order.getOrderCategory().getIdOrderCategory());
            order.setCostIVA(order.getCost() + (order.getCost() * (((float) (orderCategory.getPercentage())) / 100)));
        } else {
            order.setCostIVA(order.getCost());
        }

        String sql = "INSERT INTO `order` (orderNumber, client, orderStatus, orderCategory, date, cost, costIVA)"
                + "VALUES(%d, %d, %d, %d, '%s', %f, %f)";
        sql = String.format(sql, order.getOrderNumber(), order.getClient().getIdClient(),
                order.getOrderStatus().getIdOrderStatus(), order.getOrderCategory().getIdOrderCategory(),
                date, order.getCost(), order.getCostIVA());
        idOrder = jdbcUtil.executeAddAI(sql);

        if (idOrder == 0) {
            throw new SQLException("Order already exist");
        }
        order.setIdOrder(idOrder);
        return order;
    }

}

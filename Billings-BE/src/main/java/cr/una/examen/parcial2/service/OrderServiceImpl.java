package cr.una.examen.parcial2.service;

import cr.una.examen.parcial2.dao.OrderDAOImpl;
import cr.una.examen.parcial2.model.Order;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.SQLException;
import java.util.List;

public class OrderServiceImpl implements OrderService {

    // Using logger for project
    final Logger logger = LogManager.getLogger(OrderServiceImpl.class);


    @Override
    public Order findById(Long idOrder) throws SQLException {
        OrderDAOImpl orderDAOImpl = new OrderDAOImpl();
        return orderDAOImpl.findById();
    }

    public List<Order> findAll() throws SQLException {
        OrderDAOImpl orderDAOImpl = new OrderDAOImpl();
        return orderDAOImpl.findAll();
    }

}

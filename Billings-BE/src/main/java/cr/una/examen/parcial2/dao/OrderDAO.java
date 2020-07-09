package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.Order;

import java.sql.SQLException;
import java.util.List;

public interface OrderDAO {
    public List<Order> findAll() throws SQLException;
    public Order findById() throws SQLException;
    public Order save(Order order) throws SQLException;
}

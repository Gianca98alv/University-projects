package cr.una.examen.parcial2.service;

import cr.una.examen.parcial2.model.Order;

import java.sql.SQLException;
import java.util.List;

public interface OrderService {

    public Order findById(Long idOrder) throws SQLException;
    public List<Order> findAll() throws SQLException;

}

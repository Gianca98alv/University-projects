package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.OrderStatus;

import java.sql.SQLException;

public interface OrderStatusDAO {
    public OrderStatus save (OrderStatus orderStatus) throws SQLException;
    public OrderStatus findById(Long idOrderStatus) throws SQLException;
}

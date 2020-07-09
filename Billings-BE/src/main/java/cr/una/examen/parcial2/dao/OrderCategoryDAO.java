package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.OrderCategory;

import java.sql.SQLException;

public interface OrderCategoryDAO {
    public OrderCategory save (OrderCategory orderCategory) throws SQLException;
    public OrderCategory findById(Long idOrderCategory) throws SQLException;
}

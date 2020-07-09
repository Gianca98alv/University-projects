package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.ClientPhone;

import java.sql.SQLException;
import java.util.List;

public interface ClientPhoneDAO {
    public ClientPhone save(ClientPhone clientPhone) throws SQLException;
    public List<ClientPhone> findByIdClient(Long idClient) throws SQLException;
}

package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.Client;

import java.sql.SQLException;
import java.util.List;

public interface ClientDAO {
    public Client findById (Long idClient) throws SQLException;
    public Client save (Client client) throws SQLException;
    public List<Client> findAll() throws SQLException;
}

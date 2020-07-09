package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.ClientAddress;

import java.sql.SQLException;
import java.util.List;

public interface ClientAddressDAO {
    public ClientAddress save (ClientAddress clientAddress) throws SQLException;
    public List<ClientAddress> findByIdClient (Long idClient) throws SQLException;
}

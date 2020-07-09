package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.ClientAddress;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ClientAddressDAOImpl implements ClientAddressDAO {

    // Using logger for project
    final Logger logger = LogManager.getLogger(ClientAddressDAOImpl.class);

    private final JdbcUtil jdbcUtil = JdbcUtil.instance();

    @Override
    public ClientAddress save(ClientAddress clientAddress) throws SQLException {
        long idClientAddress;
        String sql = "INSERT INTO clientaddress (address, type, idClient)"
                + "VALUES('%s', '%s', %d)";
        sql = String.format(sql, clientAddress.getAddress(), clientAddress.getType(), clientAddress.getIdClient());
        idClientAddress = jdbcUtil.executeAddAI(sql);
        if (idClientAddress == 0) {
           throw new SQLException("Client Address already exist");
        }
        clientAddress.setIdClientAddress(idClientAddress);
        return clientAddress;
    }

    @Override
    public List<ClientAddress> findByIdClient(Long idClient) throws SQLException {
        List<ClientAddress> clientAddressList = new ArrayList<>();
        String sql = "SELECT * FROM clientaddress where idClient = %d";
        sql = String.format(sql, idClient);
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        while(resultSet.next()) {
           ClientAddress clientAddress = new ClientAddress(resultSet.getLong("idClientAddress"),
                    resultSet.getString("address"), resultSet.getString("type"));
           clientAddress.setIdClient(resultSet.getLong("idClient"));
           clientAddressList.add(clientAddress);
        }
        return clientAddressList;
    }
}

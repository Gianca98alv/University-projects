package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.Client;
import cr.una.examen.parcial2.model.ClientAddress;
import cr.una.examen.parcial2.model.ClientPhone;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ClientDAOImpl implements ClientDAO {

    // Using logger for project
    final Logger logger = LogManager.getLogger(ClientDAOImpl.class);

    private final JdbcUtil jdbcUtil = JdbcUtil.instance();

    @Override
    public Client findById(Long idClient) throws SQLException {
        Client client = null;
        ClientAddressDAOImpl clientAddressDAOImpl = new ClientAddressDAOImpl();
        ClientPhoneDAOImpl clientPhoneDAOImpl = new ClientPhoneDAOImpl();
        String sql = "SELECT * FROM client where idClient = %d";
        sql = String.format(sql, idClient);
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        if(resultSet.next()) {
            client = new Client(resultSet.getLong("idClient"),
                    resultSet.getString("name"), resultSet.getString("lastName"), resultSet.getBoolean("iva"));
            client.setClientAddresses(clientAddressDAOImpl.findByIdClient(resultSet.getLong("idClient")));
            client.setClientPhones(clientPhoneDAOImpl.findByIdClient(resultSet.getLong("idClient")));
        }
        return client;
    }

    @Override
    public Client save(Client client) throws SQLException {
        long idClient;
        ClientAddressDAOImpl clientAddressDAOImpl = new ClientAddressDAOImpl();
        ClientPhoneDAOImpl clientPhoneDAOImpl = new ClientPhoneDAOImpl();
        String sql = "INSERT INTO client (name, lastName, iva)"
                + "VALUES('%s', '%s', %b)";
        sql = String.format(sql, client.getName(), client.getLastName(), client.getIva());
        idClient = jdbcUtil.executeAddAI(sql);

        if (idClient == 0) {
            throw new SQLException("Client already exist");
        }

        client.setIdClient(idClient);
        for(ClientAddress clientAddress : client.getClientAddresses()) {
            clientAddress.setIdClient(idClient);
            clientAddress = clientAddressDAOImpl.save(clientAddress);
        }

        for(ClientPhone clientPhone : client.getClientPhones()) {
            clientPhone.setIdClient(idClient);
            clientPhone = clientPhoneDAOImpl.save(clientPhone);
        }

        return client;
    }

    @Override
    public List<Client> findAll() throws SQLException {
        List<Client> clientsList = new ArrayList<>();
        ClientAddressDAOImpl clientAddressDAOImpl = new ClientAddressDAOImpl();
        ClientPhoneDAOImpl clientPhoneDAOImpl = new ClientPhoneDAOImpl();
        String sql = "SELECT * FROM client";
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        while(resultSet.next()) {
            Client client = new Client(resultSet.getLong("idClient"),
                    resultSet.getString("name"), resultSet.getString("lastName"), resultSet.getBoolean("iva"));
            client.setClientAddresses(clientAddressDAOImpl.findByIdClient(resultSet.getLong("idClient")));
            client.setClientPhones(clientPhoneDAOImpl.findByIdClient(resultSet.getLong("idClient")));
            clientsList.add(client);
        }
        return clientsList;
    }
}

package cr.una.examen.parcial2.dao;

import cr.una.examen.parcial2.model.ClientPhone;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ClientPhoneDAOImpl implements ClientPhoneDAO {

    // Using logger for project
    final Logger logger = LogManager.getLogger(ClientPhoneDAOImpl.class);

    private final JdbcUtil jdbcUtil = JdbcUtil.instance();

    @Override
    public ClientPhone save(ClientPhone clientPhone) throws SQLException {
        long idClientPhone;
        String sql = "INSERT INTO clientphone (phone, type, idClient)"
                + "VALUES('%s', '%s', %d)";
        sql = String.format(sql, clientPhone.getPhone(), clientPhone.getType(), clientPhone.getIdClient());
        idClientPhone = jdbcUtil.executeAddAI(sql);
        if (idClientPhone == 0) {
            throw new SQLException("Client Phone already exist");
        }
        clientPhone.setIdClientPhone(idClientPhone);
        return clientPhone;
    }

    @Override
    public List<ClientPhone> findByIdClient(Long idClient) throws SQLException {
        List<ClientPhone> clientPhonesList = new ArrayList<>();
        String sql = "SELECT * FROM clientphone where idClient = %d";
        sql = String.format(sql, idClient);
        ResultSet resultSet = jdbcUtil.executeQuery(sql);
        while(resultSet.next()) {
            ClientPhone clientPhone = new ClientPhone(resultSet.getLong("idClientPhone"),
                    resultSet.getString("phone"), resultSet.getString("type"));
            clientPhone.setIdClient(resultSet.getLong("idClient"));
            clientPhonesList.add(clientPhone);
        }
        return clientPhonesList;
    }

}

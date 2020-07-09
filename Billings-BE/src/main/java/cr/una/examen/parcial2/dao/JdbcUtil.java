/*
 *
 * Copyright (C)  2020  mike.education
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Universidad Nacional de Costa Rica, Prof: Maikol Guzman Alan.
 */

package cr.una.examen.parcial2.dao;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.*;

public class JdbcUtil {

    // Using logger for project
    final Logger logger = LogManager.getLogger(JdbcUtil.class);


    private static final String DB_DRIVER = "com.mysql.jdbc.Driver";
    private static final String DB_CONNECTION = "jdbc:mysql://localhost:3306/examen_parcial2";
    private static final String DB_USER = "examen_parcial2";
    private static final String DB_PASSWORD = "1234$una";

    private static final Connection dbConnection = getDBConnection();

    private JdbcUtil() {
    }

    private static JdbcUtil jdbcUtil;

    public static JdbcUtil instance() {
        if (jdbcUtil == null) {
            jdbcUtil = new JdbcUtil();
        }
        return jdbcUtil;
    }

    public static Connection getDBConnection() {
        try {
            String URL_connection = DB_CONNECTION + "?useTimezone=true&serverTimezone=UTC&user=" + DB_USER + "&password=" + DB_PASSWORD + "&useSSL=false&allowPublicKeyRetrieval=true";
            Class.forName(DB_DRIVER).newInstance();
            return DriverManager.getConnection(URL_connection);
        } catch (Exception e) {
            System.err.println(e.getMessage());
            System.exit(-1);
        }
        return null;
    }

    public int executeUpdate(String query) {
        try {
            Statement statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            return statement.getUpdateCount();
        } catch (SQLException ex) {
            return 0;
        }
    }

    public ResultSet executeQuery(String query) {
        try {
            Statement statement = dbConnection.createStatement();
            return statement.executeQuery(query);
        } catch (SQLException ex) {
        }
        return null;
    }

    public int executeAddAI(String query) {
        try {
            Statement statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            ResultSet resultSet = statement.getGeneratedKeys();
            if (resultSet.next())
                return resultSet.getInt(1);
            return 0;
        } catch (SQLException ex) {
            return 0;
        }
    }

}

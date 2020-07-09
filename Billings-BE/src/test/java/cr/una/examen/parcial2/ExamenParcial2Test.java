package cr.una.examen.parcial2;

import cr.una.examen.parcial2.dao.*;
import cr.una.examen.parcial2.model.*;
import cr.una.examen.parcial2.service.OrderService;
import cr.una.examen.parcial2.service.OrderServiceImpl;
import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runners.MethodSorters;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Random;

import static org.junit.Assert.*;

@FixMethodOrder(MethodSorters.NAME_ASCENDING)
public class ExamenParcial2Test {

    static Long idClientCreated = new Long(1);

    @Test
    public void testAClientDAOInsert() throws SQLException {
        Random objGenerator = new Random();
        Client client1 = new Client();
        List<ClientPhone> clientPhoneList = new ArrayList<ClientPhone>();
        List<ClientAddress> clientAddressList = new ArrayList<ClientAddress>();
        ClientPhone clientPhone1 = new ClientPhone(null, "88250"
                + objGenerator.nextInt(100), "Cellphone");
        ClientPhone clientPhone2 = new ClientPhone(null, "22233"
                + objGenerator.nextInt(100), "Home");

        ClientAddress clientAddress1 = new ClientAddress(null, "San Jose "
                + objGenerator.nextInt(100), "Domicilio");
        ClientAddress clientAddress2 = new ClientAddress(null, "Heredia "
                + objGenerator.nextInt(100), "Oficina");

        ClientDAO clientDAO = new ClientDAOImpl();

        client1.setName("Client "+objGenerator.nextInt(100));
        client1.setLastName("Sanchez");
        client1.setIva(true);
        clientPhoneList.add(clientPhone1);
        clientPhoneList.add(clientPhone2);
        clientAddressList.add(clientAddress1);
        clientAddressList.add(clientAddress2);

        client1.setClientPhones(clientPhoneList);
        client1.setClientAddresses(clientAddressList);

        clientDAO.save(client1);

        idClientCreated = client1.getIdClient();

        assertNotNull(client1.getIdClient());
        assertNotNull(client1.getClientAddresses().get(0).getIdClientAddress());
        assertNotNull(client1.getClientAddresses().get(1).getIdClientAddress());
        assertNotNull(client1.getClientPhones().get(0).getIdClientPhone());
        assertNotNull(client1.getClientPhones().get(1).getIdClientPhone());
    }

    @Test
    public void testBOrderStatusDAOInsert() throws SQLException {
        OrderStatusDAO orderStatusDAO = new OrderStatusDAOImpl();
        OrderStatus orderStatusPendiente = new OrderStatus(null, "Pendiente");
        OrderStatus orderStatusEnProceso = new OrderStatus(null, "En Proceso");
        OrderStatus orderStatusFinalizada = new OrderStatus(null, "Finalizada");

        OrderStatus orderStatusTest = orderStatusDAO.findById(new Long(1));
        if (orderStatusTest.getIdOrderStatus() == null) {
            orderStatusDAO.save(orderStatusPendiente);
            orderStatusDAO.save(orderStatusEnProceso);
            orderStatusDAO.save(orderStatusFinalizada);

            orderStatusTest = orderStatusDAO.findById(new Long(1));

        }

        assertNotNull(orderStatusTest.getIdOrderStatus());
        assertEquals(orderStatusTest.getStatus(), "Pendiente");
    }

    @Test
    public void testCOrderCategoryInsert() throws SQLException {
        OrderCategoryDAO orderCategoryDAO = new OrderCategoryDAOImpl();

        OrderCategory orderCategory1 = new OrderCategory(null, "Medicamentos"
                , new Long(2));
        OrderCategory orderCategory2 = new OrderCategory(null, "Bienes y Servicios"
                , new Long(13));
        OrderCategory orderCategory3 = new OrderCategory(null, "Canasta basica"
                , new Long(1));

        OrderCategory orderCategoryTest = orderCategoryDAO.findById(new Long(1));
        if (orderCategoryTest.getIdOrderCategory() == null) {
            orderCategoryDAO.save(orderCategory1);
            orderCategoryDAO.save(orderCategory2);
            orderCategoryDAO.save(orderCategory3);
            orderCategoryTest = orderCategoryDAO.findById(new Long(1));
        }

        assertNotNull(orderCategoryTest.getIdOrderCategory());
        assertEquals(orderCategoryTest.getCategory(), "Medicamentos");
        assertEquals(orderCategoryTest.getPercentage(), new Long(2));
    }

    @Test
    public void testDOrderDAOInsert () throws SQLException {
        OrderDAO orderDAO = new OrderDAOImpl();
        Random objGenerator = new Random();
        Date date = new Date();
        Order order = new Order();

        Client client = new Client(idClientCreated);
        OrderStatus orderStatus = new OrderStatus(new Long(1));
        OrderCategory orderCategory = new OrderCategory(new Long(1));

        order.setClient(client);
        order.setOrderStatus(orderStatus);
        order.setOrderCategory(orderCategory);
        order.setOrderNumber(1234 + objGenerator.nextInt(100));
        order.setDate(date);
        order.setCost(new Float(12345));

        orderDAO.save(order);

        assertNotNull(order.getIdOrder());
    }

    @Test
    public void testEOrderServiceFindAll() throws SQLException {
        OrderService orderService = new OrderServiceImpl();
        List<Order> orderList = orderService.findAll();

        assertTrue(orderList.size() > 0);
        assertEquals(orderList.get(0).getCostIVA(), new Float(12591.9));
    }
}

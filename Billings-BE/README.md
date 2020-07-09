# Programación 3 - Examen Parcial 2

| CODIGO: EIF206           | ESCUELA DE INFORMÁTICA       |
| ------------------------ | ---------------------------- |
| NOMBRE: PROGRAMACIÓN III | PROFESOR: Maikol Guzmán Alán |
| VALOR: 25%               | Puntaje total: 60 puntos     |

## Temas a evaluar

- Programación Orientada a Objetos
- Object Array
- Colecciones en Java
  - List
  - Map
- Patrones de diseño
  - Programación en capas (nTier)
    - Webservice (servlets)
    - Service (Business Logic)
    - DAO
    - Modelos
    - Base de Datos
- Hilos (Singleton)
- Manipulación de excepciones y archivos de log
- Normalización
- JDBC

## Material de ayuda

- [Usar el preparedStatement para obtener el id despues de insertar](https://www.codejava.net/java-se/jdbc/get-id-of-inserted-record-in-database)

## Descripción del examen

El objetivo del examen es crear un sistema que administre clientes y ordenes de compra.

Entidades del sistema:

- Clientes
  - Nombre
  - Apellido
  - IVA (si esta activado se cobra el IVA, sino no se cobra)
  - Podría tener varios tipos de teléfono
  - Podría tener varias direcciones
- Ordenes
  - Número de la orden
  - Fecha
  - Estado del la orden (Pendiente, En Proceso, Finalizada)
  - Costo sin el IVA
  - Categoría de la orden
    - Medicamentos con un 2% de IVA
    - Bienes y Servicios con un 13% de IVA
    - Canasta básica con un 1% de IVA.

El sistema ya fue analizado por un arquitecto de soluciones, el cual definió las pruebas de unidad para empezar el sistema, así como las interfaces pricipales para ser implementadas y utilizadas.

## Pruebas de Unidad

```java
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

```

## Resultado del webservice esperado

El webservice debe mostrar exactamente la siguiente estructura sin embargo **probablemente los valores no coincidan** ya que son aleatorios.

```json
[
    {
        "idOrder": 1,
        "client": {
            "idClient": 1,
            "name": "Client 47",
            "lastName": "Sanchez",
            "iva": true,
            "clientAddresses": [
                {
                    "idClientAddress": 1,
                    "idClient": 1,
                    "address": "San Jose 70",
                    "type": "Domicilio"
                },
                {
                    "idClientAddress": 2,
                    "idClient": 1,
                    "address": "Heredia 15",
                    "type": "Oficina"
                }
            ],
            "clientPhones": [
                {
                    "idClientPhone": 1,
                    "idClient": 1,
                    "phone": "8825028",
                    "type": "Cellphone"
                },
                {
                    "idClientPhone": 2,
                    "idClient": 1,
                    "phone": "2223360",
                    "type": "Home"
                }
            ]
        },
        "orderStatus": {
            "idOrderStatus": 1,
            "status": "Pendiente"
        },
        "orderCategory": {
            "idOrderCategory": 1,
            "category": "Medicamentos",
            "percentage": 2
        },
        "orderNumber": 1327,
        "date": "2020-06-21",
        "cost": 12345.0,
        "costIVA": 12591.9
    }
]
```

## Evaluación

| Detalle                                                      | Puntaje |
| ------------------------------------------------------------ | ------- |
| [ **BD** ] Desarrollar la base de datos y subirla al repositorio | 10      |
| [ **DAO** ] Implementar y desarrollar los DAO's necesarios con sus respectivos métodos de acceso por JDBC | 20      |
| [ **SERVICE** ] Implementar y desarrollar el service requerido con la lógica de negocio necesaria para calcular el costo más IVA | 10      |
| [ **WEBSERVICE** ] Desarrolar el webservice requerido        | 10      |
| [ **HILOS** ] Implementar el patrón de diseño singletón para manejar las conexiones JDBC | 5       |
| [ **LOG** ] Utilizar logger en donde sea necesario           | 5       |
| [ **TESTING** ] Las pruebas de verificación deben de correr para validar el examen | -----   |

## Reglas

1. Subir al GitHub del proyecto todos los archivos necesarios para ejecutar las pruebas unitarias.
2. Si se encuentra plagio o copias entre grupos se anula el examen de acuerdo al reglamento de la universidad.
3. El profesor únicamente revisa lo que esta en el repositório hasta la fecha de entrega. Cualquier entrega posterior a la fecha acordada se declara examen perdido con 0.
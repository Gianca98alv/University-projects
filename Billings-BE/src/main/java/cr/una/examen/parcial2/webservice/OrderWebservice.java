package cr.una.examen.parcial2.webservice;

import com.fasterxml.jackson.databind.ObjectMapper;
import cr.una.examen.parcial2.model.Order;
import cr.una.examen.parcial2.service.OrderService;
import cr.una.examen.parcial2.service.OrderServiceImpl;
import lombok.SneakyThrows;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

@WebServlet(name = "OrderWebservice", urlPatterns = {"orders"}, loadOnStartup = 1)
public class OrderWebservice extends HttpServlet {

    private ObjectMapper mapper = new ObjectMapper();
    private OrderService orderService = new OrderServiceImpl();

    /**
     * Retrieves All the Orders
     * URL/orders
     * URL/orders?id=1
     *
     * @return ListOr of orders
     */
    @SneakyThrows
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws IOException {

        // Using logger for project
        final Logger logger = LogManager.getLogger(OrderWebservice.class);


        String json = null;

        List<Order> ordersList = null;
        try {
            ordersList = orderService.findAll();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        json = mapper.writeValueAsString(ordersList);


        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        response.getWriter().print(json);

    }

}

package cr.una.examen.parcial2.model;

import java.util.Date;

/**
 *
 * @author  Giancarlo Alvarado
 */
public class Order {

    private Long idOrder;
    private Client client;
    private OrderStatus orderStatus;
    private OrderCategory orderCategory;
    private Integer orderNumber;
    private Date date;
    private Float cost;
    private Float costIVA;

    /**
     *
     */
    public Order() {
    }

    /**
     *
     * @param idOrder
     */
    public Order(Long idOrder) {
        this.idOrder = idOrder;
    }

    /**
     *
     * @param idOrder
     * @param client
     * @param orderStatus
     * @param orderCategory
     * @param orderNumber
     * @param date
     * @param cost
     * @param costIVA
     */
    public Order(Long idOrder, Client client, OrderStatus orderStatus, OrderCategory orderCategory, Integer orderNumber, Date date, Float cost, Float costIVA) {
        this.idOrder = idOrder;
        this.client = client;
        this.orderStatus = orderStatus;
        this.orderCategory = orderCategory;
        this.orderNumber = orderNumber;
        this.date = date;
        this.cost = cost;
        this.costIVA = costIVA;
    }

    /**
     *
     * @return
     */
    public Long getIdOrder() {
        return idOrder;
    }

    /**
     *
     * @param idOrder
     */
    public void setIdOrder(Long idOrder) {
        this.idOrder = idOrder;
    }

    /**
     *
     * @return
     */
    public Client getClient() {
        return client;
    }

    /**
     *
     * @param client
     */
    public void setClient(Client client) {
        this.client = client;
    }

    /**
     *
     * @return
     */
    public OrderStatus getOrderStatus() {
        return orderStatus;
    }

    /**
     *
     * @param orderStatus
     */
    public void setOrderStatus(OrderStatus orderStatus) {
        this.orderStatus = orderStatus;
    }

    /**
     *
     * @return
     */
    public OrderCategory getOrderCategory() {
        return orderCategory;
    }

    /**
     *
     * @param orderCategory
     */
    public void setOrderCategory(OrderCategory orderCategory) {
        this.orderCategory = orderCategory;
    }

    /**
     *
     * @return
     */
    public Integer getOrderNumber() {
        return orderNumber;
    }

    /**
     *
     * @param orderNumber
     */
    public void setOrderNumber(Integer orderNumber) {
        this.orderNumber = orderNumber;
    }

    /**
     *
     * @return
     */
    public Date getDate() {
        return date;
    }

    /**
     *
     * @param date
     */
    public void setDate(Date date) {
        this.date = date;
    }

    /**
     *
     * @return
     */
    public Float getCost() {
        return cost;
    }

    /**
     *
     * @param cost
     */
    public void setCost(Float cost) {
        this.cost = cost;
    }

    /**
     *
     * @return
     */
    public Float getCostIVA() {
        return costIVA;
    }

    /**
     *
     * @param costIVA
     */
    public void setCostIVA(Float costIVA) {
        this.costIVA = costIVA;
    }

    @Override
    public String toString() {
        return "Order{" + "idOrder=" + idOrder
                + ", client=" + client
                + ", orderStatus=" + orderStatus
                + ", orderCategory=" + orderCategory
                + ", orderNumber=" + orderNumber
                + ", date=" + date
                + ", cost=" + cost
                + ", costIVA=" + costIVA + '}';
    }

}

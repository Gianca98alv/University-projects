package cr.una.examen.parcial2.model;
/**
 *
 * @author Giancarlo Alvarado
 */
public class OrderStatus {

    private Long idOrderStatus;
    private String status;

    /**
     *
     */
    public OrderStatus() {}
    
    /**
     *
     * @param idOrderStatus
     * @param status
     */
    public OrderStatus(Long idOrderStatus, String status) {
        this.idOrderStatus = idOrderStatus;
        this.status = status;
    }

    public OrderStatus(Long idOrderStatus) {
        this.idOrderStatus = idOrderStatus;
    }

    /**
     *
     * @return
     */
    public Long getIdOrderStatus() {
        return idOrderStatus;
    }

    /**
     *
     * @param idOrderStatus
     */
    public void setIdOrderStatus(Long idOrderStatus) {
        this.idOrderStatus = idOrderStatus;
    }

    /**
     *
     * @return
     */
    public String getStatus() {
        return status;
    }

    /**
     *
     * @param status
     */
    public void setStatus(String status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "OrderStatus{" + "idOrderStatus=" + idOrderStatus
                + ", status=" + status + '}';
    }

}

package cr.una.examen.parcial2.model;
/**
 *
 * @author Giancarlo Alvarado
 */
public class OrderCategory {

    private Long idOrderCategory;
    private String category;
    private Long percentage;

    /**
     *
     */
    public OrderCategory() {}

    /**
     *
     * @param idOrderCategory
     * @param category
     * @param percentage
     */
    public OrderCategory(Long idOrderCategory, String category, Long percentage) {
        this.idOrderCategory = idOrderCategory;
        this.category = category;
        this.percentage = percentage;
    }

    public OrderCategory(Long idOrderCategory) {
        this.idOrderCategory = idOrderCategory;
    }

    /**
     *
     * @return
     */
    public Long getIdOrderCategory() {
        return idOrderCategory;
    }

    /**
     *
     * @param idOrderCategory
     */
    public void setIdOrderCategory(Long idOrderCategory) {
        this.idOrderCategory = idOrderCategory;
    }

    /**
     *
     * @return
     */
    public String getCategory() {
        return category;
    }

    /**
     *
     * @param category
     */
    public void setCategory(String category) {
        this.category = category;
    }

    /**
     *
     * @return
     */
    public Long getPercentage() {
        return percentage;
    }

    /**
     *
     * @param percentage
     */
    public void setPercentage(Long percentage) {
        this.percentage = percentage;
    }

    @Override
    public String toString() {
        return "OrderCategory{" + "idOrderCategory=" + idOrderCategory
                + ", category=" + category
                + ", percentage=" + percentage + '}';
    }


}

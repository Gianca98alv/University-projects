package cr.una.examen.parcial2.model;
/**
 *
 * @author Giancarlo Alvarado
 */
public class ClientPhone {

    private Long idClientPhone;
    private Long idClient;
    private String phone;
    private String type;

    /**
     *
     */
    public ClientPhone() {}

    /**
     *
     * @param idClientPhone
     * @param phone
     * @param type
     */
    public ClientPhone(Long idClientPhone, String phone, String type) {
        this.idClientPhone = idClientPhone;
        this.phone = phone;
        this.type = type;
    }

    /**
     *
     * @return
     */
    public Long getIdClientPhone() {
        return idClientPhone;
    }

    /**
     *
     * @param idClientPhone
     */
    public void setIdClientPhone(Long idClientPhone) {
        this.idClientPhone = idClientPhone;
    }

    /**
     *
     * @return
     */
    public Long getIdClient() {
        return idClient;
    }

    /**
     *
     * @param idClient
     */
    public void setIdClient(Long idClient) {
        this.idClient = idClient;
    }

    /**
     *
     * @return
     */
    public String getPhone() {
        return phone;
    }

    /**
     *
     * @param phone
     */
    public void setPhone(String phone) {
        this.phone = phone;
    }

    /**
     *
     * @return
     */
    public String getType() {
        return type;
    }

    /**
     *
     * @param type
     */
    public void setType(String type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return "ClientPhone{"
                + "idClientPhone=" + idClientPhone
                + ", idClient=" + idClient
                + ", phone=" + phone
                + ", type=" + type + '}';
    }

}

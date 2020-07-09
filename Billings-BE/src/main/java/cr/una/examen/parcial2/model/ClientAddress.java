package cr.una.examen.parcial2.model;
/**
 *
 * @author Giancarlo Alvarado
 */
public class ClientAddress {

    private Long idClientAddress;
    private Long idClient;
    private String address;
    private String type;

    /**
     *
     */
    public ClientAddress() {

    }

    /**
     *
     * @param idClientAddress
     * @param address
     * @param type
     */
    public ClientAddress(Long idClientAddress, String address, String type) {
        this.idClientAddress = idClientAddress;
        this.address = address;
        this.type = type;
    }

    /**
     *
     * @return
     */
    public Long getIdClientAddress() {
        return idClientAddress;
    }

    /**
     *
     * @param idClientAddress
     */
    public void setIdClientAddress(Long idClientAddress) {
        this.idClientAddress = idClientAddress;
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
    public String getAddress() {
        return address;
    }

    /**
     *
     * @param address
     */
    public void setAddress(String address) {
        this.address = address;
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
        return "ClientAddress{"
                + "idClientAddress=" + idClientAddress
                + ", idClient=" + idClient
                + ", address=" + address
                + ", type=" + type + '}';
    }

}

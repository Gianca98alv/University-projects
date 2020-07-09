package cr.una.examen.parcial2.model;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Giancarlo Alvarado
 */
public class Client {

    private Long idClient;
    private String name;
    private String lastName;
    private Boolean iva;
    private List<ClientAddress> clientAddresses = new ArrayList<>();
    private List<ClientPhone> clientPhones = new ArrayList<>();

    /**
     *
     */
    public Client() {}

    /**
     * @param idClient
     */
    public Client(Long idClient) {
        this.idClient = idClient;
    }

    /**
     * @param idClient
     * @param name
     * @param lastName
     * @param iva
     */
    public Client(Long idClient, String name, String lastName, Boolean iva) {
        this.idClient = idClient;
        this.name = name;
        this.lastName = lastName;
        this.iva = iva;
    }

    /**
     * @return
     */
    public Long getIdClient() {
        return idClient;
    }

    /**
     * @param idClient
     */
    public void setIdClient(Long idClient) {
        this.idClient = idClient;
    }

    /**
     * @return
     */
    public String getName() {
        return name;
    }

    /**
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return
     */
    public String getLastName() {
        return lastName;
    }


    /**
     * @param lastName
     */
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    /**
     * @return
     */
    public Boolean getIva() {
        return iva;
    }

    /**
     * @param iva
     */
    public void setIva(Boolean iva) {
        this.iva = iva;
    }

    /**
     * @return
     */
    public List<ClientAddress> getClientAddresses() {
        return clientAddresses;
    }

    /**
     * @param clientAddresses
     */
    public void setClientAddresses(List<ClientAddress> clientAddresses) {
        this.clientAddresses = clientAddresses;
    }

    /**
     * @return
     */
    public List<ClientPhone> getClientPhones() {
        return clientPhones;
    }

    /**
     * @param clientPhones
     */
    public void setClientPhones(List<ClientPhone> clientPhones) {
        this.clientPhones = clientPhones;
    }

    /**
     * @return
     */
    @Override
    public String toString() {
        return "Client{"
                + "idClient=" + idClient
                + ", name=" + name
                + ", lastName=" + lastName
                + ", iva=" + iva
                + ", clientAddresses=" + clientAddresses
                + ", clientPhones=" + clientPhones + '}';
    }

}

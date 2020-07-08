package cr.una.proyecto1.model;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Patient {

    final Logger logger = LogManager.getLogger(Patient.class);

    //Atributos
    private String name;
    private String id;
    private int cellnum;
    private String address;
    private String birthdate;
    private String diseases;
    private String observations;

    //Constructores
    public Patient() {}
    public Patient(String name, String id, int cellnum, String address, String birthdate, String diseases, String observations) {
        this.name = name;
        this.id = id;
        this.cellnum = cellnum;
        this.address = address;
        this.birthdate = birthdate;
        this.diseases = diseases;
        this.observations = observations;
    }

    //Gets
    public String getName() { return name; }
    public String getId() { return this.id; }
    public int getCellnum() { return cellnum; }
    public String getAddress() { return address; }
    public String getBirthdate() { return birthdate; }
    public String getDiseases() { return diseases; }
    public String getObservations() { return observations; }

    //Sets
    public void setName(String name) { this.name = name; }
    public void setCellnum(int cellnum) { this.cellnum = cellnum; }
    public void setAddress(String address) {this.address = address; }
    public void setBirthdate(String birthdate) { this.birthdate = birthdate; }
    public void setDiseases(String diseases) { this.diseases = diseases; }
    public void setObservations(String observations) { this.observations = observations; }

    //ToString
    @Override
    public String toString() {
        return "Patient{" + "name=" + name + "ID" + id + ", cellphone number=" + cellnum + ", address=" + address + ", birthdate" + birthdate + ", diseases" + diseases + " and observations" + observations +'}';
    }

}

package cr.una.proyecto1.model;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class ConsultingRoom {

    final Logger logger = LogManager.getLogger(ConsultingRoom.class);

    //Atributos
    private String name;
    private String telephone;
    private String day;
    private String hour;

    //Constructores
    public ConsultingRoom() {}
    public ConsultingRoom(String name, String telephone, String day, String hour) {
        this.name = name;
        this.telephone = telephone;
        this.day = day;
        this.hour = hour;
    }

    //Gets
    public String getName() { return name; }
    public String getTelephone() { return telephone; }
    public String getDay() { return day; }
    public String getHour() { return hour; }

    //Sets
    public void setName(String name) { this.name = name; }
    public void setTelephone(String telephone) { this.telephone = telephone; }
    public void setDay(String day) { this.day = day; }
    public void setHour(String hour) { this.hour = hour; }

}
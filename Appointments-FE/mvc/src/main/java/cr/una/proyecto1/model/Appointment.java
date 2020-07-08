package cr.una.proyecto1.model;

//Para asignar fecha de cita
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Appointment {

    final Logger logger = LogManager.getLogger(Appointment.class);

    //Conteo citas
    private static int CONT_ID = 0;
    private static final String FORMAT_TOSTRING = "ID: %d%nPACIENTE: %s%nCONSULTORIO: %s%nFECHA: %s%nCONFIRMADO: %s%n";
    DateTimeFormatter FORMATTER = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm");

    //Atributos
    private String patient;
    private int id;
    private String consultingRoom;
    private LocalDateTime date;
    private boolean confirm;

    public String format_confirm() {
        return confirm ? "SI" : "NO";
    }

    public String format_date() {
        return FORMATTER.format(date);
    }

    //Constructores
    public Appointment() {}
    public Appointment(String patient, String consultingRoom, LocalDateTime date) {
        this.patient = patient;
        this.id = ++CONT_ID;
        this.consultingRoom = consultingRoom;
        this.date = date;
        this.confirm = false;
    }

    //Sets
    public void setPatient(String patient) { this.patient = patient; }
    public void setConsultingRoom(String consultingRoom) { this.consultingRoom = consultingRoom; }
    public void setDate(LocalDateTime date) { this.date = date; }
    public void setConfirm(boolean confirm) { this.confirm = confirm; }
    public void setConfirm() { this.confirm = true; } //setConfirm sobrecargado al recibir sin parametros

    //Gets
    public String getPatient() {
        return patient;
    }
    public int getId() { return id; }
    public String getConsultingRoom() {
        return consultingRoom;
    }
    public LocalDateTime getDate() { return date; }
    public boolean getConfirm() { return confirm; }

    @Override
    public String toString() {
        return String.format(FORMAT_TOSTRING, id, patient, consultingRoom, format_date(), format_confirm());
    }
}
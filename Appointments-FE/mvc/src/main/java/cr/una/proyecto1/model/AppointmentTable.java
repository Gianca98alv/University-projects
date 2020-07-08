package cr.una.proyecto1.model;

import javax.swing.table.AbstractTableModel;
import java.text.SimpleDateFormat;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class AppointmentTable extends AbstractTableModel {

    final Logger logger = LogManager.getLogger(AppointmentTable.class);

    //Atributos
    private ArrayList<Appointment> appointmentArrayList;

    //Constructor
    public AppointmentTable(ArrayList<Appointment> appointmentArrayList) {
        this.appointmentArrayList = appointmentArrayList;
    }

    //Get y set
    public ArrayList<Appointment> getAppointmentArrayList() { return appointmentArrayList; }
    public void setAppointmentArrayList(ArrayList<Appointment> appointmentArrayList) {
        this.appointmentArrayList = appointmentArrayList;
    }

    //Columnas
    public String getColumnName(int column) {
        String name = "???";
        switch (column) {
            case 0:
                name = "ID Cita";
                break;
            case 1:
                name = "ID Paciente";
                break;
            case 2:
                name = "Consultorio";
                break;
            case 3:
                name = "Fecha";
                break;
            case 4:
                name = "Confirmada";
                break;
        }
        return name;
    }

    //Metodos abstractos
    @Override
    public int getRowCount() {
        return appointmentArrayList == null ? 0 : appointmentArrayList.size();
    }

    @Override
    public int getColumnCount() {
        return 5;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {

        Appointment ap = appointmentArrayList.get(rowIndex);
        Object obj = null;

        switch(columnIndex) {
            case 0: obj = ap.getId();
                break;
            case 1: obj = ap.getPatient();
                break;
            case 2: obj = ap.getConsultingRoom();
                break;
            case 3: obj = ap.format_date();
                break;
            case 4: obj = ap.format_confirm();
                break;
        }

        return obj;
    }
}

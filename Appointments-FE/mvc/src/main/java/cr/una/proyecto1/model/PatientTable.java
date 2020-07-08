package cr.una.proyecto1.model;

import javax.swing.table.AbstractTableModel;
import java.util.ArrayList;

import cr.una.proyecto1.controller.PatientController;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class PatientTable extends AbstractTableModel {

    final Logger logger = LogManager.getLogger(PatientController.class);

    //Atributos
    private ArrayList<Patient> patientArrayList;

    //Constructor
    public PatientTable(ArrayList<Patient> patientArrayList) {
        this.patientArrayList = patientArrayList;
    }

    //Get y set
    public ArrayList<Patient> getPatientArrayList() { return patientArrayList; }
    public void setPatientArrayList(ArrayList<Patient> patientArrayList) {
        this.patientArrayList = patientArrayList;
    }

    //Columnas
    public String getColumnName(int column) {
        String name = "???";
        switch (column) {
            case 0:
                name = "Nombre";
                break;
            case 1:
                name = "Identificacion";
                break;
            case 2:
                name = "Celular";
                break;
            case 3:
                name = "Direccion";
                break;
            case 4:
                name = "Fecha de nacimiento";
                break;
            case 5:
                name = "Enfermedades";
                break;
            case 6:
                name = "Observaciones";
                break;
        }
        return name;
    }

    //Metodos abstractos
    @Override
    public int getRowCount() {
        return patientArrayList == null ? 0 : patientArrayList.size();
    }

    @Override
    public int getColumnCount() {
        return 7;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {

        Patient pa = patientArrayList.get(rowIndex);
        Object obj = null;

        switch(columnIndex) {
            case 0: obj = pa.getName();
            break;
            case 1: obj = pa.getId();
            break;
            case 2: obj = pa.getCellnum();
            break;
            case 3: obj = pa.getAddress();
            break;
            case 4: obj = pa.getBirthdate();
            break;
            case 5: obj = pa.getDiseases();
            break;
            case 6: obj = pa.getObservations();
            break;
        }

        return obj;
    }

}

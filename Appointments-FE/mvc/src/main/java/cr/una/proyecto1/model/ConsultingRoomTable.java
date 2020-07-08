package cr.una.proyecto1.model;

import javax.swing.table.AbstractTableModel;
import java.util.ArrayList;

import cr.una.proyecto1.controller.ConsultingRoomController;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class ConsultingRoomTable extends AbstractTableModel  {

    final Logger logger = LogManager.getLogger(ConsultingRoomController.class);

    //Atributos
    private ArrayList<ConsultingRoom> consultingRoomArrayList;

    //Constructor
    public ConsultingRoomTable(ArrayList<ConsultingRoom> consultingRoomArrayList) {
        this.consultingRoomArrayList = consultingRoomArrayList;
    }

    //Get y set
    public ArrayList<ConsultingRoom> getConsultingRoomArrayList() { return consultingRoomArrayList; }
    public void setConsultingRoomArrayList(ArrayList<ConsultingRoom> consultingRoomArrayList) {
        this.consultingRoomArrayList = consultingRoomArrayList;
    }

    //Columnas
    public String getColumnName(int column) {
        String name = "???";
        switch (column) {
            case 0:
                name = "Nombre";
                break;
            case 1:
                name = "Telefono";
                break;
            case 2:
                name = "Dia";
                break;
            case 3:
                name = "Hora";
                break;
        }
        return name;
    }

    //Métodos abstractos
    @Override
    public int getRowCount() {
        return consultingRoomArrayList.size();
    }

    @Override
    public int getColumnCount() {
        return 4;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        ConsultingRoom cr = consultingRoomArrayList.get(rowIndex);
        Object obj = null;

        switch(columnIndex) {
            case 0: obj = cr.getName();
                break;
            case 1: obj = cr.getTelephone();
                break;
            case 2: obj = cr.getDay();
                break;
            case 3: obj = cr.getHour();
                break;
        }

        return obj;
    }
}

package cr.una.proyecto1;

import cr.una.proyecto1.controller.PatientController;
import cr.una.proyecto1.controller.ConsultingRoomController;
import cr.una.proyecto1.controller.AppointmentController;
import cr.una.proyecto1.controller.MainController;

import cr.una.proyecto1.model.Patient;
import cr.una.proyecto1.model.ConsultingRoom;
import cr.una.proyecto1.service.Service;

import cr.una.proyecto1.view.PatientView;
import cr.una.proyecto1.view.ConsultingRoomView;
import cr.una.proyecto1.view.AppointmentView;
import cr.una.proyecto1.view.MainView;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Main {

    final static Logger logger = LogManager.getLogger(Main.class);

    public static PatientController patientController;
    public static ConsultingRoomController consultingRoomController;
    public static AppointmentController appointmentController;

    public static void main(String[] args) {

        Service service = new Service();
        service.getPatients().add(new Patient("Abelardo Mora Solano", "115660987", 88250820, "San Jose", "29/07/1977", "NR", "NR"));
        service.getConsultingRooms().add(new ConsultingRoom("Hospital CYM", "24407697", "Lunes - Martes", "7:00 - 18:00"));
        service.getConsultingRooms().add(new ConsultingRoom("Centro Medico del Este", "27968901", "Jueves - Viernes", "9:00 - 15:00"));

        ConsultingRoomView consultingRoom = new ConsultingRoomView();
        consultingRoomController = new ConsultingRoomController(service, consultingRoom);
        //consultingRoom.setVisible(true);
        PatientView patient = new PatientView();
        patientController = new PatientController(service, patient);
        //patient.setVisible(true);
        AppointmentView appointment = new AppointmentView();
        appointmentController = new AppointmentController(service, appointment);
        //appointment.setVisible(true);

        MainView test= new MainView();
        AppointmentView apView = new AppointmentView();
        PatientView patView = new PatientView();
        ConsultingRoomView crView = new ConsultingRoomView();
        MainController mController = new MainController(test, apView, patView, crView);
        test.setVisible(true);
    }
}

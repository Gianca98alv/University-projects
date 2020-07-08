package cr.una.proyecto1.controller;

import cr.una.proyecto1.Main;
import cr.una.proyecto1.view.PatientView;
import cr.una.proyecto1.view.ConsultingRoomView;
import cr.una.proyecto1.view.AppointmentView;
import cr.una.proyecto1.view.MainView;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class MainController implements ActionListener {

    final Logger logger = LogManager.getLogger(MainController.class);

    private MainView mView;
    private AppointmentView apView;
    private PatientView patView;
    private ConsultingRoomView crView;

    public MainController(MainView mView, AppointmentView apView, PatientView patView, ConsultingRoomView crView){
        logger.debug("Main Controller");

        this.mView = mView;
        this.apView = apView;
        this.patView = patView;
        this.crView = crView;
        this.mView.patient.addActionListener(this::patientActionPerformed);
        this.mView.consultingRoom.addActionListener(this::consultingRoomActionPerformed);
        this.mView.appointment.addActionListener(this::appointmentActionPerformed);
        this.mView.exitButton.addActionListener(this::exitActionPerformed);
    }

    public void patientActionPerformed(ActionEvent actionEvent){
        Main.patientController.showPatient();
    }

    public void consultingRoomActionPerformed(ActionEvent actionEvent){
        Main.consultingRoomController.showConsultingRoom();
    }

    public void appointmentActionPerformed(ActionEvent actionEvent){
        Main.appointmentController.showAppointment();
    }

    public void exitActionPerformed(ActionEvent actionEvent){
        System.exit(0);
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {}
}


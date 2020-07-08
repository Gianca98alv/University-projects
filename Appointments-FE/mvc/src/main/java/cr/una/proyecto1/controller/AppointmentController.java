package cr.una.proyecto1.controller;

import cr.una.proyecto1.Main;
import cr.una.proyecto1.model.Appointment;
import cr.una.proyecto1.model.ConsultingRoom;
import cr.una.proyecto1.service.Service;
import cr.una.proyecto1.view.AppointmentView;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalDateTime;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class AppointmentController implements ActionListener {

    final Logger logger = LogManager.getLogger(AppointmentController.class);

    //Atributos
    private Service service;
    private AppointmentView apView;

    //Constructor
    public AppointmentController(Service service, AppointmentView apView){
        logger.debug("Appointment Controller");

        this.service = service;
        this.apView = apView;
        apView.setController(this);
        apView.setService(service);
    }

    //Wrappers
    public void newAppointment(String idPatinet, String crName, LocalDateTime date) {
        Appointment appointment = new Appointment(idPatinet, crName, date);
        service.newAppointment(appointment);
    }

    public void getAppointment() {
        service.updateTableAppointments(service.getAppointments());
    }

    public void updateAppointment(String name, String telephone, String day, String hour) {
        ConsultingRoom consultingRoom = new ConsultingRoom(name, telephone, day, hour);
        service.updateConsultingRoom(consultingRoom);
    }

    public Appointment searchAppointment (int n) {
        return service.searchAppointment(n);
    }

    public boolean deleteAppointment(int n) {
        return service.deleteAppointment(n);
    }

    public boolean searchPatient(String id) { return service.findIdPatient(id); }

    @Override
    public void actionPerformed(ActionEvent e) {

    }

    //Administración de la  ventana
    public void showAppointment () {
        apView.setVisible(true);
    }

    public void hideAppointment () {
        apView.setVisible(false);
    }

    public boolean findIdAppointment(int n){ return service.findIdAppointment(n); }

    public String getConsultingRoom(String day) { return service.getConsultingRoom(day); }

    public boolean validateDates(LocalDateTime date) {
        return service.validateDates(date);
    }

    public boolean confirmate(int id) {
        return service.confirmate(id);
    }

    public String showDataAppoteintment(int id) {
        return service.showDataAppoteintment(id);
    }

    public void back() {
        hideAppointment();
        Main.appointmentController.showAppointment();
    }

}

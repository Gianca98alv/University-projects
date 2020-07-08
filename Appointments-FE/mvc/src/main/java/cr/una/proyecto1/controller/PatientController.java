package cr.una.proyecto1.controller;
import cr.una.proyecto1.Main;
import cr.una.proyecto1.model.Patient;
import cr.una.proyecto1.service.Service;
import cr.una.proyecto1.view.PatientView;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class PatientController {

    final Logger logger = LogManager.getLogger(PatientController.class);

    //Atributos
    private Service service;
    private PatientView patView;

    //Constructor
    public PatientController (Service service, PatientView patView){
        logger.debug("Patient Controller");

        this.service = service;
        this.patView = patView;
        patView.setController(this);
        patView.setService(service);
    }

    //Wrappers
    public void newPatient(String name, String id, int cellnum, String address, String birthdate, String diseases, String observations){
        Patient patient = new Patient(name, id, cellnum, address, birthdate, diseases, observations);
        service.newPatient(patient);
    };

    public void getPatient() {
        service.updateTablePatients(service.getPatients());
    }

    public void updatePatient(String name, String id, int cellnum, String address, String birthdate, String diseases, String observations) {
        Patient patient = new Patient(name, id, cellnum, address, birthdate, diseases, observations);
        service.updatePatient(patient);
    }

    public Patient searchPatient(String id) {
        return service.searchPatient(id);
    }

    public boolean deletePatient(String id) {
        return service.deletePatient(id);
    }

    //Administración de la  ventana
    public void showPatient() {
        patView.setVisible(true);
    }

    public void hidePatient() {
        patView.setVisible(false);
    }

    public boolean findIdPatient(String id){
        return service.findIdPatient(id);
    }

    public void back() {
        hidePatient();
        Main.patientController.showPatient();

    }

}

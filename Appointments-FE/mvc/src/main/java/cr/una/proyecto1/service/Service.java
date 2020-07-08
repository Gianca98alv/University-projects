package cr.una.proyecto1.service;

import cr.una.proyecto1.model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;

public class Service extends Observable {
    final Logger logger = LogManager.getLogger(Service.class);

    //Atributos
    private ArrayList<Patient> patients;
    private ArrayList<ConsultingRoom> consultingRooms;
    private ArrayList<Appointment> appointments;
    private PatientTable patientTable;
    private ConsultingRoomTable consultingRoomTable;
    private AppointmentTable appointmentTable;

    private void update() {
        this.setChanged();
        this.notifyObservers();
    }

    //Constructor
    public Service() {
        logger.debug("Service");

        patients = new ArrayList<>();
        consultingRooms = new ArrayList<>();
        appointments = new ArrayList<>();
        patientTable = new PatientTable(patients);
    }

    //Añade y/o crea pacientes, consultorios y citas
    public void newPatient(Patient patient) {
        patients.add(patient);
        update();
    }

    public void newConsultingRoom(ConsultingRoom consultingRoom) {
        consultingRooms.add(consultingRoom);
        update();
    }

    public void newAppointment(Appointment appointment) {
        appointments.add(appointment);
        update();
    }

    //Listar
    public ArrayList<Patient> getPatients() {
        return patients;
    }

    public ArrayList<Appointment> getAppointments() {
        return appointments;
    }

    public ArrayList<ConsultingRoom> getConsultingRooms() {
        return consultingRooms;
    }

    //Modificaciónes
    public void updatePatient(Patient patient) {
        logger.debug("Cambios de datos en el paciente");
        for (Patient pa : patients) {
            if (pa.getId().equals(patient.getId())) {
                pa.setName(patient.getName());
                pa.setCellnum(patient.getCellnum());
                pa.setAddress(patient.getAddress());
                pa.setBirthdate(patient.getBirthdate());
                pa.setDiseases(patient.getDiseases());
                pa.setObservations(patient.getObservations());
                break;
            }
        }
    }

    public void updateConsultingRoom(ConsultingRoom consultingRoom) {
        logger.debug("Cambios en el consultorio");
        for (ConsultingRoom cr : consultingRooms) {
            if (cr.getName().equals(consultingRoom.getName())) {
                cr.setTelephone(consultingRoom.getTelephone());
                cr.setDay(consultingRoom.getDay());
                cr.setHour(consultingRoom.getHour());
            }
        }
    }

    public void updateAppointment(Appointment appointment) {
        logger.debug("Cambios en la cita");
        for (Appointment ap : appointments) {
            if (ap.getId() == appointment.getId()) {
                ap.setPatient(appointment.getPatient());
                ap.setConsultingRoom(appointment.getConsultingRoom());
                ap.setDate(appointment.getDate());
                ap.setConfirm(appointment.getConfirm());
            }
        }
    }

    public void updateTablePatients(ArrayList<Patient> aux) {
        this.patientTable = new PatientTable(aux);
        update();
    }

    public void updateTableConsultingRooms(ArrayList<ConsultingRoom> aux) {
        this.consultingRoomTable = new ConsultingRoomTable(aux);
        update();
    }

    public void updateTableAppointments(ArrayList<Appointment> aux) {
        this.appointmentTable = new AppointmentTable(aux);
        update();
    }

    //Consultas
    public Patient searchPatient(String id) {
        logger.debug("Buscando Pacientes");
        Patient n = null;
        for (Patient pa : patients) {
            if (pa.getId().equals(id)) {
                n = pa;
            }
        }
        return n;
    }

    public ConsultingRoom searchConsulRoom(String name) {
        logger.debug("Buscando Consultorios");
        ConsultingRoom n = null;
        for (ConsultingRoom cr : consultingRooms) {
            if (cr.getName().equals(name)) {
                n = cr;
            }
        }
        return n;
    }

    public Appointment searchAppointment(int id) {
        logger.debug("Buscando cita");

        Appointment n = null;
        for (Appointment ap : appointments) {
            if (ap.getId() == id) {
                n = ap;
            }
        }
        return n;
    }

    //Eliminaciones
    public boolean deletePatient(String id) {
        logger.debug("Borrando Pacientes");
        for (Patient pa : patients) {
            if (pa.getId().equals(id)) {
                patients.remove(pa);
                return true;
            }
        }
        return false;
    }

    public boolean deleteConsultRoom(String name) {
        logger.debug("Borrando consultorio");

        for (ConsultingRoom cr : consultingRooms) {
            if (cr.getName().equals(name)) {
                consultingRooms.remove(cr);
                return true;
            }
        }
        return false;
    }

    public boolean deleteAppointment(int id) {
        logger.debug("Borrando Cita");

        for (Appointment ap : appointments) {
            if (ap.getId() == id) {
                appointments.remove(ap);
                return true;
            }
        }
        return false;
    }

    //Retorna las tablas
    public PatientTable getPatientTable() {
        return patientTable;
    }
    public ConsultingRoomTable getConsultingRoomTable() {
        return consultingRoomTable;
    }
    public AppointmentTable getAppointmentTable() {return appointmentTable; }

    //Uso correcto patrón Observer
    @Override
    public synchronized void addObserver(Observer o) {
        super.addObserver(o);
    }

    //Método de validación citas
    public void appointmentConfirm(int id) {
        logger.debug("Confirmando Cita");
        for (Appointment ap : appointments) {
            if (ap.getId() == id) {
                ap.setConfirm();
                break;
            }
        }
    }

    //Metodos busqueda
    public boolean findIdPatient(String id) {
        logger.debug("Buscando Paciente con el id ["+id+"]");
        for (Patient obj : patients) {
            if (obj.getId().equals(id)) {
                return true;
            }
        }
        return false;
    }

    public boolean findNameConsultingRoom(String n) {
        logger.debug("Buscando el Consultorio ["+n+"]");
        for (ConsultingRoom obj : consultingRooms) {
            if (obj.getName().equals(n)) {
                return true;
            }
        }
        return false;
    }

    public boolean findIdAppointment(int id) {
        logger.debug("Buscando la cita por el id ["+id+"]");
        for (Appointment obj : appointments) {
            if (obj.getId() == id) {
                return true;
            }
        }
        return false;
    }

    public String getConsultingRoom(String day) {
        if(day.equals("MONDAY") || day.equals("TUESDAY")) {
            return "Hospital CYM";
        }
        if (day.equals("THURSDAY") || day.equals("FRIDAY")) {
            return "Centro Medico del Este";
        }
        return "";
    }

    public boolean validateDates(LocalDateTime date) {
        logger.debug("Verificando la fecha");
        for(Appointment object : appointments) {
            if(object.getDate().isEqual(date)) {
                return false;
            }
        }
        return true;
    }

    public boolean confirmate(int id) {
        logger.debug("Confirmando la cita que contiene el id ["+id+"]");
        for(Appointment object : appointments) {
            if(object.getId() == id) {
                object.setConfirm();
                return true;
            }
        }
        return false;
    }

    public String showDataAppoteintment(int id) {
        return searchAppointment(id).toString();
    }
}

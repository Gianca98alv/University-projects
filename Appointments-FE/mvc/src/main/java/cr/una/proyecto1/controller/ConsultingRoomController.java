package cr.una.proyecto1.controller;

import cr.una.proyecto1.Main;
import cr.una.proyecto1.model.ConsultingRoom;
import cr.una.proyecto1.service.Service;
import cr.una.proyecto1.view.ConsultingRoomView;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class ConsultingRoomController {

    final Logger logger = LogManager.getLogger(ConsultingRoomController.class);

    //Atributos
    private Service service;
    private ConsultingRoomView crView;

    //Constructor
    public ConsultingRoomController (Service service, ConsultingRoomView crView){
        logger.debug("Consulting Room Controller");

        this.service = service;
        this.crView = crView;
        crView.setController(this);
        crView.setService(service);
    }

    //Wrappers
    public void newConsultingRoom (String name, String telephone, String day, String hour){
        ConsultingRoom consultingRoom = new ConsultingRoom(name, telephone, day, hour);
        service.newConsultingRoom(consultingRoom);
    };

    public void getConsultRoom() {
        service.updateTableConsultingRooms(service.getConsultingRooms());
    }

    public void updateConsultingRoom(String name, String telephone, String day, String hour) {
        ConsultingRoom consultingRoom = new ConsultingRoom(name, telephone, day, hour);
        service.updateConsultingRoom(consultingRoom);
    }

    public ConsultingRoom searchConsultingRoom (String n) {
        return service.searchConsulRoom(n);
    }

    public boolean deleteConsultingRoom(String n) {
        return service.deleteConsultRoom(n);
    }

    //Administración de la  ventana
    public void showConsultingRoom () {
        crView.setVisible(true);
    }

    public void hideConsultingRoom () {
        crView.setVisible(false);
    }

    public boolean findNameConsultingRoom(String n){ return service.findNameConsultingRoom(n); }

    public void back() {
        hideConsultingRoom();
        Main.consultingRoomController.showConsultingRoom();
    }
}
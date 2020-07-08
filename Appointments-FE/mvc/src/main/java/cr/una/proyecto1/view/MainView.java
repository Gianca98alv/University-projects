package cr.una.proyecto1.view;

import javax.swing.*;
import java.awt.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class MainView extends JFrame {

 final Logger logger = LogManager.getLogger(MainView.class);

 public JLabel textWelcome;
 public JButton patient, consultingRoom, appointment, viewPatient, exitButton;
 public JPanel mainPanel = new JPanel();

 public MainView(){
  super("Main window");
  setSize(360,200);
  setResizable(false);
  setLocationRelativeTo(null);
  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  setVisible(true);
  this.getContentPane().add(mainPanel);

  textWelcome = new JLabel("Welcome to the digital file of doctor Dr. Juan Perez");
  patient = new JButton("Manage patient data");
  consultingRoom = new JButton("Manage consulting room data");
  appointment = new JButton("Schedule appointment");
  exitButton = new JButton("Exit");

  setComponents();

  addComponents();

  add(mainPanel);
 }

 private void setComponents(){
  mainPanel.setLayout(null);
  mainPanel.setBackground(Color.WHITE);
  mainPanel.setName("mainPanel");
  textWelcome.setName("textWelcome");
  patient.setName("patient");
  consultingRoom.setName("consultingRoom");
  appointment.setName("appointment");
  exitButton.setName("exitButton");
 }

 private void addComponents(){
  mainPanel.add(textWelcome);
  textWelcome.setBounds(30,10,500,20);
  mainPanel.add(patient);
  patient.setBounds(47,35,250,20);
  mainPanel.add(consultingRoom);
  consultingRoom.setBounds(47,65,250,20);
  mainPanel.add(appointment);
  appointment.setBounds(47,95,250,20);
  mainPanel.add(exitButton);
  exitButton.setBounds(47,125,250,20);
 }

}

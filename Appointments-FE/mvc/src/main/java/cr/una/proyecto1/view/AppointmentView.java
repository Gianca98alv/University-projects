package cr.una.proyecto1.view;

import cr.una.proyecto1.controller.AppointmentController;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Observable;
import javax.swing.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import cr.una.proyecto1.model.Appointment;
import cr.una.proyecto1.model.AppointmentTable;
import cr.una.proyecto1.service.Service;

public class AppointmentView extends javax.swing.JFrame implements java.util.Observer {

    final Logger logger = LogManager.getLogger(AppointmentView.class);

    private static final String GOOD = "EXITO";
    private static final String FAIL = "ERROR";
    private static final String MESSAGE_CONFIRMATE = "APPOINTMENT %d HA SIDO CONFIRMADA CON %s";
    private Service service;
    private AppointmentController appointmentController;
    private AppointmentTable appointmentTable;

    private int[] getDataInteger() {
        int[] data = new int[5];
        try {
            data[0] = Integer.parseInt(dia.getText());
            data[1] = Integer.parseInt(mes.getText());
            data[2] = Integer.parseInt(ano.getText());
            data[3] = Integer.parseInt(hora.getText());
            data[4] = Integer.parseInt(minutos.getText());
        } catch(NumberFormatException ex) {
            System.err.println(String.format("ERROR: %s", ex.getMessage()));
        } finally {
            return data;
        }
    }

    private int getID() {
        int data = 0;
        try {
            data = Integer.parseInt(codigo.getText());
        } catch(NumberFormatException ex) {
            System.err.println(String.format("ERROR: %s", ex.getMessage()));
        } finally {
            return data;
        }
    }

    private void updateTableModel () {
        appointmentTable = service.getAppointmentTable();
        this.jTable1.setModel(appointmentTable);
    }

    //Evita campos vacios
    private boolean validateSpaces () {
        return !(idPaciente.getText().isEmpty() && dia.getText().isEmpty() && mes.getText().isEmpty() && ano.getText().isEmpty()&& hora.getText().isEmpty()&& minutos.getText().isEmpty());
    }

    //Busca y setea en los campos de texto el obj que se busca
    private void consult (int n) {
        Appointment ap = service.searchAppointment(n);
        if (ap != null){
            ArrayList<Appointment> aux0 = new ArrayList<>();
            aux0.add(ap);
            AppointmentTable aux1 = new AppointmentTable(aux0);
            this.jTable1.setModel(aux1);
        }
    }

    private void clean() {
        idPaciente.setText("");
        dia.setText("");
        mes.setText("");
        ano.setText("");
        hora.setText("");
        minutos.setText("");
    }

    private void update () {
        this.appointmentController.getAppointment();
    }

    public AppointmentView() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    private void initComponents() {

        jLabel1 = new JLabel();
        jLabel2 = new JLabel();
        jLabel3 = new JLabel();
        jLabel4 = new JLabel();
        jScrollPane1 = new JScrollPane();
        jTable1 = new JTable();
        idPaciente = new JTextField();
        dia = new JTextField();
        hora = new JTextField();
        ingresar = new JButton();
        confirmar = new JButton();
        eliminar = new JButton();
        buscar = new JButton();
        regresar = new JButton();
        jLabel5 = new JLabel();
        codigo = new JTextField();
        jLabel6 = new JLabel();
        mes = new JTextField();
        jLabel7 = new JLabel();
        ano = new JTextField();
        jLabel8 = new JLabel();
        minutos = new JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jLabel1.setText("Cita");

        jLabel2.setText("Paciente:");

        jLabel3.setText("Fecha:");

        jLabel4.setText("Hora:");

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
                new Object [][] {
                        {null, null, null, null},
                        {null, null, null, null},
                        {null, null, null, null},
                        {null, null, null, null}
                },
                new String [] {
                        "Title 1", "Title 2", "Title 3", "Title 4"
                }
        ));
        jScrollPane1.setViewportView(jTable1);

        ingresar.setText("Ingresar");
        ingresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ingresarActionPerformed(evt);
            }
        });

        confirmar.setText("Confirmar");
        confirmar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                modificarActionPerformed(evt);
            }
        });

        eliminar.setText("Eliminar");
        eliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                eliminarActionPerformed(evt);
            }
        });

        buscar.setText("Buscar");
        buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarActionPerformed(evt);
            }
        });

        regresar.setText("Regresar");
        regresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                regresarActionPerformed(evt);
            }
        });

        jLabel5.setText("Buscar:");

        jLabel6.setText("/");

        jLabel7.setText("/");

        jLabel8.setText(":");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(layout.createSequentialGroup()
                                                .addGap(288, 288, 288)
                                                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(0, 0, Short.MAX_VALUE))
                                        .addGroup(layout.createSequentialGroup()
                                                .addGap(25, 25, 25)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(jLabel2)
                                                                        .addComponent(jLabel3)
                                                                        .addComponent(jLabel4))
                                                                .addGap(53, 53, 53)
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(idPaciente, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                        .addGroup(layout.createSequentialGroup()
                                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                                                                        .addComponent(hora, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 49, Short.MAX_VALUE)
                                                                                        .addComponent(dia, javax.swing.GroupLayout.Alignment.LEADING))
                                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                                                        .addGroup(layout.createSequentialGroup()
                                                                                                .addComponent(jLabel6)
                                                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                                                .addComponent(mes, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                                        .addGroup(layout.createSequentialGroup()
                                                                                                .addComponent(jLabel8)
                                                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                                                .addComponent(minutos)))
                                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                                .addComponent(jLabel7)
                                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                                .addComponent(ano, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                                                .addGap(26, 26, 26)
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addGroup(layout.createSequentialGroup()
                                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                                                        .addComponent(confirmar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                                                        .addComponent(eliminar, javax.swing.GroupLayout.PREFERRED_SIZE, 108, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                                .addGap(18, 18, 18)
                                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                                        .addComponent(ingresar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                                                        .addComponent(buscar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                                                                        .addComponent(regresar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addGroup(layout.createSequentialGroup()
                                                                                .addComponent(jLabel5)
                                                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                                                .addComponent(codigo, javax.swing.GroupLayout.PREFERRED_SIZE, 67, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 628, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                .addGap(0, 0, Short.MAX_VALUE)))))
                                .addContainerGap())
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(jLabel1)
                                .addGap(20, 20, 20)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                        .addGroup(layout.createSequentialGroup()
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jLabel2)
                                                        .addComponent(idPaciente, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addGap(23, 23, 23)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addComponent(jLabel3)
                                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                                .addComponent(dia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addComponent(jLabel6)
                                                                .addComponent(mes, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addComponent(jLabel7)
                                                                .addComponent(ano, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                                .addGap(20, 20, 20)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jLabel4)
                                                        .addComponent(hora, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(jLabel8)
                                                        .addComponent(minutos, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                        .addGroup(layout.createSequentialGroup()
                                                .addComponent(regresar)
                                                .addGap(18, 18, 18)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(ingresar)
                                                        .addComponent(eliminar))
                                                .addGap(21, 21, 21)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(confirmar)
                                                        .addComponent(buscar))))
                                .addGap(34, 34, 34)
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 98, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(jLabel5)
                                        .addComponent(codigo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addContainerGap(29, Short.MAX_VALUE))
        );

        pack();
    }

    private void regresarActionPerformed(java.awt.event.ActionEvent evt) {
        appointmentController.hideAppointment();
    }

    private void ingresarActionPerformed(java.awt.event.ActionEvent evt) {
        String idPatient = idPaciente.getText();
        if (validateSpaces() && appointmentController.searchPatient(idPatient)) {
            int[] data = getDataInteger();
            LocalDateTime l = LocalDateTime.of(data[2], data[1], data[0], data[3], data[4]);
            if(appointmentController.validateDates(l)) {
                String consultorio = appointmentController.getConsultingRoom(l.getDayOfWeek().toString());
                if(!consultorio.isEmpty()) {
                    appointmentController.newAppointment(idPatient,consultorio, l);
                    JOptionPane.showMessageDialog(rootPane, GOOD);
                    clean();
                    update();
                    return;
                }
            }
        }
        JOptionPane.showMessageDialog(rootPane, FAIL);

    }

    private void modificarActionPerformed(java.awt.event.ActionEvent evt) {
        int dataID = getID();
        if(appointmentController.confirmate(dataID)) {
            JOptionPane.showMessageDialog(rootPane, String.format(MESSAGE_CONFIRMATE, dataID, GOOD));
            update();
            clean();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void buscarActionPerformed(java.awt.event.ActionEvent evt) {
        int dataID = getID();
        if(appointmentController.findIdAppointment(dataID)) {
            JOptionPane.showMessageDialog(rootPane, appointmentController.showDataAppoteintment(dataID));
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void eliminarActionPerformed(java.awt.event.ActionEvent evt) {
        int dataID = getID();
        if (appointmentController.findIdAppointment(dataID)) {
            appointmentController.deleteAppointment(dataID);
            JOptionPane.showMessageDialog(rootPane, GOOD);
            clean();
            update();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    public Service getService() {
        return service;
    }

    public void setService(Service service) {
        this.service = service;
        service.addObserver(this);
        this.appointmentController.getAppointment();
    }

    public void setController (AppointmentController appointmentController) {
        this.appointmentController = appointmentController;
    }

    public AppointmentController getAppointmentController() {
        return appointmentController;
    }

    // Variables declaration - do not modify
    private JTextField ano;
    private JButton buscar;
    private JTextField codigo;
    private JTextField dia;
    private JButton eliminar;
    private JTextField hora;
    private JTextField idPaciente;
    private JButton ingresar;
    private JLabel jLabel1;
    private JLabel jLabel2;
    private JLabel jLabel3;
    private JLabel jLabel4;
    private JLabel jLabel5;
    private JLabel jLabel6;
    private JLabel jLabel7;
    private JLabel jLabel8;
    private JScrollPane jScrollPane1;
    private JTable jTable1;
    private JTextField mes;
    private JTextField minutos;
    private JButton confirmar;
    private JButton regresar;


    @Override
    public void update(Observable o, Object arg) { updateTableModel(); }
    // End of variables declaration
}
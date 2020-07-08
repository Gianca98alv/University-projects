package cr.una.proyecto1.view;

import cr.una.proyecto1.controller.ConsultingRoomController;
import java.util.Observable;
import javax.swing.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import cr.una.proyecto1.model.ConsultingRoom;
import cr.una.proyecto1.model.ConsultingRoomTable;
import cr.una.proyecto1.service.Service;

public class ConsultingRoomView extends javax.swing.JFrame implements java.util.Observer {

    final Logger logger = LogManager.getLogger(ConsultingRoomView.class);

    private static final String GOOD = "EXITO";
    private static final String FAIL = "ERROR";
    private Service service;
    private ConsultingRoomController consultingRoomController;
    private ConsultingRoomTable consultingRoomTable;

    private void updateTableModel () {
        consultingRoomTable = service.getConsultingRoomTable();
        this.jTable1.setModel(consultingRoomTable);
    }

    //Evita campos vacios
    private boolean validateSpaces () {
        return !(name.getText().isEmpty() && telephone.getText().isEmpty() && day.getText().isEmpty() && hour.getText().isEmpty());
    }

    //Busca y setea en los campos de texto el obj que se busca
    private void consult (String n) {
        ConsultingRoom cr = service.searchConsulRoom(n);
        telephone.setText(cr.getTelephone());
        day.setText(cr.getDay());
        hour.setText(cr.getHour());
    }

    private void clean() {
        name.setText("");
        telephone.setText("");
        day.setText("");
        hour.setText("");
    }

    private void update () {
        this.consultingRoomController.getConsultRoom();
    }

    public ConsultingRoomView() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        name = new javax.swing.JTextField();
        telephone = new javax.swing.JTextField();
        day = new javax.swing.JTextField();
        hour = new javax.swing.JTextField();
        regresarButton = new javax.swing.JButton();
        limpiarButton = new javax.swing.JButton();
        agregarButton = new javax.swing.JButton();
        modificarButton = new javax.swing.JButton();
        eliminarButton = new javax.swing.JButton();
        buscarButton = new javax.swing.JButton();

        //Accion al cerrar la ventana
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

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

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 30)); // NOI18N
        jLabel1.setText("Consultorios");

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel2.setText("Nombre");

        jLabel3.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel3.setText("Telefono");

        jLabel4.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel4.setText("Dia");

        jLabel5.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel5.setText("Hora");

        regresarButton.setText("Regresar");
        regresarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                regresarButtonActionPerformed(evt);
            }
        });

        limpiarButton.setText("Limpiar");
        limpiarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                limpiarButtonActionPerformed(evt);
            }
        });

        agregarButton.setText("Agregar");
        agregarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                agregarButtonActionPerformed(evt);
            }
        });

        modificarButton.setText("Modificar");
        modificarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                modificarButtonActionPerformed(evt);
            }
        });

        eliminarButton.setText("Eliminar");
        eliminarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                eliminarButtonActionPerformed(evt);
            }
        });

        buscarButton.setText("Buscar");
        buscarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(layout.createSequentialGroup()
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(jLabel4)
                                                                        .addComponent(jLabel2))
                                                                .addGap(42, 42, 42)
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                                        .addComponent(telephone)
                                                                        .addComponent(name)
                                                                        .addComponent(day)
                                                                        .addComponent(hour, javax.swing.GroupLayout.DEFAULT_SIZE, 198, Short.MAX_VALUE)))
                                                        .addComponent(jLabel3)
                                                        .addComponent(jLabel5))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                        .addGroup(layout.createSequentialGroup()
                                                .addGap(0, 11, Short.MAX_VALUE)
                                                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(34, 34, 34)))
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(regresarButton, javax.swing.GroupLayout.DEFAULT_SIZE, 85, Short.MAX_VALUE)
                                        .addComponent(limpiarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(agregarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(modificarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(eliminarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(buscarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addContainerGap())
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(regresarButton))
                                .addGap(14, 14, 14)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(jLabel2)
                                        .addComponent(name, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(limpiarButton))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(jLabel3)
                                        .addComponent(telephone, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(agregarButton))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(jLabel4)
                                        .addComponent(day, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(modificarButton))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(jLabel5)
                                        .addComponent(hour, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(eliminarButton))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(buscarButton, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(2, 2, 2))
        );

        pack();
    }// </editor-fold>

    private void regresarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        consultingRoomController.hideConsultingRoom();
    }

    private void nameActionPerformed(java.awt.event.ActionEvent evt) {}

    private void agregarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if (validateSpaces() && !consultingRoomController.findNameConsultingRoom(name.getText())) {
            consultingRoomController.newConsultingRoom(name.getText(), telephone.getText(), day.getText(), hour.getText());
            JOptionPane.showMessageDialog(rootPane, GOOD);
            clean();
            update();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void modificarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if(validateSpaces() && consultingRoomController.findNameConsultingRoom(name.getText())) {
            consultingRoomController.updateConsultingRoom(name.getText(), telephone.getText(), day.getText(), hour.getText());
            JOptionPane.showMessageDialog(rootPane, GOOD);
            clean();
            update();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void eliminarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if(!name.getText().isEmpty() && consultingRoomController.findNameConsultingRoom(name.getText())) {
            consultingRoomController.deleteConsultingRoom(name.getText());
            JOptionPane.showMessageDialog(rootPane, GOOD);
            clean();
            update();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void buscarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if(!name.getText().isEmpty() && consultingRoomController.findNameConsultingRoom(name.getText())) {
            consult(name.getText());
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void limpiarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        clean();
    }

    public Service getService() {
        return service;
    }

    public void setService(Service service) {
        this.service = service;
        service.addObserver(this);
        this.consultingRoomController.getConsultRoom();
    }

    public void setController (ConsultingRoomController consultingRoomController) {
        this.consultingRoomController = consultingRoomController;
    }

    public ConsultingRoomController getConsultingRoomController() {
        return consultingRoomController;
    }

    // Variables declaration - do not modify
    private JButton agregarButton;
    private JButton buscarButton;
    private JTextField day;
    private JButton eliminarButton;
    private JTextField hour;
    private JLabel jLabel1;
    private JLabel jLabel2;
    private JLabel jLabel3;
    private JLabel jLabel4;
    private JLabel jLabel5;
    private JScrollPane jScrollPane1;
    private JTable jTable1;
    private JButton limpiarButton;
    private JButton modificarButton;
    private JTextField name;
    private JButton regresarButton;
    private JTextField telephone;
    // End of variables declaration

    @Override
    public void update(Observable o, Object arg) {
        updateTableModel();
    }
}

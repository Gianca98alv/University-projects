package cr.una.proyecto1.view;

import cr.una.proyecto1.controller.PatientController;
import cr.una.proyecto1.model.Patient;
import cr.una.proyecto1.model.PatientTable;
import cr.una.proyecto1.service.Service;

import javax.swing.*;
import java.util.Observable;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class PatientView extends javax.swing.JFrame implements java.util.Observer {

    final Logger logger = LogManager.getLogger(PatientView.class);

    private static final String GOOD = "EXITO";
    private static final String FAIL = "ERROR";
    private Service service;
    private PatientController patientController;
    private PatientTable patientTable;
    private JScrollPane jScrollPane1;
    private JTable table1;
    private JLabel pacientesLabel;
    private JTextField name;
    private JTextField id;
    private JTextField cellnum;
    private JTextField address;
    private JTextField birthdate;
    private JTextField diseases;
    private JTextField observations;
    private JButton regresarButton;
    private JButton limpiarButton;
    private JButton agregarButton;
    private JButton modificarButton;
    private JButton eliminarButton;
    private JButton buscarButton;
    private JLabel jLabel2;
    private JLabel jLabel3;
    private JLabel jLabel4;
    private JLabel jLabel5;
    private JLabel jLabel6;
    private JLabel jLabel7;
    private JLabel jLabel8;

    private void updateTableModel () {
        patientTable = service.getPatientTable();
        this.table1.setModel(patientTable);
    }

    private boolean validateSpaces () {
        return !(name.getText().isEmpty() && id.getText().isEmpty() && cellnum.getText().isEmpty() &&
        address.getText().isEmpty() && birthdate.getText().isEmpty() && diseases.getText().isEmpty() &&
        observations.getText().isEmpty());
    }

    private void consult (String ide) {
        Patient p = service.searchPatient(ide);
        name.setText(p.getName());
        id.setText(p.getId());
        cellnum.setText(String.format("%d", p.getCellnum()));
        address.setText(p.getAddress());
        birthdate.setText(p.getBirthdate());
        diseases.setText(p.getDiseases());
        observations.setText(p.getObservations());
    }

    private void clean() {
        name.setText("");
        id.setText("");
        cellnum.setText("");
        address.setText("");
        birthdate.setText("");
        diseases.setText("");
        observations.setText("");
    }

    private void update () {
        this.patientController.getPatient();
    }

    public PatientView() {
        initComponents();
    }

    public Service getService() {
        return service;
    }

    public void setService(Service service) {
        this.service = service;
        service.addObserver(this);
        this.patientController.getPatient();
    }

    public void setController (PatientController patientController) {
        this.patientController = patientController;
    }

    public PatientController getPatientController() {
        return patientController;
    }

    private void createUIComponents() {
        // TODO: place custom component creation code here
    }

    @Override
    public void update(Observable o, Object arg) {
        updateTableModel();
    }

    private int validateInteger() {
        int data = 0;
        try {
            data = Integer.parseInt(cellnum.getText());
        } catch(NumberFormatException excepcion) {
            System.err.println(String.format("ERROR: %s", excepcion.getMessage()));
        } finally {
            return data;
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">
    private void initComponents() {

        jScrollPane1 = new JScrollPane();
        table1 = new JTable();
        pacientesLabel = new JLabel();
        jLabel2 = new JLabel();
        jLabel3 = new JLabel();
        jLabel4 = new JLabel();
        jLabel5 = new JLabel();
        jLabel6 = new JLabel();
        jLabel7 = new JLabel();
        jLabel8 = new JLabel();
        name = new JTextField();
        id = new JTextField();
        cellnum = new JTextField();
        address = new JTextField();
        birthdate = new JTextField();
        diseases = new JTextField();
        observations = new JTextField();
        regresarButton = new JButton();
        limpiarButton = new JButton();
        agregarButton = new JButton();
        modificarButton = new JButton();
        buscarButton = new JButton();
        eliminarButton = new JButton();

        //Accion al cerrar la ventana
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

        //Setea la fuente de la ventana
        setFont(new java.awt.Font("Arial", 1, 36)); // NOI18N

        table1.setModel(new javax.swing.table.DefaultTableModel(
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
        jScrollPane1.setViewportView(table1);

        pacientesLabel.setFont(new java.awt.Font("Tahoma", 1, 36)); // NOI18N
        pacientesLabel.setText("Pacientes");

        jLabel2.setText("Nombre");

        jLabel3.setText("ID");

        jLabel4.setText("Celular");

        jLabel5.setText("Direccion");

        jLabel6.setText("Fecha de nacimiento");

        jLabel7.setText("Enfermedades");

        jLabel8.setText("Observaciones");

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

        buscarButton.setText("Buscar");
        buscarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarButtonActionPerformed(evt);
            }
        });

        eliminarButton.setText("Eliminar");
        eliminarButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                eliminarButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(layout.createSequentialGroup()
                                                .addGap(20, 20, 20)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addComponent(jLabel6)
                                                        .addComponent(jLabel7)
                                                        .addComponent(jLabel8))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                        .addComponent(diseases)
                                                        .addComponent(observations, javax.swing.GroupLayout.DEFAULT_SIZE, 259, Short.MAX_VALUE)
                                                        .addComponent(birthdate))
                                                .addGap(0, 0, Short.MAX_VALUE))
                                        .addGroup(layout.createSequentialGroup()
                                                .addGap(23, 23, 23)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addComponent(pacientesLabel)
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(jLabel2)
                                                                        .addComponent(jLabel3))
                                                                .addGap(103, 103, 103)
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                                                        .addComponent(name)
                                                                        .addComponent(id)
                                                                        .addComponent(cellnum, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(jLabel5)
                                                                        .addComponent(jLabel4))
                                                                .addGap(101, 101, 101)
                                                                .addComponent(address, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                                .addGap(3, 3, 3)))
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(regresarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(modificarButton)
                                        .addComponent(limpiarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(agregarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(buscarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(eliminarButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 727, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap(28, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(pacientesLabel)
                                .addGap(23, 23, 23)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                        .addGroup(layout.createSequentialGroup()
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jLabel2)
                                                        .addComponent(name, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(regresarButton))
                                                .addGap(18, 18, 18)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jLabel3)
                                                        .addComponent(id, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(limpiarButton))
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGap(120, 120, 120)
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                                        .addComponent(birthdate, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                        .addComponent(jLabel6)))
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGap(18, 18, 18)
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(jLabel4)
                                                                        .addComponent(cellnum, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                .addGap(25, 25, 25)
                                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(address, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                        .addComponent(jLabel5)))
                                                        .addGroup(layout.createSequentialGroup()
                                                                .addGap(30, 30, 30)
                                                                .addComponent(agregarButton)
                                                                .addGap(32, 32, 32)
                                                                .addComponent(modificarButton)))
                                                .addGap(18, 18, 18)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(diseases, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(jLabel7))
                                                .addGap(22, 22, 22)
                                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jLabel8)
                                                        .addComponent(observations, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                .addGroup(layout.createSequentialGroup()
                                                        .addComponent(buscarButton)
                                                        .addGap(57, 57, 57))
                                                .addComponent(eliminarButton, javax.swing.GroupLayout.Alignment.TRAILING)))
                                .addGap(32, 32, 32)
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 106, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap(110, Short.MAX_VALUE))
        );

        pack();
    }

    private void agregarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if (validateSpaces() && !patientController.findIdPatient(id.getText())) {
            patientController.newPatient(name.getText(), id.getText(), validateInteger(),
                    address.getText(), birthdate.getText(), diseases.getText(), observations.getText());
            JOptionPane.showMessageDialog(rootPane, GOOD);
            clean();
            update();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void modificarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if (validateSpaces() && patientController.findIdPatient(id.getText())) {
            patientController.updatePatient(name.getText(), id.getText(), validateInteger(),
                    address.getText(), birthdate.getText(), diseases.getText(), observations.getText());
            JOptionPane.showMessageDialog(rootPane, GOOD);
            clean();
            update();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void eliminarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if (!id.getText().isEmpty() && patientController.findIdPatient(id.getText())) {
            patientController.deletePatient(id.getText());
            JOptionPane.showMessageDialog(rootPane, GOOD);
            clean();
            update();
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void buscarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        if (!id.getText().isEmpty() && patientController.findIdPatient(id.getText())) {
            consult(id.getText());
        } else {
            JOptionPane.showMessageDialog(rootPane, FAIL);
        }
    }

    private void limpiarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        clean();
    }

    private void regresarButtonActionPerformed(java.awt.event.ActionEvent evt) {
        patientController.hidePatient();
    }
    
}

package paintfinal;

import java.io.File;
import javax.swing.JButton;
import javax.swing.JFileChooser;

/**
 *
 * @author Jesús Ángel González Novez
 */
public class VentanaPrincipal extends javax.swing.JFrame {
    
    /**
     * Creates new form VentanaPrincipal
     */
    public VentanaPrincipal() {
        initComponents();
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        herramientasGrupo = new javax.swing.ButtonGroup();
        barraColor = new javax.swing.JPanel();
        barraEstado = new javax.swing.JLabel();
        panelColor = new javax.swing.JPanel();
        rojoButton = new javax.swing.JButton();
        azulButton = new javax.swing.JButton();
        verdeButton = new javax.swing.JButton();
        negroButton = new javax.swing.JButton();
        blancoButton = new javax.swing.JButton();
        amarilloButton = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        jPanel3 = new javax.swing.JPanel();
        grosorLabel = new javax.swing.JLabel();
        grosorSpin = new javax.swing.JSpinner();
        jPanel2 = new javax.swing.JPanel();
        rellenoButton = new javax.swing.JCheckBox();
        editarButton = new javax.swing.JCheckBox();
        jCheckBox1 = new javax.swing.JCheckBox();
        jCheckBox2 = new javax.swing.JCheckBox();
        jToolBar1 = new javax.swing.JToolBar();
        lapizButton = new javax.swing.JToggleButton();
        lineaButton = new javax.swing.JToggleButton();
        rectanguloButton = new javax.swing.JToggleButton();
        ovaloButton = new javax.swing.JToggleButton();
        desktop = new javax.swing.JDesktopPane();
        barraMenu = new javax.swing.JMenuBar();
        archivoMenu = new javax.swing.JMenu();
        nuevoMenu = new javax.swing.JMenuItem();
        abrirMenu = new javax.swing.JMenuItem();
        guardarMenu = new javax.swing.JMenuItem();
        edicionMenu = new javax.swing.JMenu();
        verMenu = new javax.swing.JCheckBoxMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(500, 600));

        barraColor.setLayout(new java.awt.BorderLayout());

        barraEstado.setText("Punto");
        barraEstado.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        barraColor.add(barraEstado, java.awt.BorderLayout.PAGE_END);

        rojoButton.setBackground(java.awt.Color.red);
        rojoButton.setText(" ");
        rojoButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                rojoButtonMouseClicked(evt);
            }
        });

        azulButton.setBackground(java.awt.Color.blue);
        azulButton.setText(" ");
        azulButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                azulButtonMouseClicked(evt);
            }
        });

        verdeButton.setBackground(new java.awt.Color(13, 255, 0));
        verdeButton.setText(" ");
        verdeButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                verdeButtonMouseClicked(evt);
            }
        });

        negroButton.setBackground(new java.awt.Color(4, 2, 2));
        negroButton.setText(" ");
        negroButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                negroButtonMouseClicked(evt);
            }
        });

        blancoButton.setText(" ");
        blancoButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                blancoButtonMouseClicked(evt);
            }
        });

        amarilloButton.setBackground(new java.awt.Color(255, 244, 0));
        amarilloButton.setText(" ");
        amarilloButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                amarilloButtonMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout panelColorLayout = new javax.swing.GroupLayout(panelColor);
        panelColor.setLayout(panelColorLayout);
        panelColorLayout.setHorizontalGroup(
            panelColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelColorLayout.createSequentialGroup()
                .addGroup(panelColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(panelColorLayout.createSequentialGroup()
                        .addGap(5, 5, 5)
                        .addComponent(rojoButton)
                        .addGap(5, 5, 5))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, panelColorLayout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(negroButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                .addGroup(panelColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(panelColorLayout.createSequentialGroup()
                        .addGap(1, 1, 1)
                        .addComponent(azulButton)
                        .addGap(5, 5, 5)
                        .addComponent(verdeButton))
                    .addGroup(panelColorLayout.createSequentialGroup()
                        .addComponent(blancoButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(amarilloButton)))
                .addGap(0, 0, 0))
        );
        panelColorLayout.setVerticalGroup(
            panelColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelColorLayout.createSequentialGroup()
                .addGap(0, 0, 0)
                .addGroup(panelColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(rojoButton)
                    .addComponent(azulButton)
                    .addComponent(verdeButton))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(panelColorLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(negroButton)
                    .addComponent(blancoButton)
                    .addComponent(amarilloButton)))
        );

        barraColor.add(panelColor, java.awt.BorderLayout.WEST);

        jPanel1.setLayout(new java.awt.BorderLayout());

        jPanel3.setBorder(javax.swing.BorderFactory.createEtchedBorder());

        grosorLabel.setText("Grosor");
        jPanel3.add(grosorLabel);

        grosorSpin.setToolTipText("");
        grosorSpin.setName(""); // NOI18N
        grosorSpin.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                grosorSpinStateChanged(evt);
            }
        });
        jPanel3.add(grosorSpin);

        jPanel1.add(jPanel3, java.awt.BorderLayout.WEST);

        jPanel2.setLayout(new java.awt.BorderLayout());

        rellenoButton.setText("Relleno");
        rellenoButton.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        rellenoButton.setHorizontalTextPosition(javax.swing.SwingConstants.RIGHT);
        rellenoButton.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                rellenoButtonStateChanged(evt);
            }
        });
        jPanel2.add(rellenoButton, java.awt.BorderLayout.SOUTH);

        editarButton.setText("Editar");
        editarButton.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                editarButtonStateChanged(evt);
            }
        });
        jPanel2.add(editarButton, java.awt.BorderLayout.NORTH);

        jCheckBox1.setText("Alisar");
        jPanel2.add(jCheckBox1, java.awt.BorderLayout.CENTER);

        jPanel1.add(jPanel2, java.awt.BorderLayout.EAST);

        barraColor.add(jPanel1, java.awt.BorderLayout.CENTER);

        jCheckBox2.setText("Transparencia");
        barraColor.add(jCheckBox2, java.awt.BorderLayout.LINE_END);

        getContentPane().add(barraColor, java.awt.BorderLayout.PAGE_END);

        jToolBar1.setRollover(true);

        herramientasGrupo.add(lapizButton);
        lapizButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/Lapiz.gif"))); // NOI18N
        lapizButton.setFocusable(false);
        lapizButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        lapizButton.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        lapizButton.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                lapizButtonStateChanged(evt);
            }
        });
        jToolBar1.add(lapizButton);

        herramientasGrupo.add(lineaButton);
        lineaButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/Linea.gif"))); // NOI18N
        lineaButton.setFocusable(false);
        lineaButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        lineaButton.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        lineaButton.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                lineaButtonStateChanged(evt);
            }
        });
        lineaButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                lineaButtonActionPerformed(evt);
            }
        });
        jToolBar1.add(lineaButton);

        herramientasGrupo.add(rectanguloButton);
        rectanguloButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/Rectangulo.gif"))); // NOI18N
        rectanguloButton.setFocusable(false);
        rectanguloButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        rectanguloButton.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        rectanguloButton.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                rectanguloButtonStateChanged(evt);
            }
        });
        jToolBar1.add(rectanguloButton);

        herramientasGrupo.add(ovaloButton);
        ovaloButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/Ovalo.gif"))); // NOI18N
        ovaloButton.setFocusable(false);
        ovaloButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        ovaloButton.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        ovaloButton.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                ovaloButtonStateChanged(evt);
            }
        });
        jToolBar1.add(ovaloButton);

        getContentPane().add(jToolBar1, java.awt.BorderLayout.PAGE_START);
        getContentPane().add(desktop, java.awt.BorderLayout.CENTER);

        archivoMenu.setText("Archivo");

        nuevoMenu.setText("Nuevo");
        nuevoMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nuevoMenuActionPerformed(evt);
            }
        });
        archivoMenu.add(nuevoMenu);

        abrirMenu.setText("Abrir");
        abrirMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                abrirMenuActionPerformed(evt);
            }
        });
        archivoMenu.add(abrirMenu);

        guardarMenu.setText("Guardar");
        guardarMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                guardarMenuActionPerformed(evt);
            }
        });
        archivoMenu.add(guardarMenu);

        barraMenu.add(archivoMenu);

        edicionMenu.setText("Edición");

        verMenu.setSelected(true);
        verMenu.setText("Ver barra estado");
        verMenu.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                verMenuStateChanged(evt);
            }
        });
        verMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                verMenuActionPerformed(evt);
            }
        });
        edicionMenu.add(verMenu);

        barraMenu.add(edicionMenu);

        setJMenuBar(barraMenu);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void rojoButtonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_rojoButtonMouseClicked
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null) vi.getLienzo().setColor(((JButton)evt.getSource()).getBackground());
        this.repaint();
    }//GEN-LAST:event_rojoButtonMouseClicked

    private void lapizButtonStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_lapizButtonStateChanged
        if(this.lapizButton.isSelected()){
            this.barraEstado.setText("Punto");
                    desktop.getSelectedFrame().getContentPane();
        }
    }//GEN-LAST:event_lapizButtonStateChanged

    private void rellenoButtonStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_rellenoButtonStateChanged
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null){
            if(this.rellenoButton.isSelected())
                 vi.getLienzo().setRelleno(true);
             else
                 vi.getLienzo().setRelleno(false);
         }
        repaint();
    }//GEN-LAST:event_rellenoButtonStateChanged

    private void lineaButtonStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_lineaButtonStateChanged
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null){
            if(this.lineaButton.isSelected()){
                this.barraEstado.setText("Linea");
                 vi.getLienzo().setForma(1);
            }
        }
    }//GEN-LAST:event_lineaButtonStateChanged

    private void rectanguloButtonStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_rectanguloButtonStateChanged
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null){
            if(this.rectanguloButton.isSelected()){
                this.barraEstado.setText("Rectangulo");
                 vi.getLienzo().setForma(2);
            }
        }
    }//GEN-LAST:event_rectanguloButtonStateChanged

    private void ovaloButtonStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_ovaloButtonStateChanged
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null){
            if(this.ovaloButton.isSelected())
                this.barraEstado.setText("Circulo");
                 vi.getLienzo().setForma(3);
        }
    }//GEN-LAST:event_ovaloButtonStateChanged

    private void azulButtonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_azulButtonMouseClicked
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
         if(vi!=null) vi.getLienzo().setColor(((JButton)evt.getSource()).getBackground());
        this.repaint();
    }//GEN-LAST:event_azulButtonMouseClicked

    private void verdeButtonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_verdeButtonMouseClicked
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
         if(vi!=null) vi.getLienzo().setColor(((JButton)evt.getSource()).getBackground());
        this.repaint();
    }//GEN-LAST:event_verdeButtonMouseClicked

    private void negroButtonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_negroButtonMouseClicked
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
         if(vi!=null) vi.getLienzo().setColor(((JButton)evt.getSource()).getBackground());
        this.repaint();
    }//GEN-LAST:event_negroButtonMouseClicked

    private void blancoButtonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_blancoButtonMouseClicked
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
         if(vi!=null) vi.getLienzo().setColor(((JButton)evt.getSource()).getBackground());
        this.repaint();
    }//GEN-LAST:event_blancoButtonMouseClicked

    private void amarilloButtonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_amarilloButtonMouseClicked
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null) vi.getLienzo().setColor(((JButton)evt.getSource()).getBackground());
        this.repaint();
    }//GEN-LAST:event_amarilloButtonMouseClicked

    private void verMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_verMenuActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_verMenuActionPerformed

    private void verMenuStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_verMenuStateChanged
        if(this.verMenu.isSelected())
            this.barraEstado.setVisible(true);
        else
            this.barraEstado.setVisible(false);
    }//GEN-LAST:event_verMenuStateChanged

    private void abrirMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_abrirMenuActionPerformed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showOpenDialog(this);
        
        if( resp == JFileChooser.APPROVE_OPTION) {
            File f = dlg.getSelectedFile();
        }

    }//GEN-LAST:event_abrirMenuActionPerformed

    private void nuevoMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nuevoMenuActionPerformed
        VentanaInterna nuevaVentana = new VentanaInterna();
        nuevaVentana.setSize(300, 300);
        this.desktop.add(nuevaVentana);
        nuevaVentana.setVisible(true);

    }//GEN-LAST:event_nuevoMenuActionPerformed

    private void guardarMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_guardarMenuActionPerformed
        JFileChooser dlg = new JFileChooser();
        int resp = dlg.showSaveDialog(this);
        
        if( resp == JFileChooser.APPROVE_OPTION) {
            File f = dlg.getSelectedFile();
        }
    }//GEN-LAST:event_guardarMenuActionPerformed

    private void lineaButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_lineaButtonActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_lineaButtonActionPerformed

    private void grosorSpinStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_grosorSpinStateChanged
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null) {
            this.grosorSpin.getValue();
            vi.getLienzo().setGrosor((int) this.grosorSpin.getValue());
        }
        this.repaint();
    }//GEN-LAST:event_grosorSpinStateChanged

    private void editarButtonStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_editarButtonStateChanged
        VentanaInterna vi = (VentanaInterna)desktop.getSelectedFrame();
        if(vi!=null){
            if(this.editarButton.isSelected())
                 vi.getLienzo().setEditar(true);
             else
                 vi.getLienzo().setEditar(false);
         }
        repaint();
    }//GEN-LAST:event_editarButtonStateChanged
    
    
    
    
    
    
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem abrirMenu;
    private javax.swing.JButton amarilloButton;
    private javax.swing.JMenu archivoMenu;
    private javax.swing.JButton azulButton;
    private javax.swing.JPanel barraColor;
    private javax.swing.JLabel barraEstado;
    private javax.swing.JMenuBar barraMenu;
    private javax.swing.JButton blancoButton;
    private javax.swing.JDesktopPane desktop;
    private javax.swing.JMenu edicionMenu;
    private javax.swing.JCheckBox editarButton;
    private javax.swing.JLabel grosorLabel;
    private javax.swing.JSpinner grosorSpin;
    private javax.swing.JMenuItem guardarMenu;
    private javax.swing.ButtonGroup herramientasGrupo;
    private javax.swing.JCheckBox jCheckBox1;
    private javax.swing.JCheckBox jCheckBox2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JToggleButton lapizButton;
    private javax.swing.JToggleButton lineaButton;
    private javax.swing.JButton negroButton;
    private javax.swing.JMenuItem nuevoMenu;
    private javax.swing.JToggleButton ovaloButton;
    private javax.swing.JPanel panelColor;
    private javax.swing.JToggleButton rectanguloButton;
    private javax.swing.JCheckBox rellenoButton;
    private javax.swing.JButton rojoButton;
    private javax.swing.JCheckBoxMenuItem verMenu;
    private javax.swing.JButton verdeButton;
    // End of variables declaration//GEN-END:variables
}

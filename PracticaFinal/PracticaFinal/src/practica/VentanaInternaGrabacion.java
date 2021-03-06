package practica;

import java.io.File;
import javax.media.MediaLocator;
import javax.media.Player;
import javax.swing.JOptionPane;
import sm.sound.SMClipPlayer;
import sm.sound.SMPlayer;
import sm.sound.SMSoundRecorder;


public class VentanaInternaGrabacion extends javax.swing.JInternalFrame {

    /**
     * Creates new form VentanaInternaAudio
     */
    Player player_jmf = null;
    SMPlayer player_sm = null;
    boolean grabar = false;
    boolean reproducir = true;
    SMSoundRecorder rec = null;
    File file;

    public VentanaInternaGrabacion(File f) {
        initComponents();
        String ex_au = ".au";
        MediaLocator ml = null;
        this.file = f;

        try {
            String nom_archivo = f.getName();
            if (nom_archivo.indexOf(".au") != -1) {
                player_sm = new SMClipPlayer(f);
            } else if (nom_archivo.indexOf(".wav") != -1) {
                player_sm = new SMClipPlayer(f);
            } else {
                ml = new MediaLocator("file:" + f.getAbsolutePath());
            }

            this.pack();
            this.reproducir = true;
            this.grabar = false;
            if (nom_archivo.indexOf(".au") != -1) {
                SMSoundRecorder rec = new SMSoundRecorder(file);
                JOptionPane.showMessageDialog(null, "Se va grabar, pulse play para comenzar y stop para finalizar");
                this.grabar = true;
                this.reproducir = false;
                this.setTitle("Grabar en archivo: " + " " + file.getName());
            } else if (nom_archivo.indexOf(".wav") != -1) {
                SMSoundRecorder rec = new SMSoundRecorder(file);
                JOptionPane.showMessageDialog(null, "Se va grabar, pulse play para comenzar y stop para finalizar");
                this.grabar = true;
                this.reproducir = false;

            } else {
                JOptionPane.showMessageDialog(null, "Formato de archivo para grabar no admitido");
                this.setTitle("Reproducir en archivo: " + " " + file.getName());
            }
        } catch (Exception ex) {
        }

    }

    public static VentanaInternaGrabacion getInstance(File f) {
        VentanaInternaGrabacion v = new VentanaInternaGrabacion(f);

        if (v.player_sm != null) {
            return v;
        } else {
            return null;
        }

    }

    public void close() {
        if (player_sm != null) {
            player_sm.stop();
        }
        if (rec != null) {
            rec.stop();
        }
        this.removeAll();
        player_sm = null;
        rec = null;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panel_botones = new javax.swing.JPanel();
        botonPlay = new javax.swing.JToggleButton();
        botonStop = new javax.swing.JToggleButton();

        setClosable(true);
        setIconifiable(true);
        setMaximizable(true);
        setResizable(true);

        panel_botones.setLayout(new java.awt.GridLayout(1, 0));

        botonPlay.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/RecordPressed_48x48.png"))); // NOI18N
        botonPlay.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonPlayActionPerformed(evt);
            }
        });
        panel_botones.add(botonPlay);

        botonStop.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconos/StopPressedBlue_48x48.png"))); // NOI18N
        botonStop.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonStopActionPerformed(evt);
            }
        });
        panel_botones.add(botonStop);

        getContentPane().add(panel_botones, java.awt.BorderLayout.CENTER);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botonPlayActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonPlayActionPerformed

        if (rec == null) {
            String nom_archivo = file.getName();
            if (nom_archivo.indexOf(".au") != -1) {
                rec = new SMSoundRecorder(file);
                rec.record();
                this.setTitle("Grabando en archivo: " + " " + file.getName());
            } else if (nom_archivo.indexOf(".wav") != -1) {
                rec = new SMSoundRecorder(file);
                rec.record();
                this.setTitle("Grabando en archivo: " + " " + file.getName());
            }
        }
        if (rec != null) {
            rec.record();
            this.setTitle("Grabando en archivo: " + " " + file.getName());
        }


    }//GEN-LAST:event_botonPlayActionPerformed

    private void botonStopActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonStopActionPerformed
        if (rec != null) {
            rec.stop();
            this.setTitle("Parada grabacion archivo: " + " " + file.getName());
        }

    }//GEN-LAST:event_botonStopActionPerformed

    private void formInternalFrameClosing(javax.swing.event.InternalFrameEvent evt) {//GEN-FIRST:event_formInternalFrameClosing
        this.close();
    }//GEN-LAST:event_formInternalFrameClosing


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToggleButton botonPlay;
    private javax.swing.JToggleButton botonStop;
    private javax.swing.JPanel panel_botones;
    // End of variables declaration//GEN-END:variables
}

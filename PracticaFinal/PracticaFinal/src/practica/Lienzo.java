
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica;

import Formas.Curva;
import Formas.Elipse;
import Formas.Forma;
import Formas.Linea;
import Formas.Rectangulo;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.QuadCurve2D;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class Lienzo extends javax.swing.JPanel {

    private ArrayList<Forma> vFormas = new ArrayList();
    Forma for_seleccionada = null;
    Point2D.Double Dxy = new Point2D.Double(0, 0);
    private Point2D.Double pClic = new Point2D.Double(-1000, -10000);
    private Point2D.Double pIni = new Point2D.Double(-1000, -1000);
    private Point2D.Double pFin = new Point2D.Double(-1000, -10000);
    private Point2D.Double pControl = new Point2D.Double(-1000, -10000);
    private Color color = Color.BLACK;
    private int id_forma = 0;
    private boolean seleccionar = false;
    VentanaPrincipal mi_ventana_principal;
    Imagen imagen;
    UmbralizacionOp umbralizador = new UmbralizacionOp();
    boolean pintar_curva = false;
    boolean terminada_curva = false;
    Curva curva_aux;

    public UmbralizacionOp getUmbral() {
        return this.umbralizador;
    }

    public Lienzo() {
        initComponents();
        vFormas.add(new Linea(0, 0, 0, 0));
    }

    public void CrearImagen(BufferedImage imagen) {
        this.imagen = new Imagen(imagen, imagen, this);
    }

    public Imagen getImagen() {
        return this.imagen;
    }

    public void setMi_Ventana_Principal(VentanaPrincipal mi_ventana_principal) {
        this.mi_ventana_principal = mi_ventana_principal;
    }

    private boolean isNear(Line2D line, Point2D p) {
        return line.ptLineDist(p) <= 2.0;

    }

    void ActualizarVentanaPrincipal() {
        if (this.for_seleccionada != null) {
            this.mi_ventana_principal.getIndicadorGrosor().setValue(
                    this.for_seleccionada.getGrosor());
            this.mi_ventana_principal.getBotonSeleccionar().setSelected(this.getSelecionar());
            if (this.for_seleccionada instanceof Rectangulo) {
                this.mi_ventana_principal.getBotonRelleno().setSelected(((Rectangulo) this.for_seleccionada).getRelleno());
                this.mi_ventana_principal.getBotonTransparencia().setSelected(((Rectangulo) this.for_seleccionada).getTransparencia());
            }
            if (this.for_seleccionada instanceof Elipse) {
                this.mi_ventana_principal.getBotonRelleno().setSelected(((Elipse) this.for_seleccionada).getRelleno());
                this.mi_ventana_principal.getBotonTransparencia().setSelected(((Elipse) this.for_seleccionada).getTransparencia());
            }
        }
    }

    public Forma getFormaSeleccionda() {
        return this.for_seleccionada;
    }

    private void getSelectedShape(Point2D p) {
        boolean salir = false;
        for_seleccionada = null;

        for (Forma forma : vFormas) {
            if (forma.getFigura() instanceof Line2D.Double) {
                if (isNear((Line2D) forma.getFigura(), p)) {
                    for_seleccionada = forma;
                    salir = true;
                    this.ActualizarVentanaPrincipal();
                }
            } else if (forma.getFigura().contains(p)) {
                for_seleccionada = forma;
                this.ActualizarVentanaPrincipal();
                salir = true;
            }
        }
    }

    public ArrayList<Forma> getFormas() {
        return this.vFormas;
    }

    private void setLocation(Forma forma, double x, double y) {
        Point2D.Double pos = new Point2D.Double();
        pos.x = x;
        pos.y = y;
        if (this.for_seleccionada != null) {
            if (this.for_seleccionada.getFigura() instanceof Line2D.Double) {
                ((Linea) this.for_seleccionada).setLocation(x, y);
            } else if (this.for_seleccionada.getFigura() instanceof Rectangle2D.Double) {
                ((Rectangulo) this.for_seleccionada).setLocation(x, y);
            } else if (this.for_seleccionada.getFigura() instanceof Ellipse2D) {
                ((Elipse) this.for_seleccionada).setLocation(x, y);
            } else if (this.for_seleccionada instanceof Curva) {
                ((Curva) this.for_seleccionada).setLocation(x, y);
            }
        }
        this.repaint();
    }

    void CreateShape(boolean relased) {

        if (this.getForma() == 2 || (this.getForma() == 6 && !terminada_curva)) {
            Linea linea = new Linea(this.getPuntoInicio().x, this.getPuntoInicio().y,
                    this.getPuntoFin().x, this.getPuntoFin().y);

            vFormas.set(vFormas.size() - 1, linea);
        } else if (this.getForma() == 3 || this.getForma() == 5) {
            Rectangulo rectangulo = new Rectangulo(0.0, 0.0, 0.0, 0.0);
            rectangulo = new Rectangulo(rectangulo.Punto_Referencia(getPuntoInicio(),
                    this.getPuntoFin()).x,
                    rectangulo.Punto_Referencia(getPuntoInicio(),
                            this.getPuntoFin()).y,
                    (double) Math.abs((this.getPuntoInicio().x - this.getPuntoFin().x)),
                    (double) Math.abs(this.getPuntoInicio().y - this.getPuntoFin().y));
            if (this.getForma() == 5) {
                rectangulo.setRedondeado(true);
            }
            vFormas.set(vFormas.size() - 1, rectangulo);
            this.for_seleccionada = vFormas.get(vFormas.size() - 1);
        } else if (this.getForma() == 4) {
            Elipse elipse = new Elipse(0.0, 0.0, 0.0, 0.0);
            elipse = new Elipse(elipse.Punto_Referencia(getPuntoInicio(),
                    this.getPuntoFin()).x,
                    elipse.Punto_Referencia(getPuntoInicio(),
                            this.getPuntoFin()).y,
                    (double) Math.abs((this.getPuntoInicio().x - this.getPuntoFin().x)),
                    (double) Math.abs(this.getPuntoInicio().y - this.getPuntoFin().y));
            vFormas.set(vFormas.size() - 1, elipse);
            this.for_seleccionada = vFormas.get(vFormas.size() - 1);

        } else if (this.getForma() == 6 && this.terminada_curva) {
            System.out.println("Vamos a terminar curva");
            QuadCurve2D q = new QuadCurve2D.Double();
            q.setCurve(this.pIni.x,
                    this.pIni.y,
                    this.pControl.x,
                    this.pControl.y,
                    this.pFin.x,
                    this.pFin.y);
            Curva curva = new Curva(q.getX1(), q.getY1(), q.getCtrlX(), q.getCtrlY(), q.getX2(), q.getY2());
            vFormas.set(vFormas.size() - 1, curva);
            this.for_seleccionada = vFormas.get(vFormas.size() - 1);
        }
        this.ActualizarVentanaPrincipal();

        if (relased) {
            if (this.pintar_curva && !this.terminada_curva) {
                this.terminada_curva = true;
            } else {
                this.setForma(this.getForma());
                this.ActualizarVentanaPrincipal();
                this.terminada_curva=false;
            }
        }
        this.repaint();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setBackground(java.awt.Color.white);
        addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                formMousePressed(evt);
            }
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                formMouseReleased(evt);
            }
        });
        addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseDragged(java.awt.event.MouseEvent evt) {
                formMouseDragged(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    private void formMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMousePressed

        if (!this.getSelecionar()) {
            if (this.terminada_curva) {
                this.pControl.x = evt.getPoint().x;
                this.pControl.y = evt.getPoint().y;
                this.CreateShape(false);
            } else {
                this.setPuntoInicio(evt.getPoint().x, evt.getPoint().y);
                this.CreateShape(false);
            }
        } else {
            this.setPuntoInicio(evt.getPoint().x, evt.getPoint().y);
            this.getSelectedShape(evt.getPoint());
            if (for_seleccionada != null) {
                double x = 0, y = 0;

                if (for_seleccionada.getFigura() instanceof Line2D.Double) {
                    x = ((Line2D.Double) for_seleccionada.getFigura()).x1;
                    y = ((Line2D.Double) for_seleccionada.getFigura()).y1;
                } else if (for_seleccionada.getFigura() instanceof Rectangle2D.Double) {
                    x = ((Rectangle2D.Double) for_seleccionada.getFigura()).x;
                    y = ((Rectangle2D.Double) for_seleccionada.getFigura()).y;
                } else if (for_seleccionada.getFigura() instanceof Ellipse2D.Double) {
                    x = ((Ellipse2D.Double) for_seleccionada.getFigura()).x;
                    y = ((Ellipse2D.Double) for_seleccionada.getFigura()).y;
                } else if (for_seleccionada.getFigura() instanceof QuadCurve2D) {
                    x = ((QuadCurve2D) for_seleccionada.getFigura()).getX1();
                    y = ((QuadCurve2D) for_seleccionada.getFigura()).getY1();
                }

                this.Dxy.x = x - evt.getPoint().x;
                this.Dxy.y = y - evt.getPoint().y;
                this.setLocation(for_seleccionada, evt.getPoint().x + this.Dxy.x,
                        evt.getPoint().y + this.Dxy.y);
            } else {
                System.out.println("No se ha localizado forma");
            }
        }
    }//GEN-LAST:event_formMousePressed

    private void formMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseReleased

        if (!this.getSelecionar()) {
            if (this.terminada_curva) {
                this.pControl.x = evt.getPoint().x;
                this.pControl.y = evt.getPoint().y;
                this.CreateShape(true);
            } else {
                this.setPuntoFin(evt.getPoint().x, evt.getPoint().y);
                this.CreateShape(true);
            }
        } else {
            this.setLocation(for_seleccionada, evt.getPoint().x + this.Dxy.x, evt.getPoint().y + this.Dxy.y);
        }
    }//GEN-LAST:event_formMouseReleased

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        if (!this.getSelecionar()) {
            if (this.terminada_curva) {
                this.pControl.x = evt.getPoint().x;
                this.pControl.y = evt.getPoint().y;
                this.CreateShape(false);
            } else {
                this.setPuntoFin(evt.getPoint().x, evt.getPoint().y);
                this.CreateShape(false);
            }
        } else {
            this.setLocation(for_seleccionada, evt.getPoint().x + this.Dxy.x, evt.getPoint().y + this.Dxy.y);
        }
    }//GEN-LAST:event_formMouseDragged

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Paint p = new Color(255, 100, 0);
        Graphics2D g2d = (Graphics2D) g;
        if (imagen != null) {
            if (imagen.getImagenTemporal() != null) {
                System.out.println("Hay imagen temporal");
                g2d.drawImage(imagen.getImagenTemporal(), 0, 0, this);
            } else if (imagen.getImagen() != null) {
                System.out.println("Hay imagen original");
                g2d.drawImage(imagen.getImagen(), 0, 0, this);

            }
        }
        for (Forma forma : vFormas) {
            if (forma.getGradienteHorizontal() || forma.getGradienteVertical()) {
                if (forma.getFigura() instanceof Rectangle2D.Double || forma.getFigura() instanceof Ellipse2D.Double) {
                    if (forma.getGradienteVertical()) {
                        if (forma.getColorGradiente1() != null && forma.getColorGradiente2() != null) {
                            GradientPaint horizontalGradient;
                            float x = forma.getFigura().getBounds().x;
                            float y = forma.getFigura().getBounds().y;
                            float witdh = forma.getFigura().getBounds().width;
                            horizontalGradient = new GradientPaint(x, y, forma.getColorGradiente1(), witdh, 0, forma.getColorGradiente2());
                            g2d.setPaint(horizontalGradient);
                        }
                    }
                    if (forma.getGradienteHorizontal()) {
                        if (forma.getColorGradiente1() != null && forma.getColorGradiente2() != null) {
                            float x = forma.getFigura().getBounds().x;
                            float y = forma.getFigura().getBounds().y;
                            float height = forma.getFigura().getBounds().height;
                            GradientPaint verticalGradient = new GradientPaint(x, y, forma.getColorGradiente1(), 0, height, forma.getColorGradiente2());
                            g2d.setPaint(verticalGradient);
                        }
                    }
                    if (forma.getGradienteDiagonal()) {
                        if (forma.getColorGradiente1() != null && forma.getColorGradiente2() != null) {
                            GradientPaint horizontalGradient;
                            float x = forma.getFigura().getBounds().x;
                            float y = forma.getFigura().getBounds().y;
                            float width = forma.getFigura().getBounds().width;
                            float height = forma.getFigura().getBounds().height;
                            GradientPaint diagonalGradient = new GradientPaint(0, 0, forma.getColorGradiente1(), width / 2,
                                    height / 2, forma.getColorGradiente2());
                            g2d.setPaint(diagonalGradient);
                        }
                    }
                }
            } else {
                g2d.setPaint(forma.getColor());
                g2d.setColor(forma.getColor());
            }
            if (!forma.getDiscontinuo()) {
                BasicStroke stroke = new BasicStroke(
                        forma.getGrosor(), // grosor: 10 píxels
                        BasicStroke.CAP_BUTT, // terminación: recta
                        BasicStroke.JOIN_ROUND, // unión: redondeada 
                        1f, // ángulo: 1 grado
                        new float[]{10, 5, 5, 5}, // línea de 10, 5 blancos, línea de 5, 5 blancos
                        2 // fase
                );
                g2d.setStroke(stroke);
            } else {
                BasicStroke stroke = new BasicStroke(
                        forma.getGrosor(), // grosor: 10 píxels
                        BasicStroke.CAP_BUTT, // terminación: recta
                        BasicStroke.JOIN_ROUND, // unión: redondeada 
                        1f, // ángulo: 1 grado
                        new float[]{10, 0, 0, 0}, // línea de 10, 5 blancos, línea de 5, 5 blancos
                        2 // fase
                );
                g2d.setStroke(stroke);
            }

            if (forma instanceof Rectangulo) {
                if (((Rectangulo) forma).getRelleno()) {
                    g2d.fill(forma.getFigura());
                }
            }
            if (forma instanceof Elipse) {
                if (((Elipse) forma).getRelleno()) {
                    g2d.fill(forma.getFigura());
                }
            }

            if (forma instanceof Rectangulo && ((Rectangulo) forma).getRedondeado()) {
                g2d.drawRoundRect(forma.getFigura().getBounds().x, forma.getFigura().getBounds().y, forma.getFigura().getBounds().width,
                        forma.getFigura().getBounds().height, (forma.getFigura().getBounds().width
                        + forma.getFigura().getBounds().height) / 4, (forma.getFigura().getBounds().width
                        + forma.getFigura().getBounds().height) / 4);
            } else {
                g2d.draw(forma.getFigura());
            }
        }

    }

    public void setForma(int forma) {
        this.id_forma = forma;

        if (id_forma == 2) {
            this.vFormas.add(new Linea(0.0, 0.0, 0.0, 0.0));
            pintar_curva=false;
        } else if (id_forma == 3) {
            this.vFormas.add(new Rectangulo(0.0, 0.0, 0.0, 0.0));
            pintar_curva=false;
        } else if (id_forma == 4) {
            this.vFormas.add(new Elipse(0.0, 0.0, 0.0, 0.0));
            pintar_curva=false;
        } else if (id_forma == 5) {
            this.vFormas.add(new Rectangulo(0.0, 0.0, 0.0, 0.0));
            pintar_curva=false;
        } else if ((id_forma == 6)) {
            System.out.println("Añadimos una curva");
            this.vFormas.add(new Curva(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
            pintar_curva = true;
        }

    }

    public int getForma() {
        return this.id_forma;
    }

    public void setPuntoInicio(double x, double y) {
        this.pIni.x = x;
        this.pIni.y = y;
    }

    public Point2D.Double getPuntoInicio() {

        return this.pIni;
    }

    public void setPuntoFin(double x, double y) {
        this.pFin.x = x;
        this.pFin.y = y;
    }

    public Point2D.Double getPuntoFin() {
        return this.pFin;
    }

    public void setSelecionar(boolean seleccionar) {
        this.seleccionar = seleccionar;
    }

    public boolean getSelecionar() {
        return this.seleccionar;
    }

}


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables

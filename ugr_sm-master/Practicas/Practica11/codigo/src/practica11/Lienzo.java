/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica11;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RectangularShape;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

/**
 *
 * @author Jesús Ángel González Novez
 */
public class Lienzo extends javax.swing.JPanel {

    final static int PUNTO = 0;
    final static int LINEA = 1;
    final static int RECTANGULO = 2;
    final static int ELIPSE = 3;
    final static int NUEVO = 4;
    //Variables privadas
    private Color color;
    private static int forma;
    private Point2D p;
    private Stroke stroke;
    private Shape s;
    private final ArrayList<Shape> vShape;
    boolean relleno, editar;
    private final Point2D dXY;
    private BufferedImage img;
    private BufferedImage imgDest;

    /**
     * Creates new form NewJPanel
     */
    public Lienzo() {
        initComponents();

        stroke = new BasicStroke(1.0f);
        vShape = new ArrayList();
        color = new Color(0, 0, 0);
        editar = false;
        relleno = false;
        dXY = new Point(0, 0);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        if(imgDest!=null) g2d.drawImage(imgDest,0,0, this);
        g2d.setPaint(color);
        g2d.setStroke(stroke);
        for (Shape s : vShape) {
            if (relleno) {
                g2d.fill(s);
            }
            g2d.draw(s);
        }
    }

    private Shape createShape(Point2D p1, Point2D p2) {
        if (p1 == null || (p2 == null && forma != PUNTO)) {
            return null;
        }

        switch (forma) {
            case PUNTO:
                return s = new Line2D.Double(p1, p1);
            case LINEA:
                return s = new Line2D.Double(p1, p1);
            case RECTANGULO:
                s = new Rectangle2D.Double();
                ((RectangularShape) s).setFrameFromDiagonal(p1, p1);
                return s;
            case ELIPSE:
                s = new Ellipse2D.Double();
                ((Ellipse2D) s).setFrameFromDiagonal(p1, p1);
                return s;
            default:
                return s = null;
        }
    }

    private void updateShape(Point2D p1, Point2D p2) {
        if (s instanceof Line2D) {
            ((Line2D) s).setLine(p1, p2);
        } else if (s instanceof RectangularShape) {
            ((RectangularShape) s).setFrameFromDiagonal(p1, p2);
        }
    }

    private Shape getSelectedShape(Point2D p) {
        //Puedo recorrer el vector normal, porque inserto los elementos al estilo FIFO en un ArrayList
        for (Shape s : vShape) {
            if (contains((Shape) s, p)) {
                return s;
            }
        }
        return null;
    }

    public boolean contains(Shape sh, Point2D p) {
        if (sh instanceof Line2D) {
            return isNear((Line2D) sh, p);
        } else {
            return sh.contains(p);
        }
    }

    public void setLocation(Shape s, Point2D p) {
        if (s instanceof Line2D) {
            double dx = p.getX() - ((Line2D) s).getX1();
            double dy = p.getY() - ((Line2D) s).getY1();
            Point2D newP = new Point2D.Double(((Line2D) s).getX2() + dx, ((Line2D) s).getY2() + dy);
            ((Line2D) s).setLine(p, newP);
        } else if (s instanceof RectangularShape) {
            RectangularShape r = (RectangularShape) s;
            r.setFrame(p, new Dimension((int) r.getWidth(), (int) r.getHeight()));
        }
    }

    private boolean isNear(Line2D line, Point2D p) {
        if (line.getP1().equals(line.getP2())) {
            return line.getP1().distance(p) <= 3.0;
        } else {
            return line.ptLineDist(p) <= 3.0;
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

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
        p = evt.getPoint();
        if (!editar) {
            vShape.add(0, createShape(p, p));
        } else {
            s = getSelectedShape(evt.getPoint());
            if (s != null) {
                double x = (s instanceof Line2D) ? ((Line2D) s).getX1() : s.getBounds2D().getX();
                double y = (s instanceof Line2D) ? ((Line2D) s).getY1() : s.getBounds2D().getY();
                dXY.setLocation(x - p.getX(), y - p.getY());
            }
        }
    }//GEN-LAST:event_formMousePressed

    private void formMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseReleased
        formMouseDragged(evt);
    }//GEN-LAST:event_formMouseReleased

    private void formMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseDragged
        Point pEvt = evt.getPoint();

        if (!editar) {
            if (forma != Lienzo.PUNTO) {
                updateShape(p, evt.getPoint());
            }
        } else {
            setLocation(s, new Point2D.Double(pEvt.getX() + dXY.getX(), pEvt.getY() + dXY.getY()));
        }
        this.repaint();
    }//GEN-LAST:event_formMouseDragged

    public void setColor(Color color) {
        this.color = color;
        this.repaint();
    }

    public Color getColor() {
        return color;
    }

    public static int getForma() {
        return Lienzo.forma;
    }

    public static void setForma(int forma) {
        Lienzo.forma = forma;
    }

    public Point2D getP() {
        return p;
    }

    public void setP(Point p) {
        this.p = p;
    }

    public boolean isRelleno() {
        return relleno;
    }

    public void setRelleno(boolean relleno) {
        this.relleno = relleno;
        repaint();
    }

    public boolean isEditar() {
        return editar;
    }

    public void setEditar(boolean editar) {
        this.editar = editar;
    }

    public Stroke getStroke() {
        return stroke;
    }

    public void setStroke(Stroke sk) {
        this.stroke = sk;
        repaint();
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables

    void setImageOriginal(BufferedImage img) {
        if(img!=null){
            setPreferredSize(new Dimension(img.getWidth(),img.getHeight()));
            this.img = img;
            setImageActual(img);
        }
    }
    
    public BufferedImage getImageOriginal(){
        return this.img;
    }
    
    public BufferedImage volcado(BufferedImage img){
        Graphics2D g=img.createGraphics();
        g.setColor(color);
        g.setStroke(stroke);
        for (Shape s : vShape) {
            if (relleno) {
                g.fill(s);
            }
            g.draw(s);
        }
        return img;
    }
    
    void setImageActual(BufferedImage imgDest) {
        setPreferredSize(new Dimension(img.getWidth(),img.getHeight()));
        this.imgDest = imgDest;
    }
    
    public BufferedImage getImageActual(){
        return this.imgDest;
    }
    
}
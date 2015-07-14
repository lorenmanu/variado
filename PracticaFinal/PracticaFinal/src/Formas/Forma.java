package Formas;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Shape;
import java.awt.geom.Point2D;

public abstract class Forma {

    private boolean transparencia = false;
    protected BasicStroke trazo;
    protected Color color, color_gradiente1 = null, color_gradiente2 = null;
    protected Color fondo;
    protected Boolean relleno;
    protected Shape la_figura;
    private int grosor = 1;
    boolean discontinuo = false;
    boolean gradienteHorizontal = false;
    boolean gradienteVertical = false;
    boolean gradienteDiagonal = false;

    public void setColorGradiente(Color color1, Color color2) {
        this.color_gradiente1 = color1;
        this.color_gradiente2 = color2;
    }

    public Color getColorGradiente1() {
        return this.color_gradiente1;
    }

    public Color getColorGradiente2() {
        return this.color_gradiente2;
    }

    public void setGradienteHorizontal(boolean gradiente) {
        this.gradienteHorizontal = gradiente;
    }

    public void setGradienteVertical(boolean gradiente) {
        this.gradienteVertical = gradiente;
    }

    public void setGradienteDiagonal(boolean gradiente) {
        this.gradienteDiagonal = gradiente;
    }

    public boolean getGradienteDiagonal() {
        return this.gradienteDiagonal;
    }

    public boolean getGradienteHorizontal() {
        return this.gradienteHorizontal;
    }

    public boolean getGradienteVertical() {
        return this.gradienteVertical;
    }

    public void set_discontinuo(boolean discontinuo) {
        this.discontinuo = discontinuo;
    }

    public boolean getDiscontinuo() {
        return this.discontinuo;
    }

    public Forma() {
        color = new Color(0, 0, 0);
        fondo = Color.red;
        relleno = false;
    }

    public Shape getFigura() {
        return this.la_figura;
    }

    public void setFigura(Shape figura) {
        this.la_figura = figura;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public Color getColor() {
        return this.color;
    }

    public void set(BasicStroke trazo) {
        this.trazo = trazo;
    }

    public Point2D.Double Punto_Referencia(Point2D.Double p1, Point2D.Double p2) {
        Point2D.Double punto_referencia = new Point2D.Double(-1000, -100000);

        if (p1.x > p2.x) {
            punto_referencia.x = p2.x;
        } else if (p1.x < p2.x || p1.x == p2.x) {
            punto_referencia.x = p1.x;
        }

        if (p1.y > p2.y) {
            punto_referencia.y = p2.y;
        } else if (p1.y < p2.y || p1.y == p2.y) {
            punto_referencia.y = p1.y;
        }

        return punto_referencia;
    }

    public void setGrosor(int grosor) {
        this.grosor = grosor;
    }

    public int getGrosor() {
        return this.grosor;
    }

}

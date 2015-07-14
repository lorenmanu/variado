package Formas;

import java.awt.Color;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

public class Rectangulo extends Forma {

    private boolean relleno = false;
    private boolean transparencia = false;
    Color color_antiguo = null;
    boolean redondeado = false;

    public void setRedondeado(boolean redondo) {
        this.redondeado = redondo;
    }

    public boolean getRedondeado() {
        return this.redondeado;
    }

    public Rectangulo() {
        super();
        la_figura = new Rectangle2D.Double(0, 0, 0, 0);
    }

    public Rectangulo(Double x, Double y, Double w, Double h) {
        super();
        la_figura = new Rectangle2D.Double(x, y, w, h);
    }

    public void setLocation(double x, double y) {
        Point2D.Double pos = new Point2D.Double();
        pos.x = x;
        pos.y = y;

        double dx = pos.getX() - ((Rectangle2D.Double) la_figura).getX();
        double dy = pos.getY() - ((Rectangle2D.Double) la_figura).getY();
        Point2D newp2 = new Point2D.Double(((Rectangle2D.Double) la_figura).getX() + dx,
                ((Rectangle2D.Double) la_figura).getY() + dy);
        ((Rectangle2D.Double) la_figura).setRect(newp2.getX(), newp2.getY(),
                ((Rectangle2D.Double) la_figura).width, ((Rectangle2D.Double) la_figura).height);
    }

    public void setRelleno(boolean relleno) {
        this.relleno = relleno;
    }

    public boolean getRelleno() {
        return this.relleno;
    }

    public void setTransparencia(boolean transparencia) {
        this.transparencia = transparencia;
    }

    public boolean getTransparencia() {
        return this.transparencia;
    }

    public void aplicarTransparencia() {
        if (getTransparencia()) {
            color_antiguo = color;
            float a = (50 / 100.0f);
            Color b = new Color(this.getColor().getRed() / 255f, this.getColor().getGreen() / 255f, this.getColor().getBlue() / 255f, a);
            setColor(b);
        } else if (color_antiguo != null) {
            setColor(color_antiguo);
        }
    }

}

package Formas;

import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

public class Linea extends Forma {

    public Linea() {
        super();
        la_figura = new Line2D.Double(0, 0, 0, 0);
    }

    public Linea(double x1, double x2, double y1, double y2) {
        super();
        la_figura = new Line2D.Double(x1, x2, y1, y2);
    }

    public void setLocation(double x, double y) {
        Point2D.Double pos = new Point2D.Double();
        pos.x=x;
        pos.y=y;
        
        double dx = pos.getX() - ((Line2D.Double) la_figura).getX1();
        double dy = pos.getY() - ((Line2D.Double) la_figura).getY1();
        Point2D newp2 = new Point2D.Double(((Line2D.Double) la_figura).getX2() + dx,
                ((Line2D.Double) la_figura).getY2() + dy);
        ((Line2D.Double) la_figura).setLine(pos, newp2);
    }

}

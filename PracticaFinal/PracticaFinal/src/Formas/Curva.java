package Formas;

import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.QuadCurve2D;

public class Curva extends Forma {

    Point2D punto_control=new Point2D.Double(0, 0);

    public Curva() {
        super();
        la_figura = new Line2D.Double(0, 0, 0, 0);
    }


    public Curva(double x1, double y1, double x2, double y2, double x3, double y3) {
        super();

            QuadCurve2D q = new QuadCurve2D.Double();
            q.setCurve(x1, y1, x2, y2, x3, y3);
            this.la_figura=q;
    }

    public void setLocation(double x, double y) {
        Point2D.Double pos = new Point2D.Double();
        pos.x = x;
        pos.y = y;

        QuadCurve2D.Double q = (QuadCurve2D.Double) this.la_figura;
        double dx = pos.getX() - q.getX1();
        double dy = pos.getY() - q.getY1();
        q.setCurve(pos.x, pos.y, q.ctrlx + dx, q.ctrly + dy, q.x2 + dx, q.y2 + dy);
        this.la_figura=q;
    }

}

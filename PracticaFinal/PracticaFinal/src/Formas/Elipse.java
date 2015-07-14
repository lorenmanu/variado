package Formas;

import java.awt.Color;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

public class Elipse extends Forma{
    private boolean relleno = false;
    private boolean transparencia=false;
    Color color_antiguo=null;
    
        
    public Elipse(){
        super();
        la_figura = new Ellipse2D.Double(0,0,0,0);
    }

    public Elipse(Double x,Double y, Double w, Double h){
        super();
        la_figura = new Ellipse2D.Double(x,y,w,h);
    }
    
    public void setLocation(double x,double y){
        Point2D.Double pos = new Point2D.Double();
        pos.x=x;
        pos.y=y;
        
        double dx = pos.getX() - ((Ellipse2D.Double) la_figura).getX();
        double dy = pos.getY() - ((Ellipse2D.Double) la_figura).getY();
        Point2D newp2 = new Point2D.Double(((Ellipse2D.Double) la_figura).getX() + dx,
                ((Ellipse2D.Double) la_figura).getY() + dy);
        ((Ellipse2D.Double) la_figura).setFrame(newp2.getX(), newp2.getY(),
                ((Ellipse2D.Double) la_figura).width, ((Ellipse2D.Double) la_figura).height);
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
        if(getTransparencia()){
            color_antiguo=color;
            float a = (50 / 100.0f);
            Color b = new Color(this.getColor().getRed() / 255f, this.getColor().getGreen() / 255f, this.getColor().getBlue() / 255f, a);
            setColor(b);
        }
        else if(color_antiguo!=null){
            setColor(color_antiguo);
        }
    }
}

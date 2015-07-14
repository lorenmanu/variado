/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica;

import Formas.Elipse;
import Formas.Forma;
import Formas.Rectangulo;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.color.ColorSpace;
import java.awt.color.ICC_ColorSpace;
import java.awt.color.ICC_Profile;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.awt.image.ColorConvertOp;
import java.awt.image.ConvolveOp;
import java.awt.image.Kernel;
import java.awt.image.LookupOp;
import java.awt.image.RescaleOp;
import java.util.ArrayList;

/**
 *
 * @author javier
 */
public class Imagen {

    private BufferedImage imagen = null;
    private BufferedImage imagen_temporal = null;
    Kernel_Mascara kernel_mascara;
    private static short ltN[], ltL[], ltG[], ltC[];
    private double escala = 1;
    private UmbralizacionOp umbralizador = new UmbralizacionOp();
    private SobelOp calculo_bordes = new SobelOp();
    Lienzo mi_lienzo;

    public class UmbralizacionOp {

        private int umbral;

        public UmbralizacionOp() {
            this.umbral = 0;
        }

        public void setUmbral(int umbral) {
            this.umbral = umbral;
        }

        public int getUmbral() {
            return this.umbral;
        }

        public BufferedImage filter(BufferedImage src) {
            BufferedImage bn = new BufferedImage(src.getWidth(), src.getHeight(), BufferedImage.TYPE_BYTE_BINARY);
            //se traspasan los colores Pixel a Pixel
            for (int i = 0; i < src.getWidth(); i++) {
                for (int j = 0; j < src.getHeight(); j++) {
                    int r, g, b;
                    Color color;

                    color = new Color(src.getRGB(i, j));
                    //se extraen los valores RGB
                    r = color.getRed();
                    g = color.getGreen();
                    b = color.getBlue();
                    //dependiendo del valor del umbral, se van separando los
                    // valores RGB a 0 y 255  
                    r = (r > umbral) ? 255 : 0;
                    g = (g > umbral) ? 255 : 0;
                    b = (b > umbral) ? 255 : 0;
                    bn.setRGB(i, j, new Color(r, g, b).getRGB());
                }
            }
            return bn;
        }
    }

    public class SobelOp {

        public SobelOp() {

        }

        String title = null;
        int sobel_x[][] = {{-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}};

        int sobel_y[][] = {{-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}};

        int pixel_x;
        int pixel_y;

        public BufferedImage DeteccionDeBordes(BufferedImage ip) {
            int w = ip.getWidth();
            int h = ip.getHeight();
            BufferedImage copy = new BufferedImage(ip.getWidth(), ip.getHeight(), BufferedImage.TYPE_BYTE_GRAY);;

            for (int x = 1; x < w - 1; x++) {
                for (int y = 1; y < h - 1; y++) {
                    pixel_x = 1 / 6 * (sobel_x[0][0] * ip.getRGB(x - 1, y - 1)) + (sobel_x[0][1] * ip.getRGB(x, y - 1)) + (sobel_x[0][2] * ip.getRGB(x + 1, y - 1))
                            + (sobel_x[1][0] * ip.getRGB(x - 1, y)) + (sobel_x[1][1] * ip.getRGB(x, y)) + (sobel_x[1][2] * ip.getRGB(x + 1, y))
                            + (sobel_x[2][0] * ip.getRGB(x - 1, y + 1)) + (sobel_x[2][1] * ip.getRGB(x, y + 1)) + (sobel_x[2][2] * ip.getRGB(x + 1, y + 1));
                    pixel_y = 1 / 6 * (sobel_y[0][0] * ip.getRGB(x - 1, y - 1)) + (sobel_y[0][1] * ip.getRGB(x, y - 1)) + (sobel_y[0][2] * ip.getRGB(x + 1, y - 1))
                            + (sobel_y[1][0] * ip.getRGB(x - 1, y)) + (sobel_y[1][1] * ip.getRGB(x, y)) + (sobel_y[1][2] * ip.getRGB(x + 1, y))
                            + (sobel_y[2][0] * ip.getRGB(x - 1, y + 1)) + (sobel_y[2][1] * ip.getRGB(x, y + 1)) + (sobel_x[2][2] * ip.getRGB(x + 1, y + 1));

                    int val = (int) Math.sqrt((pixel_x * pixel_x) + (pixel_y * pixel_y));
                    copy.setRGB(x, y, val);

                }
            }
            return copy;
        }
    }

    Imagen(BufferedImage imagen, BufferedImage imagen_temporal, Lienzo mi_lienzo) {
        this.imagen = imagen;
        this.imagen_temporal = imagen_temporal;
        this.mi_lienzo = mi_lienzo;
    }

    public SobelOp getSobelOp() {
        return this.calculo_bordes;
    }

    public void setUmbralizador() {
        this.umbralizador = umbralizador;
    }

    public UmbralizacionOp getUmbralizador() {
        return this.umbralizador;
    }

    public void setEscala(double escala) {
        this.escala = escala;
    }

    public double getEscala() {
        return this.escala;
    }

    public void guardarImagen(ArrayList<Forma> vFormas) {
       if (this.imagen_temporal != null || this.imagen != null) {
            Graphics2D g2d=null;
            if (this.imagen_temporal != null) {
                g2d = this.imagen_temporal.createGraphics();
            } else if (this.imagen != null) {
                g2d = this.imagen.createGraphics();
            }
            if (g2d != null) {
                for (Forma forma : vFormas) {
                    g2d.setPaint(forma.getColor());
                    g2d.setColor(forma.getColor());

                    Stroke sk = new BasicStroke(forma.getGrosor());
                    g2d.setStroke(sk);
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
                    g2d.draw(forma.getFigura());
                }
            }
        }
    }

    public void setImagen(BufferedImage imagen) {
        this.imagen = imagen;
    }

    public BufferedImage getImagen() {
        return this.imagen;
    }

    public void setImagenTemporal(BufferedImage imagen_temporal) {
        this.imagen_temporal = imagen_temporal;
    }

    public BufferedImage getImagenTemporal() {
        return this.imagen_temporal;
    }

    public void setBrillo(float aumento) {

        if (this.imagen != null) {
            RescaleOp rop = new RescaleOp(1.0F, aumento, null);
            if (this.imagen_temporal == null && this.imagen != null) {
                this.imagen_temporal = this.imagen;
                this.imagen_temporal = rop.filter(this.imagen, null);
            }
            if (this.imagen_temporal != null) {
                this.imagen_temporal = rop.filter(this.imagen, null);
            }
            this.mi_lienzo.repaint();
        }

    }

    public void setConvolucion(int tipo) {
        Kernel kernel = kernel_mascara.createKernel(tipo);
        BufferedImage imgSource=null;

        if (this.imagen_temporal != null) {
            System.out.println("Coge temporal");
            imgSource = this.imagen_temporal;
        }
        else if(this.imagen != null) {
            System.out.println("No coge temporal");
            imgSource = this.imagen;
        }

        if (imgSource!=null) {
            if (imgSource != null) {
                try {
                    ConvolveOp cop = new ConvolveOp(kernel);
                    BufferedImage imgOut = cop.filter(imgSource, null);
                    this.setImagenTemporal(imgOut);
                    this.mi_lienzo.repaint();
                } catch (IllegalArgumentException e) {
                    System.err.println(e.getLocalizedMessage());
                }
            }
        }

    }

    BufferedImage convertImageType(BufferedImage img, int type) {
        if (img == null) {
            return null;
        }
        BufferedImage imgOut = new BufferedImage(img.getWidth(), img.getHeight(), type);
        Graphics2D g2d = imgOut.createGraphics();
        g2d.drawImage(img, 0, 0, null);
        return imgOut;
    }

    public void setLookUpOp(int func) {
        int tipo = func;
        BufferedImage imgSource=null;

        if (this.imagen_temporal != null) {
            System.out.println("Coge temporal");
            imgSource = this.imagen_temporal;
        }
        else if(this.imagen != null) {
            System.out.println("No coge temporal");
            imgSource = this.imagen;
        }

        if(imgSource!=null){
            imgSource = convertImageType(imgSource, BufferedImage.TYPE_INT_RGB);
            LookupOp lop = new LookupOp(practica.LookupTableProducer.createLookupTable(tipo), null);
            BufferedImage imgdest = lop.filter(imgSource, null);
            this.setImagenTemporal(imgdest);
            this.mi_lienzo.repaint();
        }
    }

    public void toBYN() {
        ICC_Profile ip = ICC_Profile.getInstance(ColorSpace.CS_GRAY);
        ColorSpace cs = new ICC_ColorSpace(ip);
        ColorConvertOp ccop = new ColorConvertOp(cs, null);

        if (this.imagen != null) {
            this.imagen_temporal = ccop.filter(this.imagen, null);
        }

        this.mi_lienzo.repaint();
    }

    public void setAffineTransform(int tranformacion, float a, float b) {
        AffineTransform at = null;
        switch (tranformacion) {
            case 0:
                at = AffineTransform.getScaleInstance(a, b);
                break;
            case 1:
                at = AffineTransform.getRotateInstance(Math.toRadians(a), this.imagen_temporal.getWidth() / 2, this.imagen_temporal.getHeight() / 2);
                break;
            case 2:
                at = AffineTransform.getShearInstance(a, b);
                break;
            case 3:
                at = AffineTransform.getTranslateInstance(a, b);
                break;
        }
        AffineTransformOp atop = new AffineTransformOp(at, AffineTransformOp.TYPE_BILINEAR);

        if (this.imagen != null) {
            this.imagen_temporal = atop.filter(this.imagen, null);
        }
        this.mi_lienzo.repaint();
    }

}

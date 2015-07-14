/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import sm.image.BufferedImageOpAdapter;
import sm.image.BufferedImagePixelIterator;
import sm.image.BufferedImageSampleIterator;

/**
 *
 * @author javier
 */
public class UmbralizacionOp extends BufferedImageOpAdapter {

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
        BufferedImage bn = createCompatibleDestImage(src, null);
        WritableRaster srcRaster = src.getRaster();
        WritableRaster destRaster = bn.getRaster();
        //se traspasan los colores Pixel a Pixel
        for (BufferedImagePixelIterator it = new BufferedImagePixelIterator(src); it.hasNext();) {
            BufferedImagePixelIterator.PixelData iterador = it.next();
            int r, g, b;
            Color color;
            color = new Color(src.getRGB(iterador.col, iterador.row));
            //se extraen los valores RGB
            r = color.getRed();
            g = color.getGreen();
            b = color.getBlue();
            //dependiendo del valor del umbral, se van separando los
            // valores RGB a 0 y 255 
            if (r > umbral) {
                r = 255;
            } else {
                r = 0;
            }
            if (g > umbral) {
                g = 255;
            } else {
                g = 0;
            }
            if (b > umbral) {
                b = 255;
            } else {
                b = 0;
            }
            bn.setRGB(iterador.col, iterador.row, new Color(r, g, b).getRGB());
        }
        return bn;
    }

    @Override
    public BufferedImage filter(BufferedImage bi, BufferedImage bi1) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}

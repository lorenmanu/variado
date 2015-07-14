/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica;

import java.awt.image.Kernel;

public class Kernel_Mascara {
    
    //Tipos de máscaras
    final static int TYPE_MEDIA_3x3 = 0;
    final static int TYPE_BINOMIAL_3x3 = 1;
    final static int TYPE_ENFOQUE_3x3 = 2;
    final static int TYPE_RELIEVE_3x3 = 3;
    final static int TYPE_LAPLACIANA_3x3 = 4;
   
    /**
     * Crea objetos Kernel a partir de máscaras predefinidas
     */
    static Kernel createKernel(int tipo){
        switch(tipo){
            case 0:
                 return new Kernel(3,3,MASCARA_MEDIA_3x3); 
            case 1:
                 return new Kernel(3,3,MASCARA_BINOMIAL_3x3);    
            case 2:
                 return new Kernel(3,3,MASCARA_ENFOQUE_3x3);     
            case 3:
                 return new Kernel(3,3,MASCARA_RELIEVE_3x3);     
            case 4:
                 return new Kernel(3,3,MASCARA_LAPLACIANA_3x3);  
            case 5:
                return new Kernel(3,3,MASCARA_REPUJAR_3x3);
            case 6:
                return new Kernel(3,3,MASCARA_REALCE_3x3);
            default:
                 return null;
        }
    }
    
    /**
     * Constructor privado 
     */
    public Kernel_Mascara(){}
    
   // Máscaras de convolución
    static float MASCARA_MEDIA_3x3[] = {
      0.1f, 0.1f, 0.1f,
      0.1f, 0.2f, 0.1f,
      0.1f, 0.1f, 0.1f
    };
    static float MASCARA_BINOMIAL_3x3[] = {
      0.0625f, 0.125f, 0.0625f,
      0.125f, 0.25f, 0.125f,
      0.0625f, 0.125f, 0.0625f
    };
    static float MASCARA_ENFOQUE_3x3[] = {  
      0.0f, -1.0f, 0.0f,
      -1.0f, 5.0f, -1.0f,
      0.0f, -1.0f, 0.0f
    };
    static float MASCARA_LAPLACIANA_3x3[] = {
      1.0f, 1.0f, 1.0f,
      1.0f, -8.0f, 1.0f,
      1.0f, 1.0f, 1.0f
    };
    static float MASCARA_RELIEVE_3x3[] = {   
      -2.0f, -1.0f, 0.0f,
      -1.0f, 1.0f, 1.0f,
      0.0f, 1.0f, 2.0f
    };
    
    static float MASCARA_REPUJAR_3x3[] = {
        -2.0f, 1.0f,  0.0f, 
        -1.0f, 1.0f, 1.0f,
        0.0f, 1.0f,  2.0f
    };
    
    static float MASCARA_REALCE_3x3[] = {
        0.0f, -1.0f, 0.0f,
        -1.0f,  5.0f, -1.0f,
        0.0f, -1.0f, 0.0f
    };

            // Fin máscaras de convolución 
}

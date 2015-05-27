/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica4;

/**
 *
 * @author root
 */
public class Practica4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       //Queremos pagar un total de 12unidades con monedas de 1,6 y 10
       //Encontrar la mejor opción para dar el menor número de monedas
       Cambio c = new Cambio(14, new int[]{1,2,5,10,20,50});
       int resultado[] = c.getVectorSeleccion();
       int matriz[][] = c.getMatrizCambio();
       System.out.println("n=6,P=14");
       System.out.println("Matriz:");
       for(int i=1; i<resultado.length+1; i++)
       {
           for(int j=0; j<=14; j++)
              System.out.print(matriz[i][j]+" ");
           System.out.print("\n");
       }
       
       System.out.println("Vector resultado:");
       System.out.print("{");
       for(int i=0; i<resultado.length; i++)
          System.out.print(resultado[i]+" ");
       System.out.print("}\n");
       
       
    }
    
}

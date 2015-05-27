/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica4;

public class Cambio {

    private int[][] matrizCambio;
    private int[] vectorMonedas;
    private int cantidad;
    private int[] vectorSeleccion;

   
    Cambio(int cantidad, int[] monedas) {
        this.cantidad = cantidad; //Cantidad que queremos pagar  (P)
        this.vectorMonedas = monedas; //Tipos de monedas diferentes (n=size())
        matrizCambio = calcularMonedas(cantidad, monedas); 
        vectorSeleccion = seleccionarMonedas(cantidad, monedas, matrizCambio);
    }

    public int[] getVectorSeleccion() {
        return this.vectorSeleccion;
    }

    public int[][] getMatrizCambio() {
        return this.matrizCambio;
    }

    private int[][] calcularMonedas(int cantidad, int[] monedas) {

        
        int[][] matrizCambio2 = new int[monedas.length + 1][cantidad + 1];

        for (int i = 0; i < monedas.length; i++) {
            matrizCambio2[i][0] = 0;
        }

        for (int j = 1; j <= cantidad; j++) {
            matrizCambio2[0][j] = 99;
        }

        for (int i = 1; i <= monedas.length; i++) {
            for (int j = 1; j <= cantidad; j++) {
                if (j < monedas[i - 1]) {

                    matrizCambio2[i][j] = matrizCambio2[i - 1][j];
                } else {

                    int minimo = 0;

                    minimo = min(matrizCambio2[i - 1][j], matrizCambio2[i][j - monedas[i - 1]] + 1);
                    matrizCambio2[i][j] = minimo;

                }
            }
        }

        return matrizCambio2;
    }

    private int[] seleccionarMonedas(int c, int[] monedas, int[][] tabla) {
        int i, j;
        int[] seleccion = new int[monedas.length];
        for (i = 0; i < monedas.length; i++) {
            seleccion[i] = 0;
        }
        i = monedas.length;
        j = c;
        while (j > 0) {
            if (i > 1 && tabla[i][j] == tabla[i - 1][j]) {
                i--;
            } else {
                seleccion[i - 1]++;
                j = j - monedas[i - 1];
            }
        }

        return seleccion;
    }

    private int min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }

}

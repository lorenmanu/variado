//Problema de los fumadores con monitores Hoare
//Jesús Ángel González Novez  76440070F
//Grupo A
package fumadores;

public class EjemploFumadores {
    public static void main(String[] args) {
        Estanco estanco = new Estanco();
        Estanquero estanquero = new Estanquero(estanco);
        estanquero.thr.start();
        for(int i=0; i<3 ; i++){
            Fumador fum = new Fumador(i,estanco);
            fum.thr.start();
        }
    
    }
}

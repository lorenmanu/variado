//Problema de los fumadores con monitores Hoare
//Jesús Ángel González Novez  76440070F
//Grupo A
package fumadores;

class Estanquero implements Runnable {

    public Thread thr;
    private Estanco estanco;
    public Estanquero(Estanco estanco){
        this.estanco = estanco;
        this.thr = new Thread(this,"Estanquero");
    }
    public void run() {
        int ingrediente;
        while (true) {
            ingrediente = (int) (Math.random() * 3.0); // 0,1 o 2
            estanco.ponerIngrediente(ingrediente);
            estanco.esperarRecogidaIngrediente();
        }
    }
}


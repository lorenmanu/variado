/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fumadores;
class Fumador implements Runnable {

    int miIngrediente;
    public Thread thr;
    private Estanco estanco;
    
    public Fumador(int p_miIngrediente, Estanco estanco  ) {
        this.miIngrediente = p_miIngrediente;
        this.estanco = estanco;
        this.thr = new Thread(this,"Fumador" + p_miIngrediente);
        
    }

    public void run() {
        while (true) {
            estanco.obtenerIngrediente(miIngrediente);
            aux.dormir_max(2000);
        }
    }
}


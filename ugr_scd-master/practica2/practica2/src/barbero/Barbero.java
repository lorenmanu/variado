package barbero;
/**
 *
 * @author Jesús Ángel González Novez
 */
class Barbero implements Runnable {

    public Thread thr;
    private Barberia barberia;
    public Barbero(Barberia barberia){
        this.barberia = barberia;
        this.thr = new Thread(this,"Barbero");
    }
    public void run() {
        while (true) {
            barberia.siguienteCliente();
            aux.dormir_max(2500); // el barbero está cortando el pelo
            barberia.finCliente();
        }
    }
}


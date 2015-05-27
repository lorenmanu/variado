package barbero2;

/**
 *
 * @author Jesús Ángel González Novez
 */
class Barbero2 implements Runnable {

    public Thread thr;
    private Barberia2 barberia;
    public Barbero2(Barberia2 barberia){
        this.barberia = barberia;
        this.thr = new Thread(this,"Barbero");
    }
    public void run() {
        while (true) {
            int t = barberia.siguienteCliente();
            Aux2.dormir_max(t); // el barbero está cortando el pelo
            barberia.finCliente();
        }
    }
}


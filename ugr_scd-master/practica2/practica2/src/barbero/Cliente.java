package barbero;
/**
 *
 * @author Jesús Ángel González Novez
 */
class Cliente implements Runnable {

    public Thread thr;
    private Barberia barberia;
    private int id;
    public Cliente(Barberia barberia,int id){
        this.barberia = barberia;
        this.id = id;
        this.thr = new Thread(this,"Cliente");
    }
    public void run() {
        while (true) {
            barberia.cortarPelo(this.id); // el cliente espera (si procede) y se corta el pelo
            aux.dormir_max(2000); // el cliente está fuera de la barberia un tiempo

        }
    }
}

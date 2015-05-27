package barbero2;

/**
 *
 * @author Jesús Ángel González Novez
 */
class Cliente2 implements Runnable {

    public Thread thr;
    private Barberia2 barberia;
    private int id;
    public Cliente2(Barberia2 barberia,int id){
        this.barberia = barberia;
        this.id = id;
        this.thr = new Thread(this,"Cliente");
    }
    public void run() {
        while (true) {
            int t = (int) (Math.random() * 3.0 +1);
            barberia.cortarPelo(this.id,t); // el cliente espera (si procede) y se corta el pelo
            Aux2.dormir_max(2000); // el cliente está fuera de la barberia un tiempo

        }
    }
}

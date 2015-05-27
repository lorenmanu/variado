package barbero;
/**
 *
 * @author Jesús Ángel González Novez
 */
public class EjemploBarberoDurmiente {
    public static void main(String[] args) {
        Barberia barberia = new Barberia();
        Barbero barbero;
        barbero = new Barbero(barberia);
        barbero.thr.start();
        for(int i=0; i<5 ; i++){
            Cliente cli = new Cliente(barberia,i);
            cli.thr.start();
        }
    
     
    }
}

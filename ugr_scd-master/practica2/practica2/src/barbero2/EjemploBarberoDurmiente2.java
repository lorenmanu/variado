package barbero2;
/**
 *
 * @author Jesús Ángel González Novez
 */
public class EjemploBarberoDurmiente2 {
    public static void main(String[] args) {
        Barberia2 barberia = new Barberia2();
        Barbero2 barbero;
        barbero = new Barbero2(barberia);
        barbero.thr.start();
        for(int i=0; i<5 ; i++){
            Cliente2 cli = new Cliente2(barberia,i);
            cli.thr.start();
        }
    
     
    }
}

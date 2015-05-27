package barbero2;
/**
 *
 * @author Jesús Ángel González Novez
 */

import java.util.Random;

class Aux2 {
    static Random genAlea = new Random();
    static void dormir_max(int milisecsMax) {
        try {
            Thread.sleep(genAlea.nextInt(milisecsMax));
        } catch (InterruptedException e) {
            System.err.println("sleep interumpido en ’aux.dormir_max()’");
        }
    }
}

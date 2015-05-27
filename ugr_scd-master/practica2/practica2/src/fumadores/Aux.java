/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fumadores;

import java.util.Random;

class aux {
    static Random genAlea = new Random();
    static void dormir_max(int milisecsMax) {
        try {
            Thread.sleep(genAlea.nextInt(milisecsMax));
        } catch (InterruptedException e) {
            System.err.println("sleep interumpido en ’aux.dormir_max()’");
        }
    }
}

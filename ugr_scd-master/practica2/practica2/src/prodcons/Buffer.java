package prodcons;

import monitor.*;

class Buffer extends AbstractMonitor{

    private int numSlots = 0, cont = 0;
    private double[] buffer = null;
    
    //AÑADIDO
    private Condition puede_producir = makeCondition();
    private Condition puede_consumir = makeCondition();
    
    public Buffer(int p_numSlots) {
        numSlots = p_numSlots;
        buffer = new double[numSlots];
    }

    public void depositar(double valor) throws InterruptedException {
        enter();
        while (cont == numSlots) {
            puede_producir.await();
        }
        buffer[cont] = valor;
        cont++;
        puede_consumir.signal();
        leave();
    }

    public double extraer() throws InterruptedException {
        enter();
        double valor;
        while (cont == 0) {
            puede_consumir.await();
        }
        cont--;
        valor = buffer[cont];
        puede_producir.signal();
        leave();
        return valor;
        
    }
}
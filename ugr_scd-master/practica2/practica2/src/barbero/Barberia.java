package barbero;
/**
 *
 * @author Jesús Ángel González Novez
 */
import monitor.AbstractMonitor;
import monitor.Condition;
class Barberia extends AbstractMonitor {
    private int barbero;
    private int silla;
    private int abierta;
    private Condition barberoLibre;
    private Condition sillaOcupada;
    private Condition puertaAbierta;
    private Condition clienteAdios;
    public Barberia(){
        this.barbero = 0;
        this.silla = 0;
        this.abierta = 0;
        this.barberoLibre = makeCondition();
        this.sillaOcupada = makeCondition();
        this.puertaAbierta = makeCondition();
        this.clienteAdios = makeCondition();
    }
    // invcado por los clientes para cortarse el pelo
    public void cortarPelo(int id) {
        enter();	
        while (barbero == 0)
            barberoLibre.await();
	barbero--;
	silla++;
	sillaOcupada.signal();
	while (abierta == 0)
            puertaAbierta.await();
	abierta--;
        clienteAdios.signal();
        System.out.println("LLega el cliente:"+id);
        leave();
    }
// invocado por el barbero para esperar (si procede) a un nuevo cliente y sentarlo para el corte
    public void siguienteCliente() {
        enter();
        barbero++;
	barberoLibre.signal();
	while (silla == 0)
            sillaOcupada.await();
	silla--;
        System.out.println("El cliente se sienta y lo pelo");
        leave();
    }
// invocado por el barbero para indicar que ha terminado de cortar el pelo
    public void finCliente() {
        enter();
        abierta++;
	puertaAbierta.signal();
	while (abierta > 0)
            clienteAdios.await();
        System.out.println("Adios y gracias");
        leave();

    }
}

//Problema de los fumadores con monitores Hoare
//Jesús Ángel González Novez  76440070F
//Grupo A
package fumadores;

import monitor.*;

class Estanco extends AbstractMonitor {
    private int ingredienteMostrador;
    private Condition poner_ingrediente = makeCondition();
    public Estanco(){
        this.ingredienteMostrador = -1;
    }
// invocado por cada fumador, indicando su ingrediente o numero
    public void obtenerIngrediente(int miIngrediente) {
        enter();
        if(miIngrediente == ingredienteMostrador){
            String nombre=new String(),ingrediente=new String();
            if(miIngrediente == 0){
                nombre = "Pepe";
                ingrediente = "cerillas";
            }
            if(miIngrediente == 1){
                nombre = "Juan";
                ingrediente = "papel";
            }
            if(miIngrediente == 2){
                nombre = "Jose";
                ingrediente = "tabaco";
            }
            System.out.println(nombre + " coge el ingrediente " + ingrediente);
            poner_ingrediente.signal();
        }
        leave();
        
    }
// invocado por el estanquero, indicando el ingrediente que pone
    public void ponerIngrediente(int ingrediente) {
        enter();
        this.ingredienteMostrador = ingrediente;
         String ing=new String();
            if(ingredienteMostrador == 0){
                ing = "cerillas";
            }
            if(ingredienteMostrador == 1){
                ing = "papel";
            }
            if(ingredienteMostrador == 2){
                ing = "tabaco";
            }
        System.out.println("En el mostrador hay " + ing);
        leave();
    }
// invocado por el estanquero
    public void esperarRecogidaIngrediente() {
        enter();
        poner_ingrediente.await();
        leave();
    }
}

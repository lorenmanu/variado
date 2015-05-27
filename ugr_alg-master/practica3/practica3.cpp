#include <iostream>
#include <cstdlib>
#include <omp.h>
using namespace std;
#define N 5

/*-----Códigos de los colores usados --------------
    black \033[22;30m  
    red \033[22;31m  
    green \033[22;32m  
    brown \033[22;33m  
    blue \033[22;34m  
    yellow \033[01;33m  
    cyan \033[22;36m 
    white \033[01;37m
-------------------------------------------------*/

//Estructuras auxiliares---------------------------
struct nodo{
  int id;
  int color;
  int n_aristas;
  int * aristas;
};
struct grafo{
  int size;
  nodo *nodos;
}; 
//--------------------------------------------------

//Pasamos el nodo y el número de aristas que queramos que tenga.
void creaArista(nodo &n, int n_a){ 
   n.n_aristas = n_a;
   n.aristas = new int[n_a];
}

//Liberamos toda la memoria del grafo que pasamos como argumento.
void liberar(grafo &g){ 
   for (int i = 0; i < g.size; i++){
      delete[] g.nodos[i].aristas;
   }

   delete[] g.nodos;
}

//Muestra el grafo indicado con colores (si está coloreado).
void pintaGrafo(grafo &g){ 
   for (int i = 0; i < g.size; i++){
      cout << "\033[01;37mNodo: ";
      switch(g.nodos[i].color)
      {
        case 0: cout << "\033[22;30m" << g.nodos[i].id;
        break;
        case 1: cout << "\033[22;32m" << g.nodos[i].id;
        break;
        case 2: cout << "\033[22;31m" << g.nodos[i].id;
        break;
        case 3: cout << "\033[22;34m" << g.nodos[i].id;
        break;
        case 4: cout << "\033[22;33m" << g.nodos[i].id;
        break;
        case 5: cout << "\033[01;33m " << g.nodos[i].id;
        break;
        case 6: cout << "\033[22;36m" << g.nodos[i].id;
      	break;
      	case 7: cout << "\033[01;37m" << g.nodos[i].id;
      	break;
      }
      cout << "\033[01;37m --> ";
      for (int j = 0; j < g.nodos[i].n_aristas; j++){
         switch(g.nodos[g.nodos[i].aristas[j]].color)
         {
           case 0: cout << "\033[22;30m"<< g.nodos[i].aristas[j] << " ";
           break;
           case 1: cout << "\033[22;32m" << g.nodos[i].aristas[j] << " ";
           break;
           case 2: cout << "\033[22;31m" << g.nodos[i].aristas[j] << " ";
           break;
           case 3: cout << "\033[22;34m"<< g.nodos[i].aristas[j] << " ";
           break;
           case 4: cout << "\033[22;33m" << g.nodos[i].aristas[j] << " ";
           break;
           case 5: cout << "\033[01;33m " << g.nodos[i].aristas[j] << " ";
           break;
           case 6: cout << "\033[22;36m" << g.nodos[i].aristas[j] << " ";
           break;
           case 7: cout << "\033[01;37m" << g.nodos[i].aristas[j] << " ";
           break;
         }
      }
      cout << "\033[01;37m" << endl;
   }
}

//Solución
bool solucion(grafo &g){
   bool resultado = true; //Inicialmente es true hasta que encuentra un nodo blanco.

   for (int i = 0; i < g.size && resultado; i++){
      if (g.nodos[i].color == 7){ //Si el color del nodo es blanco no tenemos solución.
         resultado = false;
      }
   }

   return resultado;
}

//Colorear el grafo
void coloracion(grafo &g){
   cout << endl << "\033[01;37mColoreando..." << endl;

   int color_actual = 1;

   while(!solucion(g)){ //Solución recorre todos los nodos para comprobar si hay alguno sin pintar (blanco).
      for (int i = 0; i < g.size; i++){
         if (g.nodos[i].color == 7){ //Si el nodo está sin colorear.
            bool colorear = true;

            for (int j = 0; j < g.nodos[i].n_aristas && colorear; j++){ //Comprobamos que los vecinos no tienen el color actual.
               if (g.nodos[g.nodos[i].aristas[j]].color == color_actual){
                  colorear = false;
               }
            }

            if (colorear){ //Se puede colorear con el color actual.
               g.nodos[i].color = color_actual;
            }
         }
      }

      color_actual++;
   }
}

//Creación del grafo
void creaGrafo(grafo &g){
   g.size = N;
   g.nodos = new nodo[N];

   for (int i = 0; i < N; i++){
      g.nodos[i].id = i;
      g.nodos[i].color = 7; //White.
   }

   creaArista(g.nodos[0], 1);
   creaArista(g.nodos[1], 2);
   creaArista(g.nodos[2], 3);
   creaArista(g.nodos[3], 2);
   creaArista(g.nodos[4], 2);

   g.nodos[0].aristas[0] = 2;
   g.nodos[1].aristas[0] = 3;
   g.nodos[1].aristas[1] = 4;
   g.nodos[2].aristas[0] = 0;
   g.nodos[2].aristas[1] = 3;
   g.nodos[2].aristas[2] = 4;
   g.nodos[3].aristas[0] = 1;
   g.nodos[3].aristas[1] = 2;
   g.nodos[4].aristas[0] = 1;
   g.nodos[4].aristas[1] = 2;
}

//Función main
int main(int argc,char *argv[])
{
   grafo g;
   creaGrafo(g);
   pintaGrafo(g);
   coloracion(g);
   pintaGrafo(g);
   liberar(g);
}

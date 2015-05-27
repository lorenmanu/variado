/*
 * Jesús Ángel González Novez
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "player.h"
#include "environment.h"
#include <omp.h>
using namespace std;

const double masinf=9999999999.0, menosinf=-9999999999.0;
//Contador del total de estados evaluados
int estadosEvaluados = 0;
// Constructor
Player::Player(int jug)
{
    jugador_=jug;
}

// Actualiza el estado del juego para el jugador
void Player::Perceive(const Environment & env)
{
    actual_=env;
}

/*
double Puntuacion(int jugador, const Environment &estado)
{
    double suma=0;
    for (int i=0; i<7; i++)
        for (int j=0; j<7; j++)
        {
            if (estado.See_Casilla(i,j)==jugador)
            {
                if (j<3)
                    suma += j;
                else
                    suma += (6-j);
            }
        }
    return suma;
}

Funcion de valoracion para testear Poda Alfabeta
double ValoracionTest(const Environment &estado, int jugador)
{
    int ganador = estado.RevisarTablero();
    if (ganador==jugador)
        return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
        return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
        return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else
        return Puntuacion(jugador,estado);
}
*/

//FUNCIONES AUXILIARES(HEURISTICA)
double tengoEnFila(Environment estado,int jugador)
{
    int jugadorAux;
    double resultado=0;
    for(int i=0; i<7; ++i){
        for(int j=0; j<7; ++j){
            //Comprobamos que se este mirando una casilla del jugador
            // para ahorrarnos el resto de ifs en caso contrario.
            if(estado.See_Casilla(i,j)==jugador){
//--------------Combinaciones de dos-----------------------------------------//
                //Horizontal de dos
                if(j<6 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i,j+1) == jugador)
                    resultado += 10;
                //Horizontal de dos preferente
                if(j>1 && j<4 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i,j+1) == jugador)
                    resultado += 10;

                //Vertical  de dos
                if(i>0 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j) == jugador)
                    resultado += 5;
                //Vertical de dos preferente
                if(i>0 && i<5 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j) == jugador)
                    resultado += 5;
                //Vertical de dos central
                if(i>0 && j==3 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j) == jugador)
                    resultado += 4;

                //Diagonal der abajo de dos
                if((i>0 && j<6) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j+1) == jugador)
                    resultado += 20;
                //Diagonal der abajo de dos preferente
                if((i>2 && j<4) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j+1) == jugador)
                    resultado += 20;

                //Diagonal izq abajo de dos
                if((i>0 && j>0) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j-1) == jugador)
                    resultado += 20;
                //Diagonal izq abajo de dos preferente
                if((i>2 && j>2) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j-1) == jugador)
                    resultado += 20;

//--------------Combinaciones de tres------------------------------------------//
                //Horizontal de tres
                if(j<5 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i,j+1) == jugador && estado.See_Casilla(i,j+2) == jugador)
                    resultado += 50;
                //Horizontal de tres preferente
                if(j>0 && j<4 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i,j+1) == jugador && estado.See_Casilla(i,j+2) == jugador)
                {
                    resultado += 50;
                    //Horizontal de tres preferente con hueco en ambos extremos
                    if(estado.See_Casilla(i,j+3)==0 && estado.See_Casilla(i,j-1)==0)
                        resultado += 500;
                }

                //Vertical de tres
                if(i>1 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j) == jugador && estado.See_Casilla(i-2,j) == jugador)
                    resultado += 30;
                //Vertical de tres preferente
                if(i>1 && i<6 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j) == jugador && estado.See_Casilla(i-2,j) == jugador)
                {
                    resultado += 30;
                    //Vertical de tres preferente con hueco arriba
                    if(estado.See_Casilla(i+1,j)==0)
                        resultado+=30;
                }
                //Vertical de tres central
                if(i>1 && j==3 && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j) == jugador && estado.See_Casilla(i-2,j) == jugador)
                    resultado += 20;

                //Diagonal derecha abajo de tres
                if((i>1 && j<5) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j+1) == jugador && estado.See_Casilla(i-2,j+2) == jugador)
                    resultado += 100;
                //Diagonal derecha abajo de tres preferente
                if((i>2 && j<4) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j+1) == jugador && estado.See_Casilla(i-2,j+2) == jugador)
                {
                    resultado += 100;
                    //Diagonal derecha abajo de tres preferente con hueco en ambos lados
                    if(i<6 && j>0 && estado.See_Casilla(i-3,j+3)==0 && estado.See_Casilla(i+1,j-1)==0)
                        resultado += 500;
                }

                //Diagonal izq abajo de tres
                if((i>1 && j>1) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j-1) == jugador && estado.See_Casilla(i-2,j-2) == jugador)
                    resultado += 100;
                //Diagonal izq abajo de tres preferente
                if((i>2 && j>2) && estado.See_Casilla(i,j) == jugador && estado.See_Casilla(i-1,j-1) == jugador && estado.See_Casilla(i-2,j-2) == jugador)
                {
                    resultado += 100;
                    //Diagonal izq abajo de tres preferente con hueco en ambos lados
                    if(i<6 && j<6 && estado.See_Casilla(i+1,j+1)==0 && estado.See_Casilla(i-3,j-3)==0)
                        resultado += 500;
                }

//--------------Otras comprobaciones------------------------------------------//
                //Damos prioridad a las columnas centrales o en los laterales
                if(j==3)
                    resultado+=5;
                if(j==0 || j==6)
                    resultado+=2;
            }
        }
    }
    return resultado;
}


double Valoracion(const Environment &estado, int jugador)
{
    int ganador = estado.RevisarTablero();
    if (ganador==jugador)
        return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
        return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
        return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else{
        //Si no he ganado ni perdido ni empatado aplicamos la heurística
        double total=0;
        total += tengoEnFila(estado,jugador);
        return total;
    }
}



void JuegoAleatorio(bool aplicables[], int opciones[], int &j)
{

    j=0;
    for (int i=0; i<7; i++)
    {
        if (aplicables[i])
        {
            opciones[j]=i;
            j++;
        }
    }
}

//ALGORITMO MINIMAX CON PODA ALFA_BETA
double Player::minimax(const Environment &env,int jugador, int depth,double a,double b,bool maxormin)
{
    if(env.JuegoTerminado() || depth==0){
        estadosEvaluados++;
        return Valoracion(env,jugador);
    }
    int n_act;
    bool aplicables[7];
    n_act = env.possible_actions(aplicables);
    Environment tableros[7];
    n_act = env.GenerateAllMoves(tableros);
    if(maxormin){
        for(unsigned int i=0; i<n_act; ++i){
            a = max(a,minimax(tableros[i],jugador,depth-1,a,b,!maxormin));
            if(a >= b) return b;
        }
        return a;
    }
    else{
        for(unsigned int j=0; j<n_act; ++j){
            b = min(b,minimax(tableros[j],jugador,depth-1,a,b,!maxormin));
            if(a >= b) return a;
        }
        return b;
    }

}

// Invoca el siguiente movimiento del jugador
Environment::ActionType Player::Think()
{
    const int PROFUNDIDAD_ALFABETA = 8; // Umbral maximo de profundidad para la poda Alfa_Beta
    Environment::ActionType accion; // acción que se va a devolver
    bool aplicables[7]; // Vector bool usado para obtener las acciones que son aplicables en el estado actual. La interpretacion es
    double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
    double alpha, beta; // Cotas de la poda AlfaBeta
    int n_act; //Acciones posibles en el estado actual
    n_act = actual_.possible_actions(aplicables); // Obtengo las acciones aplicables al estado actual en "aplicables"
//  int opciones[10];

    cout << " Acciones aplicables ";
    (jugador_==1) ? cout << "Jugador verde" : cout << "Jugador azul";
    for (unsigned int t=0; t<7; ++t)
        if (aplicables[t])
            cout << " " << actual_.ActionStr( static_cast< Environment::ActionType > (t)  );
    cout << endl;

    alpha = menosinf;
    beta = masinf;
    int act=-1;
    Environment tableros[7];
    n_act = actual_.GenerateAllMoves(tableros);
    double sec1,sec2;
    sec1 = omp_get_wtime();
    for(unsigned int i=0; i<n_act; ++i){
        
	valor = minimax(tableros[i],jugador_,PROFUNDIDAD_ALFABETA,alpha,beta,false);
        if(valor > alpha){
            alpha = valor;
            accion = static_cast< Environment::ActionType > (tableros[i].Last_Action(jugador_));
        }
    }
  
    sec2 = omp_get_wtime();
    cout << "Estados evaluados hasta ahora:" << estadosEvaluados << endl;
    cout << "Valor: " << valor << "  Accion: " << actual_.ActionStr(accion) << endl;
    if(alpha == menosinf){
        act = -1;
        Environment tablero = actual_.GenerateNextMove(act);
        accion = static_cast< Environment::ActionType > (tablero.Last_Action(jugador_));
    }
    cout << "Tiempo empleado para decidir:" << sec2-sec1 << " segundos"<< endl << endl;
    return accion;
}


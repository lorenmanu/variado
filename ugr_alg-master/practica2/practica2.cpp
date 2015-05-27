#include <iostream>
#include <cstdlib>
#include <omp.h>
using namespace std;
void pivote(int vector[],int N,int i,int j,int &l)
{
  int p,k,aux;
  p = vector[i];
  k = i;
  l = j + 1;
  for(k = k+1; vector[k]<p && k<j; k++);
  for(l = l-1; vector[l]>p; l--);
  while(k<l)
  {
    aux = vector[k];
    vector[k] = vector[l];
    vector[l] = aux;
    for(k = k+1; vector[k]<=p; k++);
    for(l = l-1; vector[l]>p; l--);
  }
  aux = vector[i];
  vector[i] = vector[l];
  vector[l] = aux;
}

int seleccion(int vector[],int N,int s)
{
  int i,j,l;
  i = 0;
  j = N-1;
  do
  {
    pivote(vector,N,i,j,l);
    if(s<l)  j = l - 1;
    else if(s>l) i = l +1;
  }while(l != s);
  return vector[l];
}

void mostrar(int v[],int N)
{
  for(int i=0; i<N; i++)
    cout << v[i] << " ";
  cout << endl;
}

int main(int argc,char *argv[])
{
  if(argc < 3){
    cout << "Uso ./practica2 N opcion" << endl;
    cout << "N=tamaño" << endl;
    cout << "\033[22;32mopcion= si es 1 ordenado, si distinto de 1 aleatorio" << endl;
    return 0;
  }
  int resultado, mediana;
  int N=atoi(argv[1]);
  int ordenado=atoi(argv[2]);
  int *v0 = (int*) malloc(10*N);
  double t1,t;
  //Rellenamos vector
  if(ordenado == 1)
    for(int i=0; i<N; i++)   v0[i] = i;
  else   
    for(int i=0; i<N; i++)   v0[i] = rand()%N;
    
  //Mostramos vector
  if(N<10){
    cout << "V0:";
    mostrar(v0,N);
  }else{
    cout << "V0[0]:" << v0[0] << " ... V0[N-1]:" << v0[N-1] << endl;
  }
  mediana = N / 2;
  t1 = omp_get_wtime();
  resultado = seleccion(v0,N,mediana);
  t = omp_get_wtime()-t1;
  cout << "Mediana V0:" << resultado << endl;
  cout << "Tiempo de ejecución:" << t << "(s)" << endl;
  free(v0);
}

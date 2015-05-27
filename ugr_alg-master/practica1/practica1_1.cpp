#include <iostream>
#include <cstdlib>
using namespace std;
void mostrar(int v[],int n)
{
  for(int i=0; i<n; i++)
    cout << v[i] << " ";
  cout << endl;
}
int main(int argc,char *argv[])
{
  int N;
  if(argc < 2)
    N=10;
  else
    N=atoi(argv[1]);
  int a[N];
  int inst1=0,inst2=0;
  //Primera función
  for(int i=0; i<N; i++)
    a[i] = i;
  for(int i=0; i<N; i++){
    if(a[i] >= a[N-1]){
      a[N-1] = a[i];
      inst1++;
    }
    i *= 2;
    
  }
  
  //Segunda función
  for(int i=0; i<N; i++)
    a[i] = i;
  int cont=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<i; j++){
      if(a[i]<a[j]){
         inst2++;
         cont++;
      }
    }
  }
  cout << inst1 << " " << inst2 << endl;
 
}

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

//modela classe
class Ordenacao{
  public:
    int x,z;
   int vetor[20];

  Ordenacao(){
    srand((unsigned int)time(NULL));

    for(int i=0;i<20;i++){
		    vetor[i] = rand()%100+1;
	   }
  };
  //~bubbles(){};

  void bublesort(){
    z=20;
    do{
      for (int i=0;i<20;i++){
        if(i+1<=20){
              if(vetor[i]>vetor[i+1]){
                x=vetor[i+1];
                vetor[i+1]=vetor[i];
                vetor[i]=x;
              }
        }
      }
      z--;
    } while(z!=0);

  };

  void selectionsort(){
    for (int i=0;i<20;i++){
      z=vetor[i];
      for (x=i+1;x<20;x++){
        if(vetor[x]<z){
          z=vetor[x];
          vetor[x]=vetor[i];
          vetor[i]=z;
        }
      }
      vetor[i]=z;
    }

  };

  //
  // void insertionsort(){
  //   for (int i=0;i<20;i++){
  //     int b=1;
  //     while(vetor[i]<vetor[i+b]){
  //       b++;
  //
  //     }
  //       //if(vetor[i]
  //   }
  // }
};

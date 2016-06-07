#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;
//modela classe
class Ordenacao{
  public:
  int x,z;
  Ordenacao(int Vetor[]){
      /*for(int i=0;i<20;i++){
		    vetor[i] = Vetor[i];
	   }*/
    };

  void bublesort(int *vetor){
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
//________________________________________________________________________________________
  void selectionsort(int *vetor){
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

  //_____________________________________________________________________________________
  void insertionSort(int *vetor) {
        int key;

      for (x = 1; x < 20; x++){
        key = vetor[x];
          for (z = x - 1; (z >= 0) && (vetor[z] > key); z--){
             vetor[z + 1] = vetor[z];
          }
            vetor[z + 1] = key;
      }
  };
//_________________________________________________________________________________________
  void mergeSort(int *Vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho,*vetorTemp;


    if(posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(Vetor, posicaoInicio, metadeTamanho);
    mergeSort(Vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    int v [posicaoFim - posicaoInicio + 1];
    vetorTemp = v ;

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = Vetor[j];
            j++;
            k++;
        }else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = Vetor[i];
                i++;
                k++;
            }else {
                if (Vetor[i] < Vetor[j]) {
                    vetorTemp[k] = Vetor[i];
                    i++;
                    k++;
                }else {
                    vetorTemp[k] = Vetor[j];
                    j++;
                    k++;
                }
            }
        }
    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        Vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
};
    void ShellSort( int *vetor,int tamanho) {
     int i, temp;
     bool b = false;
     int tam=tamanho;
     while(tam > 1 || !b) {
          tam = (tam+1) / 2;
          b = false;
          for (i = 0; i < (tamanho - tam); i++) {
               if (vetor[i + tam] < vetor[i]) {
                      temp = vetor[i + tam];
                      vetor[i + tam] = vetor[i];
                      vetor[i] = temp;
                      b=true;
               }
          }
     }
     return;
};
    void quicksort(int *vetor,int tam){
        int aux;
        for (int i=0;i<tam;i++){
            aux =vetor[i];
            for (int j=tam;j>i;j--){
                if (aux>vetor[j]){
                    aux = vetor[j];
                    vetor[j]=vetor[i];
                    vetor[i]=aux;
                }
            }
        }
    };



};

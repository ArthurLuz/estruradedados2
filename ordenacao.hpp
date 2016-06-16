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

  void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp,aux;

    if(posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
     vetorTemp = new int [posicaoFim - posicaoInicio + 1];

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
};
// void mergeSort(int *vetor,int inicio,int fim) {
//
//   if (fim <= inicio) {
// 		return;
// 	}
// 	int meio = (inicio + fim) / 2;
// 	meio++;
// 	//mergeSort();
//   int *A =new int [meio - inicio + 1];
// 	int *B= new int [fim - meio];
// 	for (int i = 0; i <= meio - inicio; i++) {
// 		A[i] = vetor[inicio + i];
// 	}
// 	for (int i = 0; i <= fim - meio - 1; i++) {
// 		B[i] = vetor[meio + 1 + i];
// 	}
//   mergeSort(A,meio,meio-inicio+1);
//   mergeSort(B,inicio,fim-meio);
// 	int i = 0;
// 	int j = 0;
// 	for (int k = inicio; k <= fim; k++) {
// 		if (i < meio - inicio + 1 && j < fim - meio) {
// 			if (A[i] < B[j]) {
// 				vetor[k] = A[i++];
// 			} else {
// 				vetor[k] = B[j++];
// 			}
// 		} else if (i < meio - inicio + 1) {
// 			vetor[k] = A[i++];
// 		} else if (j < fim - meio) {
// 			vetor[k] = B[j++];
// 		}
// 	}
// };





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



    void quicksort(int *vetor,int inicio,int fim,int aboll){
      int indexpivo;
      int auxboll = aboll;
      if(auxboll<=0)indexpivo=inicio;
      else indexpivo=fim;
        int aux;
        if (inicio<fim){
          // encontra o index pivo

            //indexpivo=inicio;
            //do{
            if(vetor[indexpivo]>vetor[fim]){
              aux =vetor[indexpivo];
              vetor[indexpivo]=vetor[fim];
              vetor[fim]=aux;
              //indexpivo=inicio;
              auxboll=1;
              std::cout << "/* message */" << std::endl;
            }else{
              fim--;
            }
          //}while(fim>inicio || auxboll!=1);
          //do{
            if(vetor[indexpivo]<vetor[inicio]){
              aux =vetor[indexpivo];
              vetor[indexpivo]=vetor[inicio];
              vetor[inicio]=aux;
              //indexpivo=fim;
              auxboll=-1;
            }else{
                  inicio++;
            }
          //}while(inicio<fim||auxboll!=-1);

          }
          //indexpivo=encontrapivo(vetor,inicio,fim,auxboll);
          quicksort(vetor,indexpivo+1,fim,auxboll);
          quicksort(vetor,inicio,indexpivo-1,auxboll);

        };
        // int encontrapivo(int *vetor,int inicio,int fim, int auxboll){
        //   int i = inicio;
        //   int f = fim;
        //   int aux= auxboll;
        //     if(aux=1) return f;
        //     if (aux=-1) return i;
        // };

    };

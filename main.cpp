#include "ordenacao.hpp"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

    Ordenacao *x;
    int vetor[20];
    x = new Ordenacao(vetor);

    srand((unsigned int)time(NULL));

    for(int i=0;i<20;i++){ //preenche o vetor
		    vetor[i] = 1 + ( rand() % 100 );//rand()%100000+1;
    }
    int inicio=0;
    int fim=19;
    int tam =20;
    for(int i=0;i<20;i++){
      cout << "original: "<< vetor[i] << endl; //mostra o vetor antes de arrumar
    }
   // x->mergeSort(vetor,inicio,fim);
   // x->selectionsort(vetor);
   // x->bublesort(vetor);
    //x->insertionSort(vetor);
    x->quickSort(vetor,inicio,fim);
        for(int i=0;i<20;i++){
      cout << "ordenado:  "<< vetor[i] << endl; //mostra depois de ordenado
    }







<<<<<<< HEAD
}//}

=======
}
>>>>>>> 83b0a0a4a99050d673747f00681b265728d4cabc

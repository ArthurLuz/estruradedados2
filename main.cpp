#include "ordenacao.hpp"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

    Ordenacao *x;
    int vetor[10];
    x = new Ordenacao(vetor);

    srand((unsigned int)time(NULL));

    for(int i=0;i<10;i++){ //preenche o vetor
		    vetor[i] = 1 + ( rand() % 100 );//rand()%100000+1;
    }
    int inicio=0;
    int fim=9;
    int tam =10;

    for(int i=0;i<tam;i++){
      cout << "original: "<< vetor[i] << endl; //mostra o vetor antes de arrumar
    }
   //x->mergeSort(vetor,inicio,fim);
   // x->selectionsort(vetor);
   // x->bublesort(vetor);
    //x->insertionSort(vetor);
    x->quicksort(vetor,inicio,fim,0);
    for(int i=0;i<tam;i++){
      cout << "ordenado:  "<< vetor[i] << endl; //mostra depois de ordenado
    }








}

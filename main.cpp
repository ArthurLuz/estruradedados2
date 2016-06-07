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
    for(int i=0;i<20;i++){
      cout << "original: "<< vetor[i] << endl; //mostra o vetor antes de arrumar
    }
    int inicio=0;
    int fim=19;

    x->mergeSort(vetor,inicio,fim);
    x->selectionsort(vetor);
    x->bublesort(vetor);
    x->insertionSort(vetor);
    for(int i=0;i<20;i++){
      cout << "ordenado:  "<< vetor[i] << endl; //mostra depois de ordenado
    }








};

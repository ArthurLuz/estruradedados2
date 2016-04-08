#include "pessoa.hpp"
#include <iostream>
#include <string>

Pessoa *raiz=NULL ;
//Pessoa *novo ;

string n;
int idade;

int main(int argc, char **argv){

  for (int i=0; i<=3; i++){

    Pessoa *novo;

    cout << "Insira nome" << endl;
    cin >> n;
    cout << "Insira idade" << endl;
    cin >> idade;

    novo = new Pessoa(n,idade);

    if (raiz == NULL){
      raiz = novo;
      } else {
          raiz->inserirfilho(novo);
      }

  }
  raiz->Ordem();
  cout << endl;
  return 0;
};

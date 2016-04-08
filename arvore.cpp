#include "pessoa.hpp"
#include <iostream>
#include <string>

Pessoa *raiz=NULL ;
<<<<<<< HEAD
//Pessoa *novo ;
=======
Pessoa *novo ;
>>>>>>> 234a9056b846971c6255d75634d5b3c6710143b1

string n;
int idade;

int main(int argc, char **argv){

<<<<<<< HEAD
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
=======

  novo=new Pessoa;
  cout << "informe o nome" << endl;
  cin >> n;
  novo->setnome(n);

  cout << "informe a idade" << endl;
  cin >> idade;
  novo->setidade(idade);
  if(raiz==NULL){
    raiz =novo;
  }else{
    novo->inserirfilho(novo);
  }

}
>>>>>>> 234a9056b846971c6255d75634d5b3c6710143b1

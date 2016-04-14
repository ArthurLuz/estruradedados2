#include "pessoa.hpp"
#include <iostream>
#include <string>

Pessoa *raiz=NULL ;
//Pessoa *novo ;
Pessoa *novo ;


string n;
int idade;

int main(int argc, char **argv){


  for (int i=0; i<=3; i++){

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

  //raiz->Ordem(raiz);
  cout << endl;
  int b;
  cout << "informe a idade q deseja buscar" << endl;
  cin >> b;

 novo->busca(raiz,b) ;




  return 0;

};

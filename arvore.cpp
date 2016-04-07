#include "pessoa.hpp"
#include <iostream>
#include <string>

Pessoa *raiz=NULL ;
Pessoa *novo ;

string n;
int idade;

int main(int argc, char **argv){


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

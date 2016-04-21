#include "pessoa.hpp"
#include <iostream>
#include <string>

Pessoa *raiz=NULL ;
Pessoa *novo,*b ;


string n;
int idade;

int main(int argc, char **argv){


  for (int i=0; i<=3; i++){

    novo = new Pessoa();
    cout << "informe o nome" << endl;
    cin >> n;
    novo->setnome(n);

    cout << "informe a idade" << endl;
    cin >> idade;
    novo->setidade(idade);
    if(raiz==NULL){
      raiz =novo;
    }else{
      raiz->inserirfilho(novo);
    }

  }

  //raiz->Ordem(raiz);


  cout << "imprimindo em ordem" << endl;
  raiz->Ordem();

  int k;
  cout << "digite uma idade pra buscar:" << endl;
  cin >> k;
  b=raiz->busca(k);
  if(b==NULL)
    cout << "pessoa não encontrada" << endl;
  else
    cout << "pessoa encontrada:"<< b->getnome()<<endl;



  return 0;

};

#include "pessoa.hpp"
#include <iostream>
#include <string>

Pessoa *raiz=NULL ;
Pessoa *novo,*b ;


string n;
int idade;

int main(int argc, char **argv){


  for (int i=0; i<7; i++){

    novo = new Pessoa();
    cout << "informe o nome" << endl;
    cin >> n;
    novo->setnome(n);

    cout << "informe a idade" << endl;
    cin >> idade;
    novo->setidade(idade);
    if(raiz==NULL){
      raiz =novo;
      novo->pai=NULL;
    }else{
      raiz->inserirfilho(novo);
    }

  }

  //raiz->Ordem(raiz);
  int imprimir =0;
  int op=1;
do{


  cout << "digite 1 pra ordem--- 2 pra posordem -----  3 pra PreOrdem" << endl;
  cin >> op;
  if (op==1)    raiz->Ordem();
  else if (op==2)  raiz->PreOrdem();
  else if(op==3)   raiz->PosOrdem();
  else cout << "digita opcao certa animal!!!"<<endl;
  cout << "se deseja imprimir denovo digite 1"<<endl;
  cin >> imprimir;
}while (imprimir==1);

  int k;
  cout << "digite uma idade pra buscar:" << endl;
  cin >> k;
  b=raiz->busca(k);
  if(b==NULL)
    cout << "pessoa não encontrada" << endl;
  else
    cout << "pessoa encontrada:"<< b->getnome()<<endl;

    b=raiz->busca(k);
    if(b==NULL)
      cout << "pessoa não encontrada" << endl;
    else
      cout << "pessoa encontrada:"<<raiz->removefilhofolha(b)<<endl;
      do{


        cout << "digite 1 pra ordem--- 2 pra posordem -----  3 pra PreOrdem" << endl;
        cin >> op;
        if (op==1)    raiz->Ordem();
        else if (op==2)  raiz->PreOrdem();
        else if(op==3)   raiz->PosOrdem();
        else cout << "digita opcao certa animal!!!"<<endl;
        cout << "se deseja imprimir denovo digite 1"<<endl;
        cin >> imprimir;
      }while (imprimir==1);


  return 0;

}

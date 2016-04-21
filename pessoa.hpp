#include <iostream>
#include <string>
using namespace std;

//modela classe
class Pessoa{
  protected:
  string nome;
  int idade;


//metodos da classe
  public:

    Pessoa *dir;
    Pessoa *esq;
    //construtor
  Pessoa(){
  nome="";
  idade=0;
  dir=NULL;
  esq=NULL;
  };
//construtor com parametros , polimorfismo do tipo sobrecarga
  Pessoa(string n, int i){
  nome=n;
  idade=i;
  dir=NULL;
  esq=NULL;
  };
//metodos destrutor
  ~Pessoa(){
      cout << "deletando instancia de pessoa." << endl;
  };
  //metodo para retornar nome
  string getnome(){
    return nome;
  };
  void setnome(string n ){
    nome=n;
  };
  float getidade(){
    return idade;
  };
  void setidade(int i){
    idade= i;
  };
  void inserirfilho(Pessoa *novo){
      if (this->idade >= novo->idade) {
        cout << " if " << endl;
          if(this->esq!=NULL){
            cout << "if ( 1 if " << endl;
            this->inserirfilho(novo);
          }else{
            this->esq = novo;
          }
      }else{
        cout << "else if " << endl;
        if(this->dir!=NULL){
          cout << "if ( 2 if " << endl;
          this->dir->inserirfilho(novo);
        }else{
          this->dir = novo;
        }
      }
  };
//============Impromir=========================================================
    void Ordem () {
      if(this->esq != NULL)
        this->esq->Ordem();

      cout << "nome: " <<this->getnome()<< endl;
      cout << "Idade: " << this->getidade() << endl;

      if(this->dir != NULL)
      this->dir->Ordem();
    };
    void PreOrdem () {
      cout << "nome: " <<this->getnome()<< endl;
      cout << "Idade: " << this->getidade() << endl;

      if(this->esq != NULL)
        this->esq->PreOrdem();

      if(this->dir != NULL)
      this->dir->PreOrdem();
    };
    void PosOrdem () {
      if(this->esq != NULL)
        this->esq->PosOrdem();

      if(this->dir != NULL)
      this->dir->PosOrdem();

      cout << "nome: " <<this->getnome()<< endl;
      cout << "Idade: " << this->getidade() << endl;
    };
    //============================================================================
    // deleteando posordem
    void Delete (){
      if (esq != NULL){
        this->esq->Delete();
      }//else return NULL;
       if (dir != NULL){
          this->dir->Delete();
        }//else return NULL;

      delete this;

    };

    Pessoa *busca (int k) {
    if ( this->idade == k){
        cout << "achou aki"  <<endl;
        return this;
      }else{
        if(k > this->idade){
            if(this->dir != NULL)
              this->dir->busca(k);
            else
              return NULL;
          }else{
            if(this->esq != NULL)
              this->esq->busca(k);
            else
              return NULL;
          }
      }
    };
    Pessoa *removefilho(int k){
      raiz->busca(k);
          // if(this->dir == NULL && this->esq==NULL)
          //   cout << "removendo :"<<this->getnome()<<endl;
          //   delete this;
          // else{
          //   if(this->dir == NULL && this->esq!=NULL){ //90
          //     if(this->esq->esq==NULL && this->esq->dir==NULL){// verifica se 80 tem filho
          //       this->esq->esq
          //     }
          //
          //   }
          // }
          if (raiz == NULL) {
                cout <<"Arvore vazia "<<endl;
            }
            if (k < raiz->getidade()) {
                this->esq = removefilho(this->esq->getidade());
            }
            else if (k > this->getidade()) {
                this->dir = remover(this->dir, k);
            }
            // else if (node.esquerda != null && node.direita != null){
            //     System.out.println("Removeu No com a matricula " + node.valor.matricula);
            //     node.valor.matricula = node.encontraMinimo(node.direita).valor.matricula;
            //     node.direita = node.removeMinimo(node.direita);
            // }
            // else {
            //     System.out.println("Removeu No com a matricula " + node.valor.matricula);
            //     node = (node.esquerda == null) ? node.esquerda : node.direita;
            // }
            // return node;


    };


};

  class Pessoafisica:public Pessoa{

// atributos da classe
  private:
    int CPF;
//metodos da classe
  public:
      Pessoafisica(){

      };
      Pessoafisica(string n, int i,int cpf){
        nome  = n;
        idade = i;
        CPF = cpf;
      };
//metodo destrutor
      ~Pessoafisica(){

      };

      int getcpf(){
        return CPF;
      };
      void settipocambio(int cpf){
        CPF = cpf;
      };
  };

  class Pessoajuridica:public Pessoa{

// atributos da classe
  private:
    int CNPJ;
//metodos da classe
  public:
      Pessoajuridica(){

      };
      Pessoajuridica(string n, int i,int cnpj){
        nome  = n;
        idade = i;
        CNPJ = cnpj;
      };
//metodo destrutor
      ~Pessoajuridica(){

      };

      int getcnpj(){
        return CNPJ;
      };
      void settipocambio(int cnpj){
        CNPJ = cnpj;
      };
  };

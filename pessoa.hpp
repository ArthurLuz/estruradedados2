#include <iostream>
#include <string>
using namespace std;

//modela classe
class Pessoa{
  protected:
  string nome;
  int idade;
  Pessoa *dir;
  Pessoa *esq;

//metodos da classe
  public:
//construtor
  Pessoa(){
  nome="";
  idade=0;
  dir==NULL;
  esq==NULL;
  };
//construtor com parametros , polimorfismo do tipo sobrecarga
  Pessoa(string n, int i){
  nome=n;
  idade=i;
  dir==NULL;
  esq==NULL;
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
      if (this->idade <= novo->idade) {
          if(esq==NULL){
            this->esq = novo;
          }else{
            this->inserirfilho(novo);
          }
      }else{
        if(dir==NULL){
          this->dir = novo;
        }else{
          this->inserirfilho(novo);
        }
      }
<<<<<<< HEAD

  };
  void Ordem (){
      if (esq != NULL){
        this->esq->Ordem();
      }
      cout << " " << this->nome;
      if (dir != NULL){
          this->dir->Ordem();
      }
    };
    // deleteando posordem
    void Delete (){
      if (esq != NULL){
        this->esq->Delete();
      }
      if (dir != NULL){
          this->dir->Delete();
      }
      delete this;
    };
=======
  };
>>>>>>> 234a9056b846971c6255d75634d5b3c6710143b1
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

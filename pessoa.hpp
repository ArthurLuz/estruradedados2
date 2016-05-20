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
    Pessoa *pai;
    int altura,equilibrio;
    //construtor
  Pessoa(){
  nome="";
  idade=0;
  dir=NULL;
  esq=NULL;
  pai=NULL;
  altura=equilibrio=0;
  };
//construtor com parametros , polimorfismo do tipo sobrecarga
  Pessoa(string n, int i){
  nome=n;
  idade=i;
  dir=NULL;
  esq=NULL;
  pai=NULL;
  altura=equilibrio=0;
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
      //cout << " if " << endl;
          if(this->esq!=NULL) this->esq->inserirfilho(novo);
          else{
            this->esq = novo;
            novo->pai = this;
            //Pessoa *aux=this;
            //  cout << "aux->pai="<< aux->pai<<endl;
            //  cout << "aux->dir=" <<aux->dir<<endl;
            //  cout << "aux->esq=" <<aux->esq<<endl;
            if(this->dir==NULL) this->altura++;

            vertam(this);
              // while(aux->pai!=NULL){
              //   if(aux->pai->dir==NULL){
              //     if
              //     aux->pai->altura++;
              //     aux=aux->pai;
              //   }
              // }
          }

      }else{
        //cout << "else if " << endl;
        if(this->dir!=NULL) this->dir->inserirfilho(novo);
        else{
          this->dir = novo;
          novo->pai = this;
          //Pessoa *aux2 = this;
          if(this->esq==NULL) this->altura++;

          vertam(this);
          // while(aux2->pai!=NULL){
          //   aux2->pai->altura++;
          //   aux2=aux2->pai;
          // }
        }
      }
  };
  void vertam(Pessoa *p){
    if(this->pai!=NULL){
      cout << "1 if"<<endl;
      if(this->pai->dir==this){
        cout << "2 if"<<endl;
        if(this->pai->esq!=NULL&&this->pai->esq->altura<=this->altura||this->pai->esq==NULL){
          cout << "3 if"<<endl;
          this->pai->altura++;
          //vertam(this->pai);
        }
      }else if(this->pai->esq==this){
        cout << "5 if"<<endl;
          if(this->pai->dir!=NULL&&this->pai->dir->altura<=this->altura||this->pai->dir==NULL){
            cout << "6 if"<<endl;
            this->pai->altura++;
          //  vertam(this->pai);

          }
      }
    }
  };
//============Impromir=========================================================
    void Ordem () {
      if(this->esq != NULL)
        this->esq->Ordem();

      cout << "nome: " <<this->getnome()<<  "  | Idade: " << this->getidade() <<  "  | altura: " <<this->altura <<endl;

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
    Pessoa *removefilhofolha(Pessoa *e){
        //============== Metodo Apaga folha =================
        if(e->dir==NULL && e->esq==NULL){
            if(e->pai->dir==e){
                e->pai->dir=NULL;
                delete e;
                cout <<"filho deletado!"<<endl;
            }else{
                e->pai->esq=NULL;
                delete e;
                cout <<"filho deletado!!"<<endl;
            }
        }
    };
    Pessoa *remove1filho(Pessoa *e){
        if(e->esq == NULL){ // verifica se o filho esta na esquerda ou direita
          e->dir->pai = e->pai; //o pai do filho q vai ser deletado passa a ser o avo
          if(e->pai->dir == e){
            e->pai->dir= e->dir; //pai do e recebe o filho do e como filho
          }else{
            e->pai->esq = e->dir;
          }
          delete e;

        }else{
            e->esq->pai = e->pai;
          if(e->pai->esq == e){
            e->pai->esq = e->esq;
          }else{
            e->pai->dir = e->esq;
          }
          delete e;
        }
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

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
            //setaltura(this);
            //cout << "altif : " <<this->altura<<endl;
          }

      }else{
        //cout << "else if " << endl;
        if(this->dir!=NULL) this->dir->inserirfilho(novo);
        else{
          this->dir = novo;
          novo->pai = this;
          //setaltura(this);
          //cout << "altelse : " <<this->altura<<endl;
        }
      }
  };/*
  void setaltura(Pessoa *P){
      if(this->esq != NULL)     this->esq->Ordem();

      if(this->dir != NULL)     this->dir->Ordem();
  };*/
  int vertam(Pessoa *h){
    int u, v;
    if (h == NULL) return -1;
    u = vertam(h->esq);
    v = vertam(h->dir);
    this->equilibrio=v-u;
    //cout<<"equi: "<<this->equilibrio<<endl;
    if (u > v) return u+1;
    else return v+1;
  };
//============AO MESMO TEMPO Q SETA A VARIAVEL EQUILIBRIO JA VAI EQUILIBRANDO A ARVORE========

    void equilibrar () {
      if(this->esq != NULL)      this->esq->equilibrar();
      this->altura=vertam(this);
      if(-1<=this->equilibrio<=1){
        if (this->equilibrio>1){
            if(this->dir->equilibrio<0){
                //ROTA플O DUPLA A ESQUERDA
            }else{
                if(raiz==this){
                    raiz = this->dir;
                    if(raiz->esq==NULL){
                        raiz->esq=this;
                        raiz->pai=NULL;
                        this->pai=raiz;
                    }else{
                        this->dir=raiz->esq;
                        this->pai=raiz;
                        this->dir->pai=this;
                        raiz->esq=this;
                    }
                    //this->dir->esq=this->dir->pai;
                }
                //ROTA플O A ESQUERDA
            }
        }else{
            if(this->esq->equilibrio>0){
                //ROTA플O DUPLA A DIREITA
            }else{
                //ROTA플O A DIRTEITA
            }
        }
            //cout << "nome: " <<this->getnome()<<  "  | Idade: " << this->getidade() <<  "  | altura: " <<this->altura <<  "  | equi: " <<this->equilibrio <<endl;
      }
      if(this->dir != NULL)      this->dir->equilibrar();
    };
    //__________________________________________________________________________________
    void Ordem () {
      if(this->esq != NULL)      this->esq->Ordem();

        cout << "nome: " <<this->getnome()<<  "  | Idade: " << this->getidade() <<  "  | altura: " <<this->altura <<  "  | equi: " <<this->equilibrio <<endl;

      if(this->dir != NULL)      this->dir->Ordem();
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

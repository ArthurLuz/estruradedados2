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

    void inserirfilho(Pessoa *pessoas){

        if(this->idade>=pessoas->idade){
                if(this->esq!=NULL){
                    this->esq->inserirfilho(pessoas);
                }
                else{
                    this->esq=pessoas;
                }

        }
        else{
             if(this->dir!=NULL){
                    this->dir->inserirfilho(pessoas);
                }
                else{
                    this->dir=pessoas;
                }
        }

};
  int vertam(Pessoa *h){
    int u, v;
    if (h == NULL) return -1;
    u = vertam(h->esq);
    v = vertam(h->dir);
    //this->equilibrio=v-u;
    if (u > v) return u+1;
    else return v+1;
  };
//============AO MESMO TEMPO Q SETA A VARIAVEL EQUILIBRIO JA VAI EQUILIBRANDO A ARVORE========


    void rotacaoESQ(Pessoa *p){
        Pessoa *b = this->dir;
        this->dir = b->esq;
        b->esq=this;
        p=b;
    };
    void rotacaoDIR(Pessoa *p){
        Pessoa *b = this->esq;
        this->esq=b->dir;
        b->dir=this;
        p=b;
    };
    void rotacao2ESQ(Pessoa *p){
        rotacaoDIR(this->dir);
        rotacaoESQ(this);
    };
    void rotacao2DIR(Pessoa *p){
        rotacaoESQ(this->esq);
        rotacaoDIR(this);
    };
     void rotacionar(Pessoa *p){
        if (this->equilibrio>1){
            if(this->dir->equilibrio<0){
                rotacao2ESQ(this);
            }else{
                rotacaoESQ(this);
            }
        }else{
            if(this->esq->equilibrio>0){
                rotacao2DIR(this);
            }else{
                rotacaoDIR(this);
            }
        }
    };
    //__________________________________________________________________________________
    void Ordem () {
      if(this->esq != NULL)      this->esq->Ordem();
      //this->altura=vertam(this);


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

    };
    };
};

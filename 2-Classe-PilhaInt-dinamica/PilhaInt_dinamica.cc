#include <iostream>




using namespace std;

class PilhaInt
{ 
  public:

    PilhaInt (int tamanho = 10): tamanho(tamanho), tab((int*) malloc(tamanho * sizeof(int))) { // construtor
      for(int i=0;i<tamanho;i++) {
        tab[i] = 0;
      }
    }

    PilhaInt (const PilhaInt &p) { // construtor de copia
      this->tamanho = p.tamanho;
      this->atual = p.atual;
      this->tab = (int*) malloc(tamanho * sizeof(int));
      for(int i=0;i< this->atual; i++) {
        this->tab[i] = p.tab[i];
      }
    }

    const PilhaInt& operator= (const PilhaInt& p) { // sobrecarga do operador de atribuicao
      if(this == &p) return *this;
      this->tamanho = p.tamanho;
      this->atual = p.atual;
      free(this->tab);
      this->tab = (int*) malloc(tamanho * sizeof(int));
      for( int i=0; i<this->atual; i++ )
        this->tab[i]=p.tab[i];
      return *this;
    }

    ~PilhaInt () {
      free(tab);
    }

    void redimensiona(int n) {
      if(n > this->tamanho) {
        int *aux = (int*) malloc(n * sizeof(int));
        for( int i=0; i<this->tamanho; i++ )
          aux[i] = this->tab[i];
        free(this->tab);
        this->tab = aux;
        this->tamanho = n;
        return;
      }
      int *aux = (int*) malloc(n * sizeof(int));
      for( int i=0; i<n; i++ ) {
        aux[i] = this->tab[i];
      }
      free(this->tab);
      this->tab = aux;
      this->tamanho = n;
      this->atual = n;
    }

    int capacidade() {
      return tamanho;
    }

    void duplica() {
      int n = 2*this->tamanho;
      int *aux = (int*) malloc(n * sizeof(int));
      for( int i=0; i<this->tamanho; i++ )
        aux[i] = this->tab[i];
      free(this->tab);
      this->tab = aux;
      this->tamanho = n;
    }

    void empilha( int valor ) {
      if(this->atual>=this->tamanho)
        duplica();
      tab[this->atual++] = valor;
      
    }
  
    int desempilha() {
      return this->tab[--this->atual];
    }

    void print( ostream& o ) {
      o << "[ ";
      for(int i = 0; i < this->atual; i++) {
        o << tab[i];
        if(i<this->atual-1)
          o << ", ";
      }
      o << " ]";
    }


    PilhaInt& operator<< ( int valor ) {
      empilha( valor );
      return *this;
    }


  private:
    int tamanho;
    int *tab;
    int atual = 0;
};






int main(int argc, char **argv) {
  // PilhaInt p;
  // p << 19 << 18 << 17 << 30;

  // p.print( cout );
  // cout << endl;

  // PilhaInt a(5), b(15);
  // cout << a.capacidade() << endl;
  // cout << b.capacidade() << endl;

  //   PilhaInt a{7}, b{500000}, c{5};
  //   a << 8 << 3 << 1 << 4 << 5;
  //   for( int i = 0; i < b.capacidade(); i++ )
  //     b << i;
  //   a = b;

  // PilhaInt a{81};
  // a << 5 << 6 << 3 << 2 << 9 << 13;
  // a.duplica(); cout << a.capacidade() << endl;
  // a.print(cout);
  // a.redimensiona( 11 ); cout << a.capacidade() << endl;
  // a.redimensiona( 6 ); cout << a.capacidade() << endl;
  // a.print( cout ); cout << endl;
  // a.redimensiona( 3 ); cout << a.capacidade() << endl;
  // a.print( cout ); cout << endl;

  PilhaInt a{3};
  a << 24;
  a << 24;
  a << 24;
  a << 24;
  a << 24;
  a << 24;
  a << 24;
  a.print( cout );
  cout << a.capacidade() << endl;
}
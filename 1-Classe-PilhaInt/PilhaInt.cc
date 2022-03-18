#include <iostream>




using namespace std;

#define MAX_PILHA 10

class PilhaInt
{ 
  public:

    PilhaInt() {}

    void empilha( int valor ) {
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

    const PilhaInt& operator= (const PilhaInt& p) {
      this->atual = p.atual;
      for( int i=0; i<this->atual; i++ )
        this->tab[i]=p.tab[i];
      return *this;
    }

    PilhaInt& operator<< ( int valor ) {
      empilha( valor );
      return *this;
    }


  private:
    int tab[MAX_PILHA];
    int atual = 0;
};






int main(int argc, char **argv) {
  PilhaInt p;
  p << 19 << 18 << 17 << 30;

  p.print( cout );
  cout << endl;
}
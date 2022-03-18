#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class PilhaInt
{
public:
  PilhaInt(int capacidade = 10)
  {
    tab.reserve(capacidade);
  }

  PilhaInt(const PilhaInt &p)
  {
    for (unsigned int i = 0; i < p.tab.size(); i++)
    {
      this->tab.push_back(p.tab[i]);
    }
  }

  const PilhaInt &operator=(const PilhaInt &p)
  {
    if (this == &p)
      return *this;
    vector<int> tmp;
    this->tab.swap(tmp);
    this->tab.reserve(p.tab.capacity());
    for (unsigned int i = 0; i < p.tab.size(); i++)
      this->tab.push_back(p.tab[i]);
    return *this;
  }

  ~PilhaInt()
  {
  }

  int capacidade()
  {
    return tab.capacity();
  }

  void empilha(int valor)
  {
    tab.push_back(valor);
  }

  int desempilha()
  {
    int retorno = tab.back();
    tab.pop_back();
    return retorno;
  }

  void print(ostream &o) const
  {
    o << "[ ";
    for (unsigned int i = 0; i < this->tab.size(); i++)
    {
      o << tab[i];
      if (i < this->tab.size() - 1)
        o << ", ";
    }
    o << " ]";
  }

  PilhaInt &operator<<(int valor)
  {
    empilha(valor);
    return *this;
  }

  void redimensiona(unsigned int valor)
  {
    if (valor >= this->tab.capacity())
      this->tab.reserve(valor);
    else
    {
      vector<int> tmp;
      tmp.reserve(valor);
      for (unsigned int i = 0; i < valor; i++)
      {
        tmp.push_back(this->tab[i]);
      }
      this->tab.swap(tmp);
    }
  }

private:
  vector<int> tab;
};

// PilhaInt embaralha(PilhaInt q)
PilhaInt embaralha(PilhaInt q)
{
  int aux = q.desempilha();
  q << 32 << 9 << aux;

  return q;
}

int main(int argc, char **argv)
{

  PilhaInt a{7}, b{5000}, c{5};
  a << 8 << 3 << 1 << 4 << 5;
  for (int i = 0; i < 5000; i++)
    b << i;
  c = a;
  a = b;
  b = c;
  cout << a.capacidade() << ", " << b.capacidade() << ", " << c.capacidade() << endl;

  // PilhaInt a{81};
  // a << 5 << 6 << 3 << 2 << 9 << 13;
  // a.redimensiona(81);
  // cout << a.capacidade() << endl;
  // a.redimensiona(11);
  // cout << a.capacidade() << endl;
  // a.redimensiona(6);
  // cout << a.capacidade() << endl;
  // a.print(cout);
  // cout << endl;
  // a.redimensiona(3);
  // cout << a.capacidade() << endl;
  // a.print(cout);
  // cout << endl;

  // PilhaInt a{7}, b{500}, c{5};
  // a << 8 << 3 << 1 << 4 << 5;
  // b << 1 << 2 << 3;
  // c = a;
  // a = b;
  // b = c;
  // c.desempilha();
  // c << 7;
  // a.print(cout);
  // cout << endl;
  // b.print(cout);
  // cout << endl;
  // c.print(cout);
  // cout << endl;

  // PilhaInt p;
  // p.empilha(1);
  // p << 3 << 9 << 13 << 89;
  // cout << p.desempilha() << endl;
  // cout << p.desempilha() << endl;
  // p.print(cout);
  // p << 19 << 18 << 17 << 30;
  // stringstream ss;
  // p.print(ss);
  // cout << endl
  //      << "{" << ss.str() << "}" << endl;

  // PilhaInt a(5), b(15);
  // cout << a.capacidade() << endl;
  // cout << b.capacidade() << endl;

  // PilhaInt a(10);
  // a << 1 << 2 << 3 << 4;
  // embaralha(a);

  // PilhaInt a(7);
  // a << 3 << 5 << 13 << 19;
  // PilhaInt b{embaralha(a)};
  // a.print(cout);
  // cout << endl;
  // b.print(cout);
  // cout << endl;

  // PilhaInt b{embaralha(a)};
  // a.print(cout);
  // cout << endl;
  // b.print(cout);
  // cout << endl;

  // PilhaInt p;
  // p << 19 << 18 << 17 << 30;

  // p.print(cout);
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

  // PilhaInt a{3};
  // a << 24;
  // a << 24;
  // a << 24;
  // a << 24;
  // a << 24;
  // a << 24;
  // a << 24;
  // a.print( cout );
  // cout << a.capacidade() << endl;
}
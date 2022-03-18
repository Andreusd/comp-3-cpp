#include <iostream>
#include <initializer_list>

using namespace std;

class AbstractPair
{
public:
  virtual void imprime(ostream &o) = 0;
};

template <typename A, typename B>
class ImplPair : public AbstractPair
{
public:
  ImplPair(A a, B b) : primeiro(a), segundo(b) {}
  void imprime(ostream &o)
  {
    o << primeiro << " = " << segundo << endl;
  }

private:
  A primeiro;
  B segundo;
};

class Pair
{
public:
  template <typename A, typename B>
  Pair(A a, B b)
  {
    p = new ImplPair<A, B>(a, b);
  }
  void imprime(ostream &o)
  {
    p->imprime(o);
  }

private:
  AbstractPair *p;
};

void print(ostream &o, initializer_list<Pair> lista)
{
  for (auto par : lista)
  {
    par.imprime(o);
  }
}

int main()
{

  Pair p("1", 2);

  print(cout, {{"jan", 1}, {2, "fev"}, {string("pi"), 3.14}});

  return 0;
}
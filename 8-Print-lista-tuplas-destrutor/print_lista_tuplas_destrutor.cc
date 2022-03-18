#include <iostream>
#include <initializer_list>
#include <memory>

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
  ImplPair(A &a, B &b) : primeiro(a), segundo(b) {}
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
    p = shared_ptr<AbstractPair>(new ImplPair<A, B>(a, b));
  }
  void imprime(ostream &o)
  {
    p->imprime(o);
  }

private:
  shared_ptr<AbstractPair> p;
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
  print(cout, {{"jan", "leak"}, {"pi", "leak"}});

  return 0;
}
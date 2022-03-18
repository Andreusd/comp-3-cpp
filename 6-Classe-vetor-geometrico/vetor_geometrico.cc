#include <iostream>
#include <initializer_list>

using namespace std;

template <int N, typename T>
class Vetor;

template <int N, typename T>
class MeioDoProdutoVetorial
{
public:
  MeioDoProdutoVetorial(Vetor<N, T> *v) : _v(v) {}
  Vetor<N, T> &v() { return *_v; }

private:
  Vetor<N, T> *_v;
};

template <int N, typename T>
class Vetor
{
public:
  Vetor() {}
  Vetor(const initializer_list<T> &lista)
  {
    for (int i = 0; i < N; i++)
    {
      tab[i] = *(lista.begin() + i);
    }
  }
  const Vetor &operator=(const initializer_list<T> &lista)
  {
    for (int i = 0; i < N; i++)
    {
      tab[i] = *(lista.begin() + i);
    }
    return *this;
  }
  T &operator[](int n)
  {
    return tab[n];
  }
  Vetor operator+(Vetor outro)
  {
    Vetor soma;
    for (int i = 0; i < N; i++)
    {
      soma[i] = (*this)[i] + outro[i];
    }
    return soma;
  }
  Vetor operator-(Vetor outro)
  {
    return *this;
  }
  int operator*(Vetor outro)
  {
    int retorno = 0;
    for (int i = 0; i < N; i++)
      retorno += (*this)[i] * outro[i];
    return retorno;
  }
  MeioDoProdutoVetorial<N, T> operator*()
  {
    return MeioDoProdutoVetorial<N, T>(this);
  }
  Vetor operator*(MeioDoProdutoVetorial<N, T> outro)
  {
    Vetor &a = *this;
    Vetor &b = outro.v();
    Vetor resultado{a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
    return resultado;
  }
  Vetor operator*(auto n)
  {
    Vetor novo;
    for (int i = 0; i < N; i++)
    {
      novo[i] = (*this)[i] * n;
    }
    return novo;
  }

private:
  T tab[N];
};

template <int N, typename T>
ostream &operator<<(ostream &o, Vetor<N, T> v)
{
  for (int i = 0; i < N; i++)
    o << v[i] << " ";
  return o;
}

template <int N, typename T>
Vetor<N, T> operator*(double n, Vetor<N, T> v)
{
  return v * n;
}

int main()
{
  Vetor<3, double> a{-1, 2, 1};
  Vetor<3, double> b{1, 2, 3};

  cout << a * *b;
}
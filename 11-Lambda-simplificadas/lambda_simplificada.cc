#include <iostream>
#include <vector>
#include <type_traits>
#include <functional>
#include <map>

using namespace std;

template <typename V, typename F>
auto operator|(const V &iteravel, F func)
{
  auto primeiro = *begin(iteravel);
  if constexpr (is_same_v<invoke_result_t<F, decltype(*begin(iteravel))>, bool>)
  {
    vector<decltype(primeiro)> v;
    for (const auto &item : iteravel)
    {
      if (invoke(func, item))
      {
        v.push_back(item);
      }
    }
    return v;
  }
  else if constexpr (is_same_v<invoke_result_t<F, decltype(*begin(iteravel))>, void>)
  {
    for (const auto &item : iteravel)
      invoke(func, item);
  }
  else
  {
    vector<invoke_result_t<F, decltype(primeiro)>> v;
    for (const auto &item : iteravel)
      v.push_back(invoke(func, item));
    return v;
  }
}

template <typename F>
class Expr
{
public:
  Expr(F f) : f(f) {}
  auto operator()(auto v) const
  {
    return f(v);
  }

private:
  F f;
};

template <typename A, typename B>
auto operator+(Expr<A> a, Expr<B> b)
{
  return Expr{[a, b](auto v)
              { return a(v) + b(v); }};
};

template <typename A, typename B>
auto operator+(Expr<A> a, B b)
{
  return Expr{[a, b](auto v)
              { return a(v) + b; }};
};

template <typename A, typename B>
auto operator*(Expr<A> a, Expr<B> b)
{
  return Expr{[a, b](auto v)
              { return a(v) * b(v); }};
};

template <typename A, typename B>
auto operator%(Expr<A> a, B b)
{
  return Expr{[a, b](auto v)
              { return a(v) % b; }};
};

template <typename A, typename B>
auto operator==(Expr<A> a, B b)
{
  return Expr{[a, b](auto v)
              { return a(v) == b; }};
};

template <typename T>
class OStream
{
public:
  OStream(ostream &o, T t) : o(o), t(t) {}
  void operator()(auto v)
  {
    o << t(v);
    o << after_buffer;
  }
  void coloca_depois(char c)
  {
    after_buffer += c;
  }

private:
  ostream &o;
  T t;
  string after_buffer = "";
};

template <typename A, enable_if_t<!is_same_v<A, string>, bool> = true>
OStream<A> operator<<(ostream &o, A t)
{
  return OStream<A>(o, t);
}

template <typename A>
auto operator<<(OStream<A> a, const char &c)
{
  a.coloca_depois(c);
  return a;
}

auto x = Expr{[](auto v)
              { return v; }};

auto cte(auto valor)
{
  return Expr{[valor](auto x)
              { return valor; }};
}

int main()
{

  vector<int> v1 = {1, 2, 3, 4, 1, 1, 0, 8};

  v1 | (x % 2 == 0) | cout << x * x + 1 << ' ';
}
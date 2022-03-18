#include <iostream>
#include <vector>
#include <initializer_list>
#include <map>

using namespace std;

auto apply(const auto &iteravel, auto func)
{
  vector<decltype(func(*begin(iteravel)))> saida;
  for (auto i = begin(iteravel); i != end(iteravel); i++)
  {
    saida.push_back(func(*i));
  }
  return saida;
}

auto apply(const initializer_list<int> &iteravel, auto func)
{
  vector<decltype(func(*iteravel.begin()))> saida;
  for (auto i = iteravel.begin(); i != iteravel.end(); i++)
  {
    saida.push_back(func(*i));
  }
  return saida;
}

int id(int n) { return n; }

int main()
{
  // vector<int> l1 = {1, 2, 3};
  // apply(l1, quadrado);
  // vector<int> v{1, 2, 3, 4, 5};
  // vector<int> r = apply(v, quadrado);
  int v[] = {1, 2, 3, 4, 5};
  vector<int> r = apply(v, id);
  for (auto x : r)
  {
    cout << x << endl;
  }
}
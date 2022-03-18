#include <iostream>
#include <vector>

using namespace std;

void operator|(auto &iteravel, auto func)
{
  for (auto i = begin(iteravel); i != end(iteravel); i++)
  {
    func(*i);
  }
}

int main()
{
  int tab[10] = {1, 2, 3, 2, 3, 4, 6, 0, 1, 8};
  tab | [](int x)
  { cout << x * x << endl; };
}
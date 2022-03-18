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
  if constexpr(is_same_v<invoke_result_t<F, decltype(*begin(iteravel))>,bool>) {
    vector<decltype(primeiro)> v;
    for(const auto &item : iteravel) {
      if(invoke(func,item)) {
        v.push_back(item);
      }
    }
    return v;
  } 
  else if constexpr(is_same_v<invoke_result_t<F, decltype(*begin(iteravel))>,void>) {
    for(const auto &item : iteravel)
      invoke(func,item);
  }
  else {
    vector<invoke_result_t<F, decltype(primeiro)>> v;
    for(const auto &item : iteravel)
      v.push_back(invoke(func,item));
    return v;
  }
}

int main()
{
  int v1[] = { 2, 9, 8, 8, 7, 4 };
  v1 | []( int x ) { return x % 2 == 0; } | [] ( int x ) { cout << x << " "; };
}
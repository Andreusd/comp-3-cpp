#include <iostream>
#include <functional>

using namespace std;

template <typename F>
class Bind;

template <typename F>
auto bind(F f){
  return Bind(f);
}

template <typename F,typename ...P>
auto bind(F func,P ...params){
  if constexpr (is_invocable_v<F,P...>) {
    return invoke(func,params...);
  } else if constexpr(is_class_v<F>){
    return Bind{ [&func,params...](auto ...args){ return invoke(func,params...,args...);} };
  } else {
    return Bind{ [func,params...](auto ...args){ return invoke(func,params...,args...);} };
  }
}

template <typename F>
class Bind {
	public:
		Bind(F f):f(f){}
    
		template<typename ...P>
		auto operator()(P ...args){
			if constexpr (is_invocable_v<F,P...>){
				return invoke(f,args...);
      } else {
        return ::bind(f,args...);
		  }
    }
	private:
		F f;
};


















int mdc( int a, int b ) { return b == 0 ? a : mdc( b, a%b ); };

struct MMC {
  auto operator()( long a, long b ) { return a*b/mdc(a,b); }    
};

int main() {
  MMC mmc;
  auto f1 = ::bind( mmc, 6 );
  for( int i = 2; i <= 12; i++ )
    cout << f1( i ) << " ";

}
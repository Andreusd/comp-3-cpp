#include <iostream>
#include <math.h>

using namespace std;

class X {
public:
  double e( double v ) {
    return v;
  }
  
  double dx( double v ) {
    return 1;
  }

  string str() const {
    return "x";
  }

	string dx_str() const {
    return "1";
  }
};

class Cte {
public:
  Cte( double c ): c(c) {}

  double e( double v ) {
    return c;
  }
  
  double dx( double v ) {
    return 0;
  }

  string str() const{
    return remove_zeros_desnecessarios(to_string(c));
  }

  string dx_str() const{
    return "0";
  }

private:
  double c;

  string remove_zeros_desnecessarios(string str) const {
    str = str.substr(0, str.find_last_not_of('0')+1);
    if(str.find('.') == str.size()-1)
    {
        str = str.substr(0, str.size()-1);
    }
    return str;
  }
};

template <typename F1, typename F2>
class Multiplicacao {
public:
  Multiplicacao( F1 f1, F2 f2 ): f1(f1), f2(f2) {}
  
  double e( double v ) {
    return f1.e(v) * f2.e(v);
  }

  double dx( double v ) {
    return f1.e(v)*f2.dx(v) + f1.dx(v)*f2.e(v);
  }

  string str() const{
    return "(("+f1.str()+")*("+f2.str()+"))";
  }

  string dx_str() const{
    return "(("+f1.dx_str()+")*("+f2.str()+")+("+f1.str()+")*("+f2.dx_str()+"))";
  }
  
private:
  F1 f1;
  F2 f2;
};

template <typename F1, typename F2> 
Multiplicacao<F1,F2> operator * ( F1 f1, F2 f2 ) {
   return Multiplicacao<F1,F2>( f1, f2 );
}

template <typename F2> 
Multiplicacao<Cte,F2> operator * ( double n, F2 f2 ) {
   return Multiplicacao<Cte,F2>( n, f2 );
}

template <typename F2> 
Multiplicacao<Cte,F2> operator * ( int n, F2 f2 ) {
   return Multiplicacao<Cte,F2>( n, f2 );
}

template <typename F1> 
Multiplicacao<F1,Cte> operator * ( F1 f1, double n ) {
   return Multiplicacao<F1,Cte>( f1, n );
}

template <typename F1, typename F2>
class Divisao {
public:
  Divisao( F1 f1, F2 f2 ): f1(f1), f2(f2) {}
  
  double e( double v ) {
    return f1.e(v) / f2.e(v);
  }

  double dx( double v ) {
    return (f1.dx(v)*f2.e(v) - f1.e(v)*f2.dx(v)) / (f2.e(v)*f2.e(v));
  }

  string str() const{
    return "(("+f1.str()+")/("+f2.str()+"))";
  }

  string dx_str() const{
    return "((("+f1.dx_str()+")*("+f2.str()+")-("+f1.str()+")*("+f2.dx_str()+"))/"+f2.str()+"^2)";
  }
  
private:
  F1 f1;
  F2 f2;
};

template <typename F1, typename F2> 
Divisao<F1,F2> operator / ( F1 f1, F2 f2 ) {
   return Divisao<F1,F2>( f1, f2 );
}

template <typename F2> 
Divisao<Cte,F2> operator / ( double n, F2 f2 ) {
   return Divisao<Cte,F2>( n, f2 );
}

template <typename F2> 
Divisao<Cte,F2> operator / ( int n, F2 f2 ) {
   return Divisao<Cte,F2>( n, f2 );
}

template <typename F1> 
Divisao<F1,Cte> operator / ( F1 f1, double n ) {
   return Divisao<F1,Cte>( f1, n );
}

template <typename F1, typename F2>
class Soma {
public:
  Soma( F1 f1, F2 f2 ): f1(f1), f2(f2) {}
  
  double e( double v ) {
    return f1.e(v) + f2.e(v);
  }

  double dx( double v ) {
    return f2.dx(v) + f1.dx(v);
  }

  string str() const{
    return "(("+f1.str()+")+("+f2.str()+"))";
  }

  string dx_str() const{
    return "(("+f1.dx_str()+")+("+f2.dx_str()+"))";
  }
  
private:
  F1 f1;
  F2 f2;
};

template <typename F1, typename F2> 
Soma<F1,F2> operator + ( F1 f1, F2 f2 ) {
   return Soma<F1,F2>( f1, f2 );
}

template <typename F2> 
Soma<Cte,F2> operator + ( double n, F2 f2 ) {
   return Soma<Cte,F2>( n, f2 );
}

template <typename F2> 
Soma<Cte,F2> operator + ( int n, F2 f2 ) {
   return Soma<Cte,F2>( n, f2 );
}

template <typename F1> 
Soma<F1,Cte> operator + ( F1 f1, double n ) {
   return Soma<F1,Cte>( f1, n );
}

template <typename F1, typename F2>
class Subtracao {
public:
  Subtracao( F1 f1, F2 f2 ): f1(f1), f2(f2) {}
  
  double e( double v ) {
    return f1.e(v) - f2.e(v);
  }

  double dx( double v ) {
    return f2.dx(v) - f1.dx(v);
  }

  string str() const {
    return "(("+f1.str()+")-("+f2.str()+"))";
  }

  string dx_str() const {
    return "(("+f1.dx_str()+")-("+f2.dx_str()+"))";
  }
  
private:
  F1 f1;
  F2 f2;
};

template <typename F1, typename F2> 
Subtracao<F1,F2> operator - ( F1 f1, F2 f2 ) {
   return Subtracao<F1,F2>( f1, f2 );
}

template <typename F2> 
Subtracao<Cte,F2> operator - ( double n, F2 f2 ) {
   return Subtracao<Cte,F2>( n, f2 );
}

template <typename F1> 
Subtracao<F1,Cte> operator - ( F1 f1, double n ) {
   return Subtracao<F1,Cte>( f1, n );
}

template <typename F1> 
Subtracao<F1,Cte> operator - ( F1 f1, int n ) {
   return Subtracao<F1,Cte>( f1, n );
}

template <typename F1>
class Potenciacao {
public:
  Potenciacao( F1 f1, int f2 ): f1(f1), f2(f2) {}
  
  double e( double v ) {
    return pow(f1.e(v),f2);
  }

  double dx( double v ) {
    return f2*pow(f1.e(v),f2-1)*f1.dx(v);
  }

  string str() const {
    return "("+f1.str()+")^"+to_string(f2);
  }

  string dx_str() const {
    return "("+to_string(f2)+"*("+f1.dx_str()+")*("+f1.str()+")^"+to_string(f2-1)+")";
  }
  
private:
  F1 f1;
  int f2;
};

template <typename F1, typename F2> 
Potenciacao<F1> operator ->* ( F1 f1, F2 f2 ) {
  static_assert( is_same_v< F2, int > , "Operador de potenciação definido apenas para inteiros");
  return Potenciacao<F1>( f1, f2 );
}

template <typename F1>
class Seno {
public:
  Seno( F1 f1 ): f1(f1)  {}
  
  double e( double v ) {
    return sin(f1.e(v));
  }

  double dx( double v ) {
    return cos(f1.e(v))*f1.dx(v);
  }

  string str() const{
    return "sin("+f1.str()+")";
  }

  string dx_str() const{
    return "(cos("+f1.str()+")*"+f1.dx_str()+")";
  }
  
private:
  F1 f1;
};

template <typename F1> 
Seno<F1> sin( F1 f1 ) {
   return Seno<F1>( f1 );
}

template <typename F1>
class Cosseno {
public:
  Cosseno( F1 f1 ): f1(f1)  {}
  
  double e( double v ) {
    return cos(f1.e(v));
  }

  double dx( double v ) {
    return -sin(f1.e(v))*f1.dx(v);
  }

  string str() const{
    return "cos("+f1.str()+")";
  }

  string dx_str() const{
    return "(-sin("+f1.str()+")*"+f1.dx_str()+")";
  }
  
private:
  F1 f1;
};

template <typename F1> 
Cosseno<F1> cos( F1 f1 ) {
   return Cosseno<F1>( f1 );
}

template <typename F1>
class Exponenciacao {
public:
  Exponenciacao( F1 f1 ): f1(f1) {}
  
  double e( double v ) {
    return exp(f1.e(v));
  }

  double dx( double v ) {
    return f1.dx(v)*exp(f1.e(v));
  }

  string str() const{
    return "exp^("+f1.str()+")";
  }

  string dx_str() const{
    return "(exp("+f1.str()+")*("+f1.dx_str()+"))";
  }
  
private:
  F1 f1;
};

template <typename F1> 
Exponenciacao<F1> exp( F1 f1 ) {
   return Exponenciacao<F1>( f1 );
}

template <typename F1>
class Logaritmizacao {
public:
  Logaritmizacao( F1 f1 ): f1(f1) {}
  
  double e( double v ) {
    return log(f1.e(v));
  }

  double dx( double v ) {
    return 1/f1.e(v);
  }

  string str() const{
    return "log("+f1.str()+")";
  }

  string dx_str() const{
    return "(1/("+f1.str()+"))*("+f1.dx_str()+")";
  }
  
private:
  F1 f1;
};

template <typename F1> 
Logaritmizacao<F1> log( F1 f1 ) {
   return Logaritmizacao<F1>( f1 );
}

X x;


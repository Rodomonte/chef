// PLANEDIV

#include <stdio.h>
#include <map>

using std::map;

#define gc getchar_unlocked
#define _mi map<int,int>
#define _mmi map<int,_mi >
#define _mmmi map<int,_mmi >
#define _mmmmi map<int,_mmmi >

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}
int abs(int a){
  return (a < 0) ? -a : a;
}
int max(int a, int b){
  return (a > b) ? a : b;
}
int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}

int main(){
  int T,N,A,B,C, i,g,g2,r;
  _mmmmi m;
  _mmmmi::iterator it;
  _mmmi::iterator jt;
  _mmi::iterator kt;
  _mi::iterator lt;

  T = getn();
  while(T--){
    m.clear();
    N = getn();
    for(i = 0; i < N; ++i){
      A = getn(), B = getn(), C = getn();

      if(A && B){
  if(B < 0)
    A = -A, B = -B, C = -C;
  g = gcd(abs(A), B);
  A /= g, B /= g;
  if(C){
    g2 = gcd(abs(C), g);
    C /= g2, g /= g2;
  }else
    g = 1;
      }else if(!A){
  if(B < 0)
    B = -B, C = -C;
  if(C){
    g = B;
    g2 = gcd(abs(C), g);
    C /= g2, g /= g2;
  }else
    g = 1;
  B = 1;
      }else{
  if(A < 0)
    A = -A, C = -C;
  if(C){
    g = A;
    g2 = gcd(abs(C), g);
    C /= g2, g /= g2;
  }else
    g = 1;
  A = 1;
      }

      it = m.find(A);
      if(it == m.end()){
  _mi t;
  t[g] = 1;
  _mmi t2;
  t2[C] = t;
  _mmmi t3;
  t3[B] = t2;
  m[A] = t3;
      }else{
        jt = it->second.find(B);
  if(jt == it->second.end()){
    _mi t;
    t[g] = 1;
    _mmi t2;
    t2[C] = t;
    it->second[B] = t2;
  }else{
    kt = jt->second.find(C);
    if(kt == jt->second.end()){
      _mi t;
      t[g] = 1;
      jt->second[C] = t;
    }else{
      lt = kt->second.find(g);
      if(lt == kt->second.end())
        kt->second[g] = 1;
    }
  }
      }
    }

    r = 0;
    for(it = m.begin(); it != m.end(); ++it){
      for(jt = it->second.begin(); jt != it->second.end(); ++jt){
  g = 0;
  for(kt = jt->second.begin(); kt != jt->second.end(); ++kt)
    g += kt->second.size();
  r = max(g, r);
      }
    }
    printf("%d\n", r);
  }
  return 0;
}

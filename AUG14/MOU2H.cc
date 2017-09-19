// MOU2H

#include <stdio.h>
#include <unordered_map>
using std::unordered_map;

#define map unordered_map
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MAX 1000000
#define MOD 1000000009

inline int getn(){
  char c = gc(), f = 0; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = 1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return (f) ? 0-n : n;
}

char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int cmod(int n){
  if(n < 0)
    return n + MOD;
  if(n >= MOD)
    return n - MOD;
  return n;
}

int a[MAX], b[MAX];
int main(){
  int T,N,H, i,p;
  map<int,int> c;
  map<int,int>::iterator it;
  T = getn();
  while(T--){
    c.clear();
    N = getn()-1, p = getn();
    for(i = 1; i <= N; i++)
      H = getn(), a[i] = H-p, p = H;
    b[0] = 1;
    for(i = 1; i <= N; i++){
      b[i] = cmod(b[i-1]<<1);
      it = c.find(a[i]);
      if(it != c.end())
        b[i] = cmod(b[i]-b[it->second-1]);
      c[a[i]] = i;
    }
    putn(cmod(b[N]-1)); pc('\n');
  }
  return 0;
}

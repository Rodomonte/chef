// REIGN

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}
#define ll long long
#define pc putchar_unlocked
char pb[20];
inline void putll(ll n){
  if(!n) pc('0');
  if(n < 0){ pc('-'); n *= -1; }
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

#define INF 2000000000
#define MAX 100000
int a[MAX];
ll mr[MAX], ml[MAX];
int main(){
  int T,N,K, i;
  ll s;
  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 0; i < N; i++)
      a[i] = getn();
    for(i = 1, s = mr[0] = a[0]; i < N; i++){
      s = (s > 0) ? s + a[i] : a[i];
      mr[i] = (s > mr[i-1]) ? s : mr[i-1];
    }
    for(i = N-2, s = ml[N-1] = a[N-1]; i >= 0; i--){
      s = (s > 0) ? s + a[i] : a[i];
      ml[i] = (s > ml[i+1]) ? s : ml[i+1];
    }
    for(i = 0, s = -INF; i+K+1 < N; i++)
      if(mr[i] + ml[i+K+1] > s)
        s = mr[i] + ml[i+K+1];
    putll(s); pc('\n');
  }
  return 0;
}

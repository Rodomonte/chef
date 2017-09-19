// RRSTONE

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
inline void putn(ll n){
  if(!n) pc('0');
  if(n < 0){ pc('-'); n = 0L - n; }
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

#define MAX 100000
#define INF 2000000000
int main(){
  int N,K, i;
  N = getn(), K = getn();
  if(!K){
    for(i = 0; i < N; i++){
      putn(getn()); pc(' ');
    }
    pc('\n');
    return 0;
  }
  ll a[MAX], mn,mx;
  mn = INF, mx = -INF;
  for(i = 0; i < N; i++){
    a[i] = getn();
    if(a[i] < mn) mn = a[i];
    if(a[i] > mx) mx = a[i];
  }
  if(K&1){
    for(i = 0; i < N; i++){
      putn(mx-a[i]); pc(' ');
    }
    pc('\n');
    return 0;
  }
  for(i = 0; i < N; i++){
    putn(a[i]-mn); pc(' ');
  }
  pc('\n');
  return 0;
}

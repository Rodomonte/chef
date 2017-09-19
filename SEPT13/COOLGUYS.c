// COOLGUYS

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define ll long long
#define pc putchar_unlocked
inline void putl(ll n){
  if(!n) pc('0');
  char pb[20];
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

ll gcd(ll a, ll b){
  return b ? gcd(b,a%b) : a;
}

int main(){
  int T,N, i, p, n, r;
  ll s, N2, g;
  T = getn();
  while(T--){
    N = getn(), p = s = N, r = 1;
    for(i = 2; i <= sqrt(N); i++){
      n = N / i;
      s += n + (p-n)*(i-1);
      r += p - n + 1;
      p = n;
    }
    if(r < N){
      n = N / i;
      s += (p-n)*(i-1);
    }
    N2 = (ll)N * N;
    g = gcd(s, N2);
    putl(s/g);
    pc('/');
    putl(N2/g);
    pc('\n');
  }
  return 0;
}

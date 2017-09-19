// BINTOUR

#include <stdio.h>

#define pc putchar_unlocked
char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

#define ll long long
#define MOD 1000000009

int f[262144];
int main(){
  int K,N,N2, i,j;
  ll n,h,k,k2;
  scanf("%d",&K);
  if(K == 1){
    printf("2\n2\n");
    return 0;
  }else if(K == 2){
    printf("0\n8\n16\n24\n");
    return 0;
  }
  N = 1 << K;
  N2 = N >> 1;
  n = f[N2-1] = N2-1;
  for(i = N2-2; i > 0; i--){
    n = (n * i) % MOD;
    f[i] = n;
  }
  for(i = 1; i < N2; i++){
    pc('0'); pc('\n');
  }
  k = f[1];
  k = (k * N2) % MOD;
  k = (k * N2 * 2) % MOD;
  putn((k*f[1])%MOD); pc('\n');
  k2 = (k * N2) % MOD;
  putn((k2*f[2])%MOD); pc('\n');
  for(i = 3, h = j = N2+1; i < N2; i++){
    n = f[i];
    n = (n * h) % MOD;
    n = (n * k2) % MOD;
    putn(n); pc('\n');
    h = (h * ++j) % MOD;
  }
  putn((k2*h)%MOD); pc('\n');
  h = (h * ++j) % MOD;
  putn((k*h)%MOD); pc('\n');
  return 0;
}

// MTRICK

#include <stdio.h>

#define ll unsigned long long
#define gc getchar_unlocked
inline ll getll(){
  char c = gc(); ll n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define BIL 1000000000
ll A2, B2;
ll llmul(ll a, ll b, ll m){
  ll t, r;
  if(a < BIL && b < BIL){
    r = a * b;
    return (r >= m) ? r%m : r;
  }
  r = 0;
  while(b){
    if(a < b)
      t = a, a = b, b = t;
    while(a < m){
      if(b & 1)
        r += a;
      a <<= 1, b >>= 1;
    }
    a -= m;
    while(r >= m)
      r -= m;
  }
  return r;
}
int main(){
  char o[1001];
  ll T,N,A,B,C, i,j,k, a[1000], t;
  T = getll();
  while(T--){
    N = getll();
    for(i = 0; i < N; i++)
      a[i] = getll();
    A = getll(), B = getll(), C = getll();
    scanf("%s",o);
    A = (A >= C) ? A%C : A;
    B = (B >= C) ? B%C : B;
    A2 = 0, B2 = 1;
    for(i = 0; i < N; i++){
      if(o[i] == 'A'){
        A2 += A;
        A2 = (A2 >= C) ? A2-C : A2;
      }else if(o[i] == 'M'){
        A2 = llmul(A2, B, C);
        B2 = llmul(B2, B, C);
      }else{
        j = i, k = N-1;
        while(j < k){
          t = a[j], a[j] = a[k], a[k] = t;
          j++, k--;
        }
      }
      a[i] = (a[i] >= C) ? a[i]%C : a[i];
      a[i] = llmul(a[i], B2, C) + A2;
      a[i] = (a[i] >= C) ? a[i]-C : a[i];
    }
    for(i = 0; i < N; i++)
      printf("%lld ",a[i]);
    printf("\n");
  }
  return 0;
}

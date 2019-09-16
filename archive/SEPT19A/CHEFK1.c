// CHEFK1

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

ll getl(){
  ll n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

//! check N=1 M=0
int main(){
  int T, r;
  ll N,M;

  T = getl();
  while(T--){
    N = getl(), M = getl();
    if(N == 1){
      if(!M) printf("0\n");
      else if(M == 1) printf("1\n");
      else printf("-1\n");
    }else if(N == 2){
      if(M == 1) printf("1\n");
      else if(M == 2 || M == 3) printf("2\n");
      else printf("-1\n");
    }else if(M < N-1 || M > ((N*(N-1))>>1) + N) printf("-1\n");
    else if(M >= N-1 && M <= N+1) printf("2\n");
    else if(M > N+1 && M <= (N<<1)) printf("3\n");
    else{
      r = ((M / N) << 1) - 1;
      M -= M / N * N;
      if(M >= (N >> 1)) M -= (N >> 1), ++r;
      if(M > 0) ++r;
      printf("%d\n", r);
    }
  }
  return 0;
}

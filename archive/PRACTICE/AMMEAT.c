// AMMEAT

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
inline ll getn(){
  int c = gc();
  ll n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

ll *c,*d;
ll comp(const void* a, const void* b){
  c = (ll*)a, d = (ll*)b;
  if(*c == *d) return 0;
  else if(*c > *d) return -1;
  else return 1;
}
int main(){
  int T = getn(),N, i, r;
  ll M, n, a[7];
  while(T--){
    N = getn(), M = getn(), n = 0, r = 0;
    for(i = 0; i < N; i++)
      a[i] = getn();
    qsort(a, N, 8, comp);
    for(i = 0; i < N; i++){
      n += a[i];
      r++;
      if(n >= M)
        break;
    }
    if(n < M){
      printf("-1\n");
      continue;
    }
    printf("%d\n",r);
  }
  return 0;
}

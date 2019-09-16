// CHEFING

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  char S[201];
  int T,N, i,j, r, a[26], b[26];

  T = getn();
  while(T--){
    N = getn(), r = 0;
    for(i = 0; i < 26; ++i) a[i] = 0;
    for(i = 0; i < N; ++i){
      scanf("%s", S);
      for(j = 0; j < 26; ++j) b[j] = 0;
      for(j = 0; S[j]; ++j) ++b[S[j]-'a'];
      for(j = 0; j < 26; ++j) a[j] += b[j] ? 1 : 0;
    }

    for(i = 0; i < 26; ++i) r += (a[i] == N) ? 1 : 0;
    printf("%d\n", r);
  }
  return 0;
}

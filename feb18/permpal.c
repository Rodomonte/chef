// PERMPAL

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char s[100001];
int a[26][100000], r[100000];
int main(){
  int T,N, i,j, o, b[26],c[26];

  T = getn();
  while(T--){
    scanf("%s", s), N = strlen(s);

    for(i = 0; i < 26; ++i) b[i] = c[i] = 0;
    for(i = 0; i < N; ++i) a[s[i]-'a'][c[s[i]-'a']++] = i;
    for(i = o = 0; i < 26; ++i) if(c[i]&1) ++o;
    if(o > 1){ printf("-1\n"); continue; }

    for(i = j = 0; i < (N>>1); ++i){
      while(!c[j] || c[j] == 1) ++j;
      r[i] = a[j][b[j]++], r[N-i-1] = a[j][b[j]++], c[j] -= 2;
    }
    if(N&1){
      for(j = 0; j < 26; ++j) if(c[j] == 1) break;
      r[N>>1] = a[j][b[j]];
    }

    for(i = 0; i < N; ++i) printf("%d ", r[i]+1);
    printf("\n");
  }
  return 0;
}

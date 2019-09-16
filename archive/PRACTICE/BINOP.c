// BINOP

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

int max(int a, int b){ return (a > b) ? a : b; }

char a[1000001], b[1000001];
int main(){
  int T,N, i, o,z,ot,zt;

  T = getn();
  while(T--){
    scanf("%s\n%s", a, b), N = strlen(a);

    for(i = o = z = ot = zt = 0; i < N; ++i){
      if(a[i] == '1') ++ot;
      else ++zt;
      if(a[i] == b[i]) continue;
      if(a[i] == '1') ++o;
      else ++z;
    }

    if(!ot || !zt) printf("Unlucky Chef\n");
    else printf("Lucky Chef\n%d\n", max(o, z));
  }
  return 0;
}

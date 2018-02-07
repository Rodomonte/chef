// GERMANDE

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

typedef struct {
  int l,r,o,z;
} S ;

char a[1000000];
S s[1000000];
int main(){
  char f;
  int T,N,O,P, i,j,k,l,o,z;

  T = getn();
  while(T--){
    O = getn(), P = getn(), N = O * P;
    for(i = j = 0; j < O; ++j){
      s[j].l = i, s[j].r = i+P-1, s[j].o = s[j].z = 0;
      for(k = 0; k < P; ++i,++k){
        a[i] = getn();
        if(a[i] == 1) ++s[j].o;
        else ++s[j].z;
      }
    }

    f = 0;
    for(i = 0; i < P; ++i){
      o = z = 0;
      for(j = 0; j < O; ++j){
        if(s[j].o > s[j].z) ++o;
        else ++z;
        l = (s[j].l == N-1) ? 0 : s[j].l+1;
        if(a[s[j].l] == 1) --s[j].o;
        else --s[j].z;
        k = (s[j].r == N-1) ? 0 : s[j].r+1;
        if(a[k] == 1) ++s[j].o;
        else ++s[j].z;
        s[j].l = l, s[j].r = k;
      }
      if(o > z){
        f = 1;
        break;
      }
    }

    printf("%d\n", f);
  }
  return 0;
}

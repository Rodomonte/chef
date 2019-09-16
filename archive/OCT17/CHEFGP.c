// CHEFGP

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }

char a[100001];
int main(){
  char c,f,o;
  int T,X,Y, i, n,s,t,x,y;

  T = getn();
  while(T--){
    scanf("%s", a), X = getn(), Y = getn();

    x = y = 0, n = strlen(a);
    for(i = 0; i < n; ++i){
      if(a[i] == 'a') ++x;
      else ++y;
    }
    c = 'a', o = 'b', f = 0;
    if(x < y) c = 'b', o = 'a', t = x, x = y, y = t, t = X, X = Y, Y = t;
    t = x / (y+1), s = (x == y) ? 1 : min(X, (x%(y+1)) ? t+1 : t);
    if(x != y && ((x%(y+1))?t+1:t) <= X) f = 1, t = x % (y+1);

    while(x){
      for(i = 0; x && i < s; ++i, --x) printf("%c", c);
      if(x || y) printf("%c", y ? o : '*'), y -= y ? 1 : 0;
      if(f){
        --t;
        if(!t) --s, f = 0;
      }
    }
    printf("\n");
  }
  return 0;
}

// RBTREE

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char O, f;
  int Q,X,Y, a[32], i,j,b,r;
  for(a[0] = i = 1; i < 32; i++)
    a[i] = a[i-1] << 1;
  Q = getn(), f = 0;
  while(Q--){
    gc(), O = gc(), b = r = 0;
    if(O == 'i'){
      f = (f) ? 0 : 1, gc();
      continue;
    }
    X = getn(), Y = getn();
    for(i = 0; X >= a[i+1]; ++i);
    for(j = 0; Y >= a[j+1]; ++j);
    while(i > j){
      if(i & 1)
        ++r;
      else
        ++b;
      X >>= 1;
      --i;
    }
    while(j > i){
      if(j & 1)
        ++r;
      else
        ++b;
      Y >>= 1;
      --j;
    }
    while(X != Y){
      if(i & 1)
        r += 2;
      else
        b += 2;
      X >>= 1, Y >>= 1;
      --i, --j;
    }
    if(i & 1)
      ++r;
    else
      ++b;
    if((O == 'b' && !f) || (O == 'r' && f))
      printf("%d\n", b);
    else
      printf("%d\n", r);
  }
  return 0;
}

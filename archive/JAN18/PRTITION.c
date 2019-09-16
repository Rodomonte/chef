// PRTITION

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,X, i,j, t,a,b,c,n;
  ll e,o;

  T = getn();
  while(T--){
    X = getn(), N = getn();

    for(i = 1, e = o = 0; i <= N; ++i) if(i != X)
      e += (i&1) ? 0 : (ll)i, o += (i&1) ? (ll)i : 0;
    if(((e+o)&(1LL)) || !e || !o){ printf("impossible\n"); continue; }
    if(e == o){
      for(i = 1; i <= N; ++i)
        printf("%d", (i == X) ? 2 : (i&1));
      printf("\n"); continue;
    }
    t = (int)(((e-o < 0) ? o-e : e-o) >> (1LL));
    //printf("t=%d\n", t);

    a = b = c = -1;
    if(t&1){
      if(o > e && t != X && t > 0 && t <= N) a = t;
      else for(i = 1; i <= N; i += 2){
        n = (e > o) ? i+t : i-t;
        //printf("i=%d n=%d\n", i,n);
        if(i != X && n != X && n > 0 && n <= N){ a = n, b = i; break; }
      }
    }else{
      if(e > o && t != X && t > 0 && t <= N) a = t;
      else{
        for(i = 1; i <= N; i += 2){
          for(j = i+2; j <= N; j += 2){
            n = (e > o) ? i+j+t : i+j-t;
            //printf("i=%d j=%d n=%d\n", i,j,n);
            if(i != X && j != X && n != X && n > 0 && n <= N){
              a = n, b = i, c = j; break; }
          }
          if(a != -1) break;
        }
      }
    }

    if(a == -1){ printf("impossible\n"); continue; }
    for(i = 1; i <= N; ++i)
      printf("%d", (i == X) ? 2 :
        (((i&1) && (i == a || i == b || i == c)) ||
         (!(i&1) && i != a && i != b && i != c) ? 0 : 1));
    printf("\n");
  }
  return 0;
}

// GUESSPRM TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define ll long long
#define vec std::vector
#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

char ps[31623] = {0};
int main(){
  char f, buf[4];
  int T,X,Y,Z,Z0,P, i,j,k, m,n,s;
  ll t;
  vec<int> a,b,p;

  n = 31623;
  for(i = 2; i < n; ++i){
    if(ps[i]) continue;
    p.pb(i);
    for(j = i+i; j <= n; j += i)
      ps[j] = 1;
  }

  Z0 = 21856;
  m = 0;
  T = getn();
  while(T--){
    Z = Z0;
    // if(rand()%2){
    //   while(1){
    //     P = rand() % 1000000000;
    //     if(P == 1) continue;
    //     for(i = n = 0; i < p.size(); ++i)
    //       if(P % p[i] == 0){ n = 1; break; }
    //     if(!n) break;
    //   }
    // }else P = p[rand()%p.size()];
    // printf("\nT%d: P=%d  Z=%d m=%d\n", T,P,Z,m);

    printf("1 %d\n", Z), fflush(stdout);
    X = getn(); //(ll)Z * Z % P;
    t = (ll)Z * Z - X, s = sqrt(t);

    if(!t){
      Z = 31623;
      printf("1 %d\n", Z), fflush(stdout);
      X = getn(); //(ll)Z * Z % P;
      t = (ll)Z * Z - X, s = sqrt(t);

      a.clear();
      for(i = 0; i < p.size(); ++i){
        if(p[i] > s) break;
        if(t % p[i] == 0) a.pb(p[i]);
        while(t % p[i] == 0) t /= p[i];
      }
      if(t > 1) a.pb(t);
      std::sort(a.begin(), a.end());
      printf("2 %d\n", a.back()), fflush(stdout);
      // if(a.back() != P) gc();
      scanf("%s", buf);
      if(buf[0] == 'N') t /= 0;
      continue;
    }

    a.clear();
    for(i = 0; i < p.size(); ++i){
      if(p[i] > s) break;
      if(t % p[i] == 0) a.pb(p[i]);
      while(t % p[i] == 0) t /= p[i];
    }
    if(t > 1) a.pb(t);
    std::sort(a.begin(), a.end());

    i = a.size()-1;
    printf("1 %d\n", a[i]), fflush(stdout);
    Y = getn(); //(ll)a[i] * a[i] % P;
    if(!Y){
      printf("2 %d\n", a[i]), fflush(stdout);
      // if(a[i] != P){
      //   m = max(m, T);
      //   T = 0;
      //   Z0 = rand()0000+10;
      //   continue;
      // }
      scanf("%s", buf);
      if(buf[0] == 'N') t /= 0;
    }
    t = (ll)a[i] * a[i] - Y, k = i, s = sqrt(t);
    if(!t) continue;

    b.clear();
    for(i = 0; i < p.size(); ++i){
      if(p[i] > s) break;
      if(t % p[i] == 0) b.pb(p[i]);
      while(t % p[i] == 0) t /= p[i];
    }
    if(t > 1) b.pb(t);
    std::sort(b.begin(), b.end());

    for(i = a.size()-1; i >= 0; --i){
      if(a[i] <= X || a[i] <= Y || i == k) continue;
      for(j = b.size()-1, f = 0; j >= 0; --j){
        if(b[j] <= X || b[j] <= Y || b[j] == a[k]) continue;
        if(a[i] == b[j]){
          printf("2 %d\n", a[i]), fflush(stdout);
          scanf("%s", buf);
          if(buf[0] == 'N') t /= 0;
          // if(a[i] != P){
          //   m = max(m, T);
          //   T = 0;
          //   Z0 = rand()0000+10;
          //   continue;
          // }
          f = 1;
          break;
        }
      }
      if(f) break;
    }
  }
  return 0;
}

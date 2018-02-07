// LUCKG

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using std::vector;
using std::sort;

#define gc getchar_unlocked
#define pb push_back
#define pc putchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}


struct P {
  int i;
  vector<int> c;
  P(int i0): i(i0) {}
};
bool cmp(const P& a, const P& b){
  return a.i < b.i;
}
int main(){
  char v[1000], f;
  int T,N,M, p[1000], i,j,k,n,t,c;
  vector<P> a;
  T = getn();
  while(T--){
    N = getn(), M = getn(), f = 0;
    for(i = 0; i < N; i++)
      p[i] = getn();
    if(M < 3){
      printf("No Solution\n");
      continue;
    }
    for(i = 0; i < N; i++)
      if(p[i] == i || (p[i] < i && p[p[i]] == i)){
        f = 1;
        break;
      }
    if(f){
      printf("No Solution\n");
      continue;
    }
    memset(v, 0, N);
    a.clear();
    c = 1;
    for(i = 0; i < N; i++){
      if(v[i])
        continue;
      j = i, n = a.size(), t = 0;
      while(!v[j]){
        a.pb(P(j));
        v[j] = 1;
        j = p[j];
        t++;
      }
      k = a.size()-1;
      if(M == 4 && t == 3){
        a[k].c.pb(c), a[k-1].c.pb(c+1), a[k-2].c.pb(c+2);
        a[k].c.pb(c+3), a[k-1].c.pb(c+4), a[k-2].c.pb(c+5);
        a[k-1].c.pb(c+6), a[k-2].c.pb(c+7), a[k-2].c.pb(c+8);
        a[k].c.pb(c+9), a[k].c.pb(c+10), a[k-1].c.pb(c+11);
        c += 12;
        continue;
      }
      for(j = 0; j < M; j++){
        for(t = 0; t < a.size()-n-1; t++){
          a[k].c.pb(c);
          c++, k--;
          if(k < n)
            k = a.size()-1;
        }
        a[k].c.pb(c);
        c++;
      }
    }
    sort(a.begin(), a.end(), cmp);
    f = 0;
    for(i = 0; i < N; i++){
      n = 0;
      for(j = 0; j < M; j++)
        for(k = 0; k < M; k++)
          if(a[i].c[j] > a[p[i]].c[k])
            n++;
      if((n<<1) <= M*M){
        f = 1;
        break;
      }
    }
    if(f){
      printf("No Solution\n");
      continue;
    }
    for(i = 0; i < N; i++){
      for(j = 0; j < M-1; j++)
        putn(a[i].c[j]), pc(' ');
      putn(a[i].c[M-1]), pc('\n');
    }
  }
  return 0;
}

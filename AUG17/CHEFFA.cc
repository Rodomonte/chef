// CHEFFA

#include <stdio.h>
#include <unordered_map>

using std::unordered_map;

#define gc getchar
#define MOD 1000000007

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int madd(int a, int b){ return (a+b >= MOD) ? a+b-MOD : a+b; }
int hash(int a, int b){ return (a << 16) | b; }
int uha(int h){ return h >> 16; }
int uhb(int h){ return h & ((1 << 16) - 1); }

int a[100];
int main(){
  int T,N, i,j, r,x,y,z;
  unordered_map<int,int> b,m;
  unordered_map<int,int>::iterator it;

  T = getn();
  while(T--){
    N = getn();
    if(N == 1){ printf("1\n"); continue; }
    for(i = 0; i < N; ++i) a[i] = getn();
    for(; i < 100; ++i) a[i] = 0;

    m.clear(), m[hash(a[0], a[1])] = 1;
    for(i = 0; i < N+10; ++i){
      b.clear();
      for(it = m.begin(); it != m.end(); ++it){
        x = uha(it->first), y = uhb(it->first), z = a[i+2];
        for(j = 0; x >= 0 && y >= 0; ++j){
          if(b.find(hash(y, z)) == b.end()) b[hash(y, z)] = it->second;
          else b[hash(y, z)] = madd(b[hash(y, z)], it->second);
          --x, --y, ++z;
        }
      }
      m = b;
    }

    r = 0;
    for(it = m.begin(); it != m.end(); ++it) r = madd(r, it->second);
    printf("%d\n", r);
  }
  return 0;
}

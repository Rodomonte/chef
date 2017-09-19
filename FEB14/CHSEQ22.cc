// CHSEQ22

#include <stdio.h>
#include <map>
using std::map;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define ll long long
#define MOD 1000000007
int pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1)
      r = (r * n) % MOD;
    n = (n * n) % MOD;
    e >>= 1;
  }
  return (int)r;
}

struct S {
  int a,b;
  S(int a0, int b0): a(a0),b(b0) {}
  bool operator==(const S &o) const{
    return a==o.a && b==o.b;
  }
  bool operator<(const S &o) const{
    return a<o.a || b<o.b;
  }
};
int a[100001]={0};
int main(){
  int N,M,L,R, i, t,r;
  map<S,char> m;
  N = getn(), M = getn(), r = 0;
  for(i = 0; i < M; i++){
    L = getn(), R = getn();
    S s(L,R);
    if(m.find(s) != m.end())
      continue;
    m[s] = 1;
    while(1){
      if(R == a[L])
        break;
      if(!a[L]){
        a[L] = R;
        r++;
        break;
      }
      if(R > a[L]){
        L = a[L]+1;
      }else{
        t = R, R = a[L], a[L] = t;
        L = a[L]+1;
      }
    }
  }
  r = pow(2,r);
  printf("%d\n",r);
  return 0;
}

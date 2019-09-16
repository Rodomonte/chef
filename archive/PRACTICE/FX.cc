// FX

#include <stdio.h>
#include <set>

using std::set;

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[100001][3], r[1000000][3];

int val(int i){
  return a[i][0] * a[i][1] * a[i][2];
}

struct P {
  int i;
  P(int i0): i(i0) {}
  bool operator<(const P& o) const {
    return val(i) < val(o.i);
  }
};

int main(){
  int N,C, i,j,k,m,mi,n,t,rn;
  set<P> s;
  set<P>::iterator it;

  N = getn(), C = getn();
  for(i = 1; i <= N; ++i)
    a[i][0] = getn(), a[i][1] = getn(), a[i][2] = getn(), s.insert(P(i));

  rn = 0;
  while(s.size() > 1){
    i = s.begin()->i, s.erase(s.begin());
    it = s.end(), --it, j = it->i, s.erase(it);
    for(m = k = 0; k < 3; ++k){
      n = val(i) + val(j);
      t = a[i][k], a[i][k] = a[j][k]+1, a[j][k] = t+1;
      n -= val(i) + val(j) + C;
      t = a[i][k], a[i][k] = a[j][k]-1, a[j][k] = t-1;
      if(n > m)
        m = n, mi = k;
    }
    if(!m) continue;
    t = a[i][mi], a[i][mi] = a[j][mi]+1, a[j][mi] = t+1;
    r[rn][0] = mi+1, r[rn][1] = i, r[rn][2] = j, ++rn;
    s.insert(P(i)), s.insert(P(j));
  }

  printf("%d\n", rn);
  for(i = 0; i < rn; ++i)
    printf("%d %d %d\n", r[i][0], r[i][1], r[i][2]);

  return 0;
}

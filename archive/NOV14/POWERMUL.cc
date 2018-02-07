// POWERMUL

#include <stdio.h>
#include <vector>
using std::vector;

#define ll long long
#define gc getchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int mul(int a, int b, int m){
  return (int)((ll)a * b % m);
}

int pow(ll n, ll e, int m){
  ll r = 1;
  while(e){
    if(e & 1)
      r = (r * n) % m;
    n = (n * n) % m;
    e >>= 1;
  }
  return (int)r;
}

int s[100001]={0};
int p[9592],pn, q[100000], rn;
int a[19184],an, li[20],ln;
ll r[9592];
vector<int> f[100001];

void build(){
  int i,j,n;
  li[0] = 0, n = pn, ln = 1;
  while(n > 0){
    li[ln] = li[ln-1] + n;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++)
      a[j] = 1;  // a[i] * a[i+1];
    n >>= 1, ln++;
  }
  an = j;
}

void update(int p, int v, int m){
  int l,i;
  r[s[p]] += v;
  a[s[p]] = pow(p, r[s[p]], m);
  l = 1, i = s[p] >> 1;
  while(i + li[l] < an){
    a[i+li[l]] = mul(a[li[l-1]+(i<<1)], a[li[l-1]+(i<<1)+1], m);
    i >>= 1, ++l;
  }
}

int query(int i0, int i1, int m){
  int i,j,l,e,ia,ib,n;
  l = 0, n = e = 1, i = i0;
  while(i0 <= i1){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (i0 >> l+1);
      ia = (j - li[l+1]) << (l+1);
      ib = ia + (e << 1) - 1;
      if(ia == i0 && ib <= i1){
        i = j, e <<= 1, l++;
        continue;
      }
    }
    ia = (i - li[l]) << l;
    if(ia == i0){
      n = mul(n, a[i], m);
      i0 += e;
      if(i0 > i1)
        break;
    }
    if(i1 - i0 + 1 < e){
      e >>= 1, l--;
      i = li[l] + (ia >> l) + 1;
    }else{
      i++;
    }
  }
  return n;
}

int main(){
  int T,N,M,Q,R, i,j,n,d;

  s[0] = s[1] = -1, pn = 0;
  for(i = 2; i <= 100000; ++i){
    if(s[i] == -1)
      continue;
    s[i] = pn, p[pn++] = i, f[i].pb(i);
    for(j = i+i; j <= 100000; j += i){
      s[j] = -1, n = j;
      while(n % i == 0)
        f[j].pb(i), n /= i;
    }
  }

  T = getn();
  while(T--){
    N = getn(), M = getn(), Q = getn();
    if(N == 3){
      q[2] = 27%M;
    }else if(N == 4){
      q[2] = 1728%M, q[3] = 256%M;
    }else if(N == 5){
      q[2] = 200000%M, q[3] = 200000%M, q[4] = 3125%M;
    }else{
      for(i = 0; i < 9592; i++)
        r[i] = 0, a[i] = 1;
      build();
      for(i = 0; i < f[N].size(); ++i)
        update(f[N][i], N, M);
      q[N-1] = query(0, 9591, M);
      for(n = N-1, d = 2; n > d; n--, d++){
        for(i = 0; i < f[n].size(); ++i)
          update(f[n][i], n, M);
        for(i = 0; i < f[d].size(); ++i)
          update(f[d][i], -d, M);
        q[N-d] = q[d] = query(0, 9591, M);
      }
    }
    while(Q--){
      R = getn();
      printf("%d\n", q[R]);
    }
  }
  return 0;
}

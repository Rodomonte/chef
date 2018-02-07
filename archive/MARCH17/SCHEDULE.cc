// SCHEDULE

#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

#define gc getchar_unlocked
#define MX 1000000

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct P {
  int n,i,s,t;
  P(int n0, int i0): n(n0), i(i0), s(0), t(n0) {}
  bool operator<(const P& o) const{
    if(n < o.n) return true;
    else if(n == o.n) return i < o.i;
    else return false;
  }
};

char a[MX+1];
int b[MX], c[MX], d[MX];
int main(){
  char l;
  int T,N,K, i,j,n,t,r;
  priority_queue<P> q;

  T = getn();
  while(T--){
    N = getn(), K = getn(), scanf("%s", a), t = 1, j = 0;
    while(!q.empty())
      q.pop();
    for(i = 0; i < N; ++i)
      b[i] = c[i] = d[i] = 0;

    for(i = 1; i < N; ++i){
      if(a[i] == a[i-1])
        ++t;
      else
        q.push(P(t, j)), b[j] = d[j] = t, t = 1, j = i;
    }
    q.push(P(t, j)), b[j] = d[j] = t;

    for(i = 0; i < K; ++i){
      P p = q.top();
      if(p.n <= 2)
        break;
      n = ceil((double)(p.t-(p.s+1)) / (double)(p.s+2));
      P pn(n, p.i);
      pn.s = p.s+1, pn.t = p.t;
      q.push(pn), q.pop();
      /*n = q.top().n, t = q.top().i + (n>>1);
      if(n <= 2)
        break;
      if(n&1)
        q.push(P(n>>1, t+1));
      else
        q.push(P((n>>1)-1, t+1));
      q.push(P(n>>1, q.top().i)), q.push(P(1, t)), q.pop();*/
    }
    if(i == K){
      printf("%d\n", q.top().n);
      continue;
    }

    l = 0;
    for(i = 0; i < N; ++i){
      if(b[i] == 2)
        l = (l) ? 0 : 1;
      if(b[i] <= 2)
        continue;
      n = b[i]>>1;
      if(b[i]&1)
        t = i+n, b[t+1] = n, b[t] = 1, b[i] = n;
      else if((l && !(n&1)) || (!l && (n&1)))
        t = i+n-1, b[t] = 1, b[t+1] = n, b[i] = n-1;
      else
        t = i+n, b[t] = 1, b[t+1] = n-1, b[i] = n;
      ++c[t], --i;
    }

    l = 0;
    for(i = 0; i < N; ++i){
      if(l && b[i] == 2)
        l = 0;
      else if(!l && b[i] == 2)
        ++c[i], l = 1;
      else if(!l)
        ++c[i];
    }

    for(i = r = 0; i < N; ++i)
      if(c[i]&1)
        ++r;
    if(r <= K){
      printf("1\n");
      continue;
    }

    for(i = 0; i < N; ++i)
      c[i] = 0, b[i] = d[i];
    l = 1;
    for(i = 0; i < N; ++i){
      if(b[i] == 2)
        l = (l) ? 0 : 1;
      if(b[i] <= 2)
        continue;
      n = b[i]>>1;
      if(b[i]&1)
        t = i+n, b[t+1] = n, b[t] = 1, b[i] = n;
      else if((l && !(n&1)) || (!l && (n&1)))
        t = i+n-1, b[t] = 1, b[t+1] = n, b[i] = n-1;
      else
        t = i+n, b[t] = 1, b[t+1] = n-1, b[i] = n;
      ++c[t], --i;
    }

    l = 1;
    for(i = 0; i < N; ++i){
      if(l && b[i] == 2)
        l = 0;
      else if(!l && b[i] == 2)
        ++c[i], l = 1;
      else if(!l)
        ++c[i];
    }

    for(i = r = 0; i < N; ++i)
      if(c[i]&1)
        ++r;
    printf("%d\n", (r <= K) ? 1 : 2);
  }
  return 0;
}

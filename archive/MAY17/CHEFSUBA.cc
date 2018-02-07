// CHEFSUBA

#include <stdio.h>
#include <queue>
#include <set>

using std::queue;
using std::multiset;

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct Q {
  char f;
  int n;
  Q(char f0, int n0): f(f0), n(n0) {}
};

char p[100000];
int a[100000];
int main(){
  int N,K,P, i,n;
  queue<int> qa;
  queue<Q> q;
  multiset<int> s;
  multiset<int>::iterator it;

  N = getn(), K = getn(), P = getn();
  for(i = 0; i < N; ++i)
    a[i] = getn();
  scanf("%s", p);

  if(K == 1){
    n = 0;
    for(i = 0; i < N; ++i)
      if(a[i])
        n = 1;
    for(i = 0; i < P; ++i)
      if(p[i] == '?')
        printf("%d\n", n);
    return 0;
  }

  n = 0;
  for(i = N-1; i >= N-K; --i)
    n += a[i];
  q.push(Q(a[N-1], n));
  s.insert(n);
  for(; i >= 0; --i){
    n += a[i], n -= a[i+K];
    q.push(Q(a[i+K-1], n));
    s.insert(n);
  }
  for(i = K-2; i >= 0; --i)
    qa.push(a[i]);
  for(i = N-1; i >= K-1; --i)
    qa.push(a[i]);

  for(i = 0; i < P; ++i){
    if(p[i] == '?'){
      printf("%d\n", *s.rbegin());
      continue;
    }
    it = s.find(q.front().n);
    s.erase(it);
    n = q.back().n - q.back().f + q.front().f;
    q.push(Q(qa.front(), n));
    q.pop();
    qa.push(qa.front());
    qa.pop();
    s.insert(n);
  }

  return 0;
}

// DONUTS

#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,M, i,r;
  std::vector<int> a;
  std::deque<int> b;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    a.clear();
    for(i = 0; i < M; ++i)
      a.push_back(getn());
    std::sort(a.begin(), a.end());
    for(i = 0; i < M-1; ++i)
      b.push_back(a[i]);
    r = 0;
    while(!b.empty()){
      if(b.front() == 1)
  b.pop_front();
      else
        --b.front();
      ++r;
      if(!b.empty())
  b.pop_back();
    }
    printf("%d\n", r);
  }
  return 0;
}

// DESTROY

#include <stdio.h>
#include <map>

using std::map;

#define gc getchar_unlocked

inline int gi(){
  char c; int n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N, i,j,n,x;
  map<int,int> m; map<int,int>::iterator it;

  T = gi();
  while(T--){
    m.clear();
    N = gi(), x = 1;
    for(i = 0; i < N; ++i){
      n = gi();
      it = m.find(n);
      if(it == m.end()){
        m[n] = 1;
      }else{
        ++(it->second);
        if(it->second > x)
          x = it->second;
      }
    }
    printf("%d\n", (x > (N>>1)) ? (N-x)+(x-(N-x)) : (N>>1)+(N&1));
  }
  return 0;
}

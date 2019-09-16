// DIVMAC

#include <stdio.h>
#include <map>

using std::map;

#define gc getchar_unlocked
#define NM 100000
#define AM 1000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

char s[AM+1]={0};
int a[NM], p[AM+1]={0};
int main(){
  int T,N,M,O,L,R, i,j, r;
  map<int,int> m;
  map<int,int>::iterator it,jt;

  for(i = 2; i <= AM; ++i){
    if(s[i]) continue;
    p[i] = i;
    for(j = i+i; j <= AM; j += i){
      s[j] = 1;
      if(!p[j]) p[j] = i;
    }
  }

  T = getn();
  while(T--){
    N = getn(), M = getn(), m.clear();
    for(i = 0, j = -1; i < N; ++i){
      a[i] = getn();
      if(j == -1 && a[i] == 1) j = i;
      if(j != -1 && a[i] != 1) m[i-1] = j, j = -1;
    }
    if(j != -1) m[N-1] = j;

    while(M--){
      O = getn(), L = getn()-1, R = getn()-1;
      if(!O){
        for(i = L; i <= R; ++i){
          if((it = m.lower_bound(i)) != m.end() && it->second <= i)
            i = it->first+1;
          if(i > R) break;
          a[i] /= p[a[i]];
          if(a[i] == 1){
            if((it = m.find(i-1)) != m.end() &&
               (jt = m.lower_bound(i)) != m.end() && jt->second == i+1)
              m[jt->first] = it->second, m.erase(it);
            else if((it = m.find(i-1)) != m.end())
              m[i] = it->second, m.erase(it);
            else if((jt = m.lower_bound(i)) != m.end() && jt->second == i+1)
              m[jt->first] = i;
            else m[i] = i;
          }
        }

      }else{
        for(i = L, r = 1; i <= R; ++i){
          if((it = m.lower_bound(i)) != m.end() && it->second <= i)
            i = it->first+1;
          if(i > R) break;
          r = max(r, p[a[i]]);
        }
        printf("%d ", r);
      }
    }
    printf("\n");
  }
  return 0;
}

// KMHAMHA

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

int main(){
  int T,N,X,Y, m,n,t,t2,nr,nc,r;
  map<int,map<int,int> > a;
  map<int,map<int,int> >::iterator i;
  map<int,int>::iterator j;
  T = getn();
  while(T--){
    N = getn(), nr = nc = r = 0;
    while(N--){
      X = getn(), Y = getn();
      if(a.find(X) == a.end()) nr++;
      if(a.find(-Y) == a.end()) nc++;
      a[X][-Y] = a[-Y][X] = 1;
    }
    while(a.size()){
      m = 0;
      for(i = a.begin(); i != a.end(); i++){
        if(i->second.size() > m){
          m = i->second.size(), n = i->first, t = 0;
          for(j = i->second.begin(); j != i->second.end(); j++)
            if(a[j->first].size() == 1)
              t++;
        }else if(i->second.size() == m){
          t2 = 0;
          for(j = i->second.begin(); j != i->second.end(); j++)
            if(a[j->first].size() == 1)
              t2++;
          if(t2 > t)
            m = i->second.size(), n = i->first;
        }
      }
      for(j = a[n].begin(); j != a[n].end(); j++){
        a[j->first].erase(n);
        if(!a[j->first].size())
          a.erase(j->first);
      }
      a.erase(n);
      r++;
    }
    if(nr < r) r = nr;
    if(nc < r) r = nc;
    printf("%d\n",r);
  }
  return 0;
}


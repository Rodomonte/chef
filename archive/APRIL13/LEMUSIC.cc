// LEMUSIC

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
using std::sort;
using std::vector;
using std::map;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define llu unsigned long long
int main(){
  int T = getn(),N,B,L, i,j, h;
  llu s;
  vector<int> bs;
  map<int, int> b;
  map<int, int>::iterator it;
  while(T--){
    N = getn(), h = 0, s = 0;
    b.clear(); bs.clear();
    for(i = 0; i < N; i++){
      B = getn(), L = getn();
      if((it=b.find(B)) == b.end())
        b[B] = L;
      else if(L < it->second){
        s += it->second;
        b[B] = L;
      }else
        s += L;
    }
    s *= b.size();
    for(it = b.begin(); it != b.end(); it++)
      bs.push_back(it->second);
    sort(bs.begin(), bs.end());
    for(i = 0; i < bs.size(); i++)
      s += (llu)bs.at(i) * ++h;
    printf("%llu\n",s);
  }
  return 0;
}

// CHEFBM

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define pc putchar_unlocked
char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

#define map unordered_map
#define pb push_back
struct C {
  int j,c;
  C(int j0, int c0): j(j0), c(c0) {}
};
bool comp(C a, C b){
  return a.j < b.j;
}
int main(){
  bool f;
  int N,M,P, i,j,s,p,n;
  map<int,map<int,int> > a;
  map<int,int>::iterator it;
  vector<C> b;
  N = getn(), M = getn(), P = getn();
  while(P--){
    i = getn(), j = getn();
    if(a.find(i) == a.end()){
      map<int,int> b;
      b[j] = 1;
      a[i] = b;
    }else if(a[i].find(j) == a[i].end()){
      a[i][j] = 1;
    }else
      a[i][j]++;
  }
  for(i = 1; i <= N; i++){
    if(a.find(i) == a.end()){
      putn(M-1); pc('\n');
      continue;
    }
    b.clear();
    for(it = a[i].begin(); it != a[i].end(); it++)
      b.pb(C(it->first, it->second));
    sort(b.begin(), b.end(), comp);
    s = M-1, f = false;
    if(b[0].j == 1)
      s -= b[0].c;
    if(b[b.size()-1].j == M)
      s += b[b.size()-1].c;
    for(j = 1; j < b.size(); j++){
      if(b[j].j == b[j-1].j+1){
        if(b[j-1].c - b[j].c > 1){
          f = true;
          break;
        }
      }else if(b[j-1].c > 1){
        f = true;
        break;
      }
    }
    if(!f && b[b.size()-1].j != M && b[b.size()-1].c > 1)
      f = true;
    if(f)
      printf("-1");
    else
      putn(s);
    pc('\n');
  }
  return 0;
}

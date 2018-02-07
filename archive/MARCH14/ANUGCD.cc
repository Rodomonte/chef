// ANUGCD

#include <stdio.h>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

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

struct S {
  int v, f;
  S(){}
  S(int v0, int f0): v(v0), f(f0) {}
  S& operator=(const S& o){ v = o.v, f = o.f; }
};

#define map unordered_map
#define MAX 100000
int N, li[16],ln,an;
map<int,S> a[MAX*2]; // prime factor -> (max in range, count)
vector<int> b[MAX+1]; // value -> prime factors
void build(){
  int i,j,s;
  map<int,S>::iterator its,itd;
  li[0] = 0, s = N, ln = 1;
  while(s > 1){
    li[ln] = li[ln-1] + s;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++){
      a[j] = a[i];
      for(its = a[i+1].begin(); its != a[i+1].end(); its++){
        itd = a[j].find(its->first);
        if(itd == a[j].end() || its->second.v > itd->second.v)
          a[j][its->first] = its->second;
        else if(its->second.v == itd->second.v)
          a[j][its->first].f += its->second.f;
      }
    }
    s >>= 1;
    ln++;
  }
  an = j;
}
void query(int g, int i0, int i1){
  char c;
  int i,j,l,e,ia,ib, v,f,t;
  map<int,S>::iterator it;
  v = f = l = 0, e = 1, i = i0;
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
      c = 1;
      for(j = 0; j < b[g].size(); j++){
        t = b[g].at(j);
        it = a[i].find(t);
        if(it != a[i].end()){
          if(it->second.v > v){
            v = it->second.v;
            f = it->second.f;
            c = 0;
          }else if(it->second.v == v && c){
            f += it->second.f;
            c = 0;
          }
        }
      }
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
  if(v){
    putn(v); pc(' '); putn(f); pc('\n');
  }else
    printf("-1 -1\n");
}

char s[MAX+1]={0};
int main(){
  int Q,A,G,X,Y, i,j,f;
  for(i = 2; i <= MAX; i++){
    if(s[i])
      continue;
    b[i].push_back(i);
    for(j = i+i; j <= MAX; j += i)
      s[j] = 1, b[j].push_back(i);
  }
  N = getn(), Q = getn();
  for(i = 0; i < N; i++){
    A = getn();
    for(j = 0; j < b[A].size(); j++)
      a[i][b[A].at(j)] = S(A, 1);
  }
  build();
  while(Q--){
    G = getn(), X = getn()-1, Y = getn()-1;
    if(G == 1){
      printf("-1 -1\n");
      continue;
    }
    query(G, X, Y);
  }
  return 0;
}

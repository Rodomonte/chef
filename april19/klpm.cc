// KLPM

// omg this took so long

#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define llu unsigned long long
#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  int i,j;
  P(){}
  P(int h): i(h >> 16), j(h & ((1 << 16) - 1)) {}
  P(int _i, int _j): i(_i), j(_j) {}
  int hash(){ return ((i << 16) | j); }
  P& operator=(const P& o){ i = o.i, j = o.j; return *this; }
};

struct Q {
  char c;
  llu h;
  Q(llu _h, char _c): h(_h), c(_c) {}
};

llu hash(llu h, int i, char c){
  return h ^= ((llu)(c - 'a' + 1) << ((i % 12) * 5));
}

char s[1001];
llu a[1000][1000];
vector<Q> b[1000][1000];
map<llu, vector<int> > m;

int main(){
  int i,j,k,ii, l;
  llu h,r;
  map<llu, vector<int> >::iterator it;

  scanf("%s", s);
  l = strlen(s);

  for(i = l-1; i >= 0; --i)
    for(j = i, h = 0; j >= 0; --j)
      b[j][i].pb(Q(h = hash(h, i-j, s[j]), 0));

  for(i = 0; i < l; ++i){
    for(j = i, h = 0; j < l; ++j){
      a[i][j] = h = hash(h, j-i, s[j]);
      if((it = m.find(h)) == m.end()){
        vector<int> t;
        t.pb(P(i, j).hash());
        m[h] = t;
      }else it->second.pb(P(i, j).hash());
    }
  }

  for(i = 1; i <= (l>>1)+1; ++i){
    for(j = 0; j < l-i+1; ++j){
      if((it = m.find(b[j][j+i-1][0].h)) != m.end()){
        for(k = 0; k < it->second.size(); ++k){
          if(P(it->second[k]).j == j-1){
            for(ii = j+i; ii < l && ((ii-(j+i-1))<<1)+(i<<1) <= l; ++ii)
              b[j-i][ii].pb(Q(b[j+i][ii][0].h, 1));
            for(ii = j-i-1; ii >= 0 && ((j-i-ii)<<1)+(i<<1) <= l; --ii)
              b[ii][j+i-1].pb(Q(b[ii][j-i-1][0].h, 0));
          }
        }
      }

      if(i > 1 && (it = m.find(b[j+1][j+i-1][0].h)) != m.end()){
        for(k = 0; k < it->second.size(); ++k){
          p = P(it->second[k]);
          if(p.j == j-1){
            for(ii = j+i; ii < l && ((ii-(j+i-1))<<1)+(i<<1)-1 <= l; ++ii)
              b[j-i+1][ii].pb(Q(b[j+i][ii][0].h, 1));
            for(ii = j-i; ii >= 0 && ((j-i-ii+1)<<1)+(i<<1)-1 <= l; --ii)
              b[ii][j+i-1].pb(Q(b[ii][j-i][0].h, 0));
          }
        }
        p = P(it->second[0]);
        b[j][j+i-1].pb(Q(a[p.i][p.j], 1));
      }

      if(i > 1 && (it = m.find(b[j][j+i-2][0].h)) != m.end()){
        p = P(it->second[0]);
        b[j][j+i-1].pb(Q(a[p.i][p.j], 0));
      }
    }
  }

  for(r = i = 0; i < l; ++i)
    for(j = i; j < l; ++j)
      for(k = 0; k < b[i][j].size(); ++k)
        if((it = m.find(b[i][j][k].h)) != m.end())
          for(ii = 0; ii < it->second.size(); ++ii){
            p = P(it->second[ii]);
            if((!b[i][j][k].c && p.i > j) || (b[i][j][k].c && p.j < i))
              ++r;
          }

  printf("%llu\n", r);
  return 0;
}

// KLPM TEST

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using std::string;
using std::map;

#define llu unsigned long long
#define gc getchar_unlocked
#define pb push_back
#define MAX 2000000

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
  P(int _i, int _j): i(_i), j(_j) {}
  P& operator=(const P& o){ i = o.i, j = o.j; return *this; }
};

struct Q {
  char c;
  llu h;
  Q(llu _h, char _c): h(_h), c(_c) {}
};

char s[1001], e[1000][1000];
int a[1000][1000], v[1000][1000];
llu al[1000][1000], vl[1000][1000];
map<int, int> m[2][1000000];
map<llu, int> w;

llu hash(llu h, int n, int i){
  return h ^= ((llu)(s[i] - 'a' + 1) << ((n % 12) * 5));
}

int main(){
  char c;
  int T, i,j,k, l,n,t, r,r2;
  llu h;
  map<int, int>::iterator mt;
  map<int, int>::reverse_iterator rt;
  map<llu, int>::iterator wt;

  llu ta,tb,tc,td;
  ta = tb = tc = td = 0;

  T = 0;
  while(++T){
    l = rand()%20+1, s[l] = 0;
    for(i = 0; i < l; ++i)
      s[i] = rand()%2+'a';
    printf("\nT%d:  |s|=%d  %s\n", T, l, s);

    for(i = 0; i < l; ++i)
      for(j = i; j < l; ++j)
        e[i][j] = -1;
    for(i = 0; i < l*l; ++i)
      m[0][i].clear(), m[1][i].clear();
    w.clear();

    llu t0 = clock();

    for(i = l-1; i >= 0; --i)
      for(j = i, h = 0; j >= 0; --j)
        vl[j][i] = h = hash(h, i-j, j);
    for(i = 0; i < l; ++i)
      for(j = i, h = 0; j < l; ++j)
        al[i][j] = h = hash(h, j-i, j), w[h] = -1;

    llu t1 = clock();
    ta += t1-t0;
    printf("\nTIME:\n%llu\n", ta);

    for(wt = w.begin(), n = 0; wt != w.end(); ++wt, ++n)
      wt->second = n;
    for(i = 0; i < l; ++i){
      for(j = i; j < l; ++j){
        a[i][j] = w[al[i][j]];
        wt = w.find(vl[i][j]);
        v[i][j] = (wt == w.end()) ? MAX : wt->second;
      }
    }

    llu t2 = clock();
    tb += t2-t1;
    printf("%llu\n", tb);

    for(i = 0; i < l; ++i)
      for(j = i; j < l; ++j)
        m[0][a[i][j]][j] = -1, m[1][a[i][j]][i] = -1;
    for(i = 0; i < l*l; ++i)
      for(mt = m[0][i].begin(), n = 1; mt != m[0][i].end(); ++mt, ++n)
        mt->second = n;
    for(i = l*l-1; i >= 0; --i)
      for(rt = m[1][i].rbegin(), n = 1; rt != m[1][i].rend(); ++rt, ++n)
        rt->second = n;

    llu t3 = clock();
    tc += t3-t2;
    printf("%llu\n", tc);

    for(r = i = 0; i < l; ++i){
      for(j = i; j < l; ++j){
        // abcba: ab<-ba
        if((t = v[i][j]) != MAX){
          mt = m[0][t].lower_bound(i);
          if(mt == m[0][t].begin()) continue;
          --mt, n = mt->second, r += n;
          // abba: a+bba abb+a
          if(mt->first == i-1){
            if(mt != m[0][t].begin() && (--mt)->first == i-2)
              r += ((j-i+1)<<1), --n;
            r += ((j-i)<<1), --n;
          // abcba: abc+ba ab+bca abcb+a a+bcba
          }else if(mt->first == i-2) r += ((j-i+1)<<1), --n;
          // abca: ab<-a a<-ca
          if(m[0][t].begin()->first < i-2 && n > 0) r += (n << 1);
        }

        if(i-(j-i+1) >= 0 && a[i][j] == v[i-(j-i+1)][i-1]){
          // abbca: abb->a
          for(k = i-(j-i+2); k >= 0; --k)
            if((t = v[k][i-(j-i+2)]) != MAX){
              mt = m[1][t].upper_bound(j+1);
              if(mt == m[1][t].end()) continue;
              r += mt->second;
            }else break;

          // acbba: a<-bba
          for(k = j+1; k < l; ++k)
            if((t = v[j+1][k]) != MAX){
              mt = m[0][t].lower_bound(i-(j-i+2));
              if(mt == m[0][t].begin()) continue;
              --mt, r += mt->second;
            }else break;
        }

        if(i-(j-i+2) >= 0 && a[i][j] == v[i-(j-i+2)][i-2]){
          // abcbda: abcb->a
          for(k = i-(j-i+3); k >= 0; --k)
            if((t = v[k][i-(j-i+3)]) != MAX){
              mt = m[1][t].upper_bound(j+1);
              if(mt == m[1][t].end()) continue;
              r += mt->second;
            }else break;

          // adbcba: a<-bcba
          for(k = j+1; k < l; ++k)
            if((t = v[j+1][k]) != MAX){
              mt = m[0][t].lower_bound(i-(j-i+3));
              if(mt == m[0][t].begin()) continue;
              --mt; r += mt->second;
            }else break;
        }
      }
    }

    // for(n = i = 1; i < l; ++i){
    //   n = (s[i] == s[i-1]) ? n+1 : 1;
    //   if(n >= 5) r +=
    // }

    llu t4 = clock();
    td += t4-t3;
    printf("%llu\n\nRUN: %llu\n", td, t4-t0);

    // BRUTE
    int ii,jj;
    for(r2 = i = 0; i < l; ++i){
      for(j = i; j < l; ++j){
        for(k = j+1; k < l; ++k){
          for(ii = k; ii < l; ++ii){
            c = s[j+1], s[j+1] = 0;
            string t = string(s+i);
            s[j+1] = c, c = s[ii+1], s[ii+1] = 0;
            t += string(s+k);
            s[ii+1] = c, c = 1;
            for(jj = 0; jj < (t.size()>>1); ++jj)
              if(t[jj] != t[t.size()-jj-1]){ c = 0; break; }
            if(c) ++r2;
          }
        }
      }
    }

    printf("%d %d\n", r, r2);
    if(r != r2) gc();
  }
  return 0;
}

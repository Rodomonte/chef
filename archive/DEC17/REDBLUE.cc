// REDBLUE

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

#define ll long long
#define gc getchar
#define pb push_back
#define PI 3.14159265358979323846264338327950288
#define XM 1000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }

struct P {
  char c;
  int x,y;
  P(){}
  P(int x0, int y0): x(x0), y(y0) {}
  P(int x0, int y0, char c0): x(x0), y(y0), c(c0) {}
};

const double PI2 = PI / 2.0;
int pi;
P a[2000];
double anga[2000][2000];

P fix(P& p){
  if(p.y < a[pi].y) return P(a[pi].x+a[pi].x-p.x, a[pi].y+a[pi].y-p.y);
  else return p;
}
double ang(int i, char e){
  if(!e) return anga[i][pi];
  P b(fix(a[i])), c(b.x, a[pi].y);
  if(b.x == a[pi].x) return (anga[i][pi] = PI2);
  if(b.y == a[pi].y) return (anga[i][pi] = (b.x < a[pi].x) ? PI : 0);
  double d = atan((double)(b.y-c.y) / (c.x-a[pi].x));
  return (anga[i][pi] = (d < 0) ? d+PI : d);
}
bool cmp(int i, int j){ return ang(i, 0) < ang(j, 0); }

int main(){
  int T,N,M, i,j, m, r,b,r2,b2;
  vector<int> s;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N+M; ++i)
      a[i].x = getn(), a[i].y = getn(), a[i].c = (i < N) ? 'R' : 'B';

    for(pi = 0; pi < N+M; ++pi) for(j = 0; j < N+M; ++j) if(i != j) ang(j, 1);
    for(i = 0, m = 1000; i < N+M; ++i){
      pi = i, s.clear();
      for(j = 0; j < N+M; ++j) if(i != j) s.pb(j);
      sort(s.begin(), s.end(), cmp);

      for(j = r = b = r2 = b2 = 0; j < N+M-1; ++j){
        if(a[s[j]].y < a[pi].y){ if(a[s[j]].c == 'R') ++r2; else ++b2; }
        else{ if(a[s[j]].c == 'R') ++r; else ++b; }
      }
      if(a[pi].c == 'R') ++r; else ++b;
      m = min(m, min(r + b2, b + r2));
      for(j = 0; j < N+M-1; ++j){
        if(a[s[j]].y < a[pi].y){
          if(a[s[j]].c == 'R') ++r, --r2; else ++b, --b2; }
        else{ if(a[s[j]].c == 'R') --r, ++r2; else --b, ++b2; }
        m = min(m, min(r + b2, b + r2));
      }

      for(j = r = b = r2 = b2 = 0; j < N+M-1; ++j){
        if(a[s[j]].y < a[pi].y ||
           (a[s[j]].y == a[pi].y && a[s[j]].x > a[pi].x)){
          if(a[s[j]].c == 'R') ++r2; else ++b2; }
        else{ if(a[s[j]].c == 'R') ++r; else ++b; }
      }
      if(a[pi].c == 'R') ++r2; else ++b2;
      m = min(m, min(r + b2, b + r2));
      for(j = 0; j < N+M-1; ++j){
        if(a[s[j]].y < a[pi].y ||
           (a[s[j]].y == a[pi].y && a[s[j]].x > a[pi].x)){
          if(a[s[j]].c == 'R') ++r, --r2; else ++b, --b2; }
        else{ if(a[s[j]].c == 'R') --r, ++r2; else --b, ++b2; }
        m = min(m, min(r + b2, b + r2));
      }
    }

    printf("%d\n", m);
  }
  return 0;
}

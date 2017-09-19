// CHEFJR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>

#define vec vector
#define pq priority_queue
#define gc getchar_unlocked
#define pb push_back

using std::vec;
using std::pq;
using std::map;

inline int gi(){
  char c = gc(); int n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n; }

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

struct B { B(){} void init(int t0, int p0, int w0){t=t0,p=p0,w=w0,wt=pt=0,s=-1;}
  int t,p,w,wt,pt,s;
  double wp;
  vec<int> ni,no; }; //! remove no if unused
struct BP { BP(B* b0, int pt0){b=b0,pt=pt0;}
  B* b;
  int pt; };
struct BPcmp {
  bool operator()(const BP& a, const BP& b){ return a.b->wp < b.b->wp; } };
struct RP { RP(int i0, int p0){i=i0,p=p0;}
  int i,p; };
struct R { R(){}
  int p;
  vec<RP> r; };

#define ITER 1000000000

B ba[100000]; R ra[50000];
pq<BP, vec<BP>, BPcmp> bq;
vec<map<int, vec<int> > > rm; // rm[ijk]: in sqrt block i, all ri with r.p=j

void wp(B& b){
  if(b.wt) return;
  for(int i : b.ni) wp(ba[i]), b.wt += ba[i].wt, b.pt += ba[i].pt;
  b.wt += b.w, b.pt += b.p, b.wp = (double)b.wt*1.5/b.pt; }

int wpt(B& b, B& a){ int iter = 1;
  b.wt -= a.w, b.pt -= a.p;
  for(int i : b.no) iter += wpt(ba[i], a);
  return iter; }

int wpbq(B& b){ int iter = 1;
  b.wp = (double)b.wt*1.5/b.pt, bq.push(BP(&b, b.pt));
  for(int i : b.no) iter += wpbq(ba[i]);
  return iter; }

int read(BP bp, bool f=false){ int iter = 0;
  B& b = *bp.b;
  if(!b.pt || b.s == -2 || bp.pt != b.pt) return 1;
  int i,j,s;
  map<int, vec<int> >::iterator it,jt;
  s = -1;
  for(int k : b.ni){
    iter += read(BP(ba+k, ba[k].pt), true);
    if(ba[k].s == -2){ b.s = -2; break; }
    s = max(s, ba[k].s); }
  if(b.s == -2) return iter;
  if(1){ //! b.t == 1){
    for(i = s+1; i < rm.size(); ++i){
      it = rm[i].lower_bound(b.p);
      if(it != rm[i].end()) break; }
    iter += (i-s)<<3;
    if(i == rm.size()){ b.s = -2; return iter; }
    R& r = ra[(j = it->second.back())];
    r.p -= b.p, r.r.pb(RP(&b-ba, b.p));
    if(it->second.size() == 1) rm[i].erase(it);
    else it->second.pop_back();
    if(r.p){
      jt = rm[i].find(r.p);
      if(jt == rm[i].end()) rm[i][r.p] = vec<int>(1, j);
      else jt->second.pb(j); }
    iter += wpt(b, b), b.s = i, b.wp = b.w = b.p = 0;
    if(!f) iter += wpbq(b);
  }else{}
  return iter; }

int main(){ int iter = 0;
  int N,M,K, i,j,k,s,t;
  map<int, vec<int> >::iterator it;
  N = gi(), M = gi(), K = gi(), s = sqrt(N), t = N/s;
  for(i = j = 0; j < s; ++j){
    rm.pb(map<int, vec<int> >());
    for(k = 0; (j == s-1) ? (i < N) : (k < t); ++i, ++k){
      ra[i].p = gi(), it = rm.back().find(ra[i].p);
      if(it == rm.back().end()) rm.back()[ra[i].p] = vec<int>(1, i);
      else it->second.pb(i); } }
  for(i = 0; i < M; ++i) j = gi(), k = gi(), ba[i].init(j, k, gi());
  for(i = 0; i < K; ++i) j = gi()-1, k = gi()-1, ba[j].no.pb(k), ba[k].ni.pb(j);
  for(i = 0; i < M; ++i) wp(ba[i]), bq.push(BP(ba+i, ba[i].pt));
  //! small N,M?
  while(!bq.empty() && iter < ITER) iter += read(bq.top()), bq.pop();
  for(i = 0; i < rm.size(); ++i) // collect readable books pq, defrag, place
  for(i = 0; i < N; ++i){
    printf("%d", (int)ra[i].r.size());
    for(j = 0; j < ra[i].r.size(); ++j)
      printf(" %d %d", ra[i].r[j].i+1, ra[i].r[j].p);
    printf("\n"); }
  return 0; }

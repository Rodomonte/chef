// WORDNINJ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>

using std::sort;
using std::pair;
using std::vector;
using std::multimap;

#define DBG 0
#define TST 0

#define LA 6
#define M1 100
#define M2 6000
// M2=6000 ts=19114 time=7815 (max ~8k)
// ^ no break on first 7

#define ll long long
#define gc getchar_unlocked
#define pb push_back
#define DN 74414
#define BN 10000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

int score(vector<char>& s, vector<char>& w);

const char* cs[] = {"abcdefghijklmnopqrstuvwxyz", "AEILNORSTU", "DG", "BCMP",
                    "FHVWY", "K", "", "", "JX", "", "QZ"};

struct P {
  char w;
  int n[26];
  P(): w(0) { int i; for(i = 0; i < 26; ++i) n[i] = -1; }
};

struct Q {
  char a;
  int k;
  vector<char> t,w;
  vector<int> b;
  Q(): k(-1) {}
  Q(int k0, vector<int> b0, char a0): k(k0), b(b0), a(a0) {}
  void print(){
    int i;
    printf("Q s=%d k=%d a=%d: b=[", score(t, w), k, a);
    for(i = 0; i < b.size(); ++i) printf("%d ", b[i]);
    printf("] t=[");
    for(i = 0; i < t.size(); ++i) printf("%c ", t[i]);
    printf("] w=[");
    for(i = 0; i < w.size(); ++i) printf("%c ", w[i]);
    printf("]\n");
  }
};

struct R { char t, p[8]; R(){ p[0] = -1; } };

void shuf(vector<char>& v){
  char t;
  int i,j;
  for(i = 0; i < v.size()-1; ++i){
    j = rand()%(v.size()-i)+i;
    t = v[i], v[i] = v[j], v[j] = t;
  }
}

vector<char> s2v(const char* s){
  int i;
  vector<char> v;
  for(i = 0; i < strlen(s); ++i) v.pb(s[i]);
  return v;
}

///////////////////////
char b[BN][11], c[123];
int N,M;
Q e[BN];
R r[BN];
vector<P> p;
vector<char> d[DN];
///////////////////////

void read(){
  char f, s[11];
  int i,j,k,l;
  if(TST){
    FILE* file = fopen("dict.txt", "r");
    fscanf(file, "%d", &N);
    for(i = 0; i < N; ++i){
      fscanf(file, "%s", s);
      for(j = 0; j < strlen(s); ++j) d[i].pb(s[j]);
    }

    //srand(clock());
    vector<char> t;
    for(i = 0; i < 90; ++i){
      for(j = 0; j < 12; ++j) t.pb('E');
      for(j = 0; j < 9; ++j) t.pb('A'), t.pb('I');
      for(j = 0; j < 8; ++j) t.pb('O');
      for(j = 0; j < 6; ++j) t.pb('N'), t.pb('R'), t.pb('T');
      for(j = 0; j < 4; ++j) t.pb('L'), t.pb('S'), t.pb('U'), t.pb('D');
      for(j = 0; j < 3; ++j) t.pb('G');
      for(j = 0; j < 2; ++j) t.pb('?'), t.pb('B'), t.pb('C'), t.pb('M'),
        t.pb('P'), t.pb('F'), t.pb('H'), t.pb('V'), t.pb('W'), t.pb('Y');
      t.pb('K'), t.pb('J'), t.pb('X'), t.pb('Q'), t.pb('Z');
    }
    for(j = 0; j < 30; ++j) t.pb('*');
    for(j = 0; j < 70; ++j) t.pb('+');
    for(j = 0; j < 300; ++j) t.pb('#'+rand()%7);
    for(j = 0; j < 600; ++j) t.pb('1'+rand()%7);
    shuf(t);

    char f;
    int n,u;
    for(i = l = 0; i < t.size() && l < BN; ++l){
      n = rand()+1;
      for(j = u = 0; j < n; ++i, ++j){
        for(k = 0, f = 1; k < j; ++k) if(b[l][k] == t[i]){ f = 0; break; }
        if(f) b[l][u++] = t[i];
      }
      b[l][u] = '\0';
    }
    M = l;

  }else{
    N = getn();
    for(i = 0; i < N; ++i){
      scanf("%s", s);
      for(j = 0; j < strlen(s); ++j) d[i].pb(s[j]);
    }
    M = getn();
    for(i = 0; i < M; ++i){
      scanf("%s", s);
      for(j = l = 0; j < strlen(s); ++j){
        for(k = j-1, f = 1; k >= 0; --k) if(s[k] == s[j]){ f = 0; break; }
        if(f) b[i][l++] = (s[j] >= 'a' && s[j] <= 'b') ?
                          (char)(s[j]-'a'+'#') : s[j];
      }
      b[i][l] = '\0';
    }
  }
}

int score(vector<char>& s, vector<char>& w){
  int i,r,t, m[] = {1,1,1,1,1,1,1}, x = 1;
  for(i = t = 0; i < s.size(); ++i){
    if(s[i] >= '1' && s[i] <= '7') m[s[i]-'1'] = 2, t += 2;
    else if(s[i] >= '#' && s[i] <= ')') m[s[i]-'#'] = 3, t += 2;
    else if(s[i] == '+') x = 2, t += 2;
    else if(s[i] == '*') x = 3, t += 2;
    else if(s[i] >= 'a' && s[i] <= 'z') t += 5;
  }
  for(i = r = 0; i < w.size(); ++i) r += c[w[i]] * m[i];
  return r * x + t + max(i-3, 0)*3 + max(i-6, 0)*30 +
         ((w.empty() || TST) ? 0 : c[w.back()]);
}

bool dcmp(vector<char> a, vector<char> b){ return score(a, a) > score(b, b); }

void init(){
  int i,j,k;
  for(i = 0; i <= 10; ++i) for(j = 0; j < strlen(cs[i]); ++j) c[cs[i][j]] = i;
  p.pb(P());
  for(i = 0; i < N; ++i){
    for(j = k = 0; j < d[i].size(); ++j){
      if(p[k].n[d[i][j]-'A'] == -1){
        p.pb(P()), p[k].n[d[i][j]-'A'] = k = p.size()-1;
        if(j == d[i].size()-1) p[k].w = 1;
      }
      else k = p[k].n[d[i][j]-'A'];
    }
  }
  sort(d, d+N, dcmp);
}

// int find(string s){
//   int i,k;
//   for(i = k = 0; i < s.size(); ++i){
//     k = p[k].n[s[i]-'A'];
//     if(k == -1) return -1;
//   }
//   return k;
// }

void sc(Q& u, char a){
  char f;
  int i,j;
  for(i = 0; i < u.w.size(); ++i){
    for(j = f = 0; j < u.t.size(); ++j) if(u.w[i] == u.t[j]){ f = 1; break; }
    if(u.w[i] == a || (a >= 'a' && a <= 'z' && u.w[i] >= 'a' && u.w[i] <= 'z'))
      f = 1;
    if(!f) printf("BAD u.w a=%c\n", a), u.print(), gc();
  }
}

Q best(int i, char a, Q& q0){
  char x;
  int j,k,l, m,n, it;
  Q u,r;
  vector<int> v;
  multimap<int,Q> q;

  q.insert(pair<int,Q>(score(q0.t, q0.w), q0));
  it = 0, m = 0, r.k = -1;
  while(!q.empty()){
    if(++it > M2) break;
    u = (--q.end())->second;
    q.erase(--q.end());
    if(TST || DBG) sc(u, a);
    if(p[u.k].w && (n = score(u.t, u.w)) > m) m = n, r = u;

    if(a && !u.a){
      if(a >= 'A' && a <= 'Z' && p[u.k].n[a-'A'] != -1){
        Q qx(p[u.k].n[a-'A'], u.b, 1);
        qx.t = u.t, qx.w = u.w, qx.w.pb(a);
        q.insert(pair<int,Q>(score(qx.t, qx.w), qx));
        if(DBG) printf("Pushing "), qx.print();
        if(qx.k < 0 || qx.k > p.size()-1) printf("k OOB\n"), gc();
      }else if(a >= 'a' && a <= 'z'){
        for(j = 0; j < 26; ++j){ if(p[u.k].n[j] != -1){
          Q qx(p[u.k].n[j], u.b, 1);
          qx.t = u.t, qx.w = u.w, qx.w.pb(j+'a');
          q.insert(pair<int,Q>(score(qx.t, qx.w), qx));
          if(DBG) printf("Pushing "), qx.print();
          if(qx.k < 0 || qx.k > p.size()-1) printf("k OOB\n"), gc();
        }}
      }
    }

    for(j = 0; j < u.b.size(); ++j){
      for(k = 0; k < (int)strlen(b[u.b[j]]); ++k){
        x = b[u.b[j]][k];
        if((x == '?' || (x >= 'A' && x <= 'Z')) &&
           ((u.w.size() == 7 && u.a) || (u.w.size() == 6 && !u.a))) continue;

        if(x >= '1' && x <= '7' &&
           (u.w.size() <= x-'1' || c[u.w[x-'1']]*2 < 4)) continue;
        if(x >= '#' && x <= ')' &&
           (u.w.size() <= x-'#' || c[u.w[x-'#']]*3 < 6)) continue;

        if(x == '+' || x == '*' || x == ' ' ||
           (x >= '1' && x <= '7') || (x >= '#' && x <= ')') ||
           (x >= 'A' && x <= 'Z' && p[u.k].n[x-'A'] != -1)){
          for(l = 0, v.clear(); l < u.b.size(); ++l) if(l != j) v.pb(u.b[l]);
          n = (x >= 'A' && x <= 'Z') ? p[u.k].n[x-'A'] : u.k;
          Q qx(n, v, u.a);
          qx.t = u.t, qx.t[u.b[j]-i] = x, qx.w = u.w;
          if(x >= 'A' && x <= 'Z') qx.w.pb(x);

          //!
          // if((x == '+' || x == '*' || x == ' ' || (x >= '1' && x <= '7') ||
          //    (x >= '#' && x <= ')')) && i+qx.t.size() < M)
          //   qx.t.pb(' '), qx.b.pb(i+qx.t.size()-1);

          q.insert(pair<int,Q>(score(qx.t, qx.w), qx));
          if(DBG) printf("Pushing "), qx.print();
          if(qx.k < 0 || qx.k > p.size()-1) printf("k OOB\n"), gc();

        }else if(x == '?'){
          for(l = 0, v.clear(); l < u.b.size(); ++l) if(l != j) v.pb(u.b[l]);
          for(l = 0; l < 26; ++l){ if(p[u.k].n[l] != -1){
            Q qx(p[u.k].n[l], v, u.a);
            qx.t = u.t, qx.t[u.b[j]-i] = l+'a', qx.w = u.w, qx.w.pb(l+'a');
            q.insert(pair<int,Q>(score(qx.t, qx.w), qx));
            if(DBG) printf("Pushing "), qx.print();
            if(qx.k < 0 || qx.k > p.size()-1) printf("k OOB\n"), gc();
          }}
        }
      }
    }
  }
  if(TST || DBG) r.print();
  return r;
}

int ts;
void rec(int& i, char& a, Q& t){
  int j,k;
  if(t.k != -1 && score(t.t, t.w)){
    if(DBG || TST) t.print();
    for(j = k = 0; j < t.t.size(); ++j)
      r[i+j].t = (t.t[j] >= 'a' && t.t[j] <= 'z') ? '?' : t.t[j];
    for(j = 0; j < t.w.size(); ++j) r[i+t.t.size()-1].p[j] = t.w[j];
    i += t.t.size(), r[i-1].p[j] = '\0', a = r[i-1].p[j-1];
    ts += score(t.t, t.w);
    if(DBG) printf("a=%c\n", a);
  }else r[i++].t = ' ';
}

ll t0,t1;
void solve(){
  char a,f,x,y;
  int i,j,k,l, m,n;
  vector<int> v;

  t0 = clock(), ts = 0;
  for(i = 0; i < M-7; ++i){
    m = n = l = -1;
    for(j = i; j < i+8; ++j){
      for(k = 0; k < strlen(b[j]); ++k){
        if(m == -1 && (b[j][k] == '*' || b[j][k] == '+')){
          m = j, f = b[j][k]; break; }
        if(n == -1 && (b[j][k] == '#' || b[j][k] == '1')){
          n = j, a = b[j][k]; break; }
        if(l == -1 && b[j][k] >= 'A' && b[j][k] <= 'Z' && c[b[j][k]] >= 8){
          l = j, x = b[j][k]; break; }
      }
    }
    if(m == -1 || n == -1 || l == -1) continue;

    e[i].a = 0, e[i].k = p[0].n[x-'A'];
    for(j = i; j < i+8; ++j){
      if(j != m && j != n && j != l) e[i].b.pb(j);
      e[i].t.pb(' ');
    }
    e[i].t[m-i] = f, e[i].t[n-i] = a, e[i].t[l-i] = x, e[i].w.pb(x);
  }

  for(i = a = 0; i < M;){
    if(TST) printf("i=%d\n", i);
    for(j = i; j < min(i+LA, M); ++j) if(e[j].k != -1) break;
    y = (j == i) ? 1 : 0;
    v.clear();
    Q qt(0, v, 0);
    for(j = 0; j < min(LA, M-i); ++j) qt.t.pb(' ');
    for(j = i, f = 1; j < min(i+LA, M); ++j){
      x = 1;
      if(f) for(k = 0; k < strlen(b[j]); ++k)
        if(b[j][k] == '*' || b[j][k] == '+'){
          qt.t[j-i] = b[j][k];
          if(i+LA < M) qt.t.pb(' '), qt.b.pb(i+LA);
          f = x = 0; break;
        }
      if(x) qt.b.pb(j);
    }
    Q qr = best(i, a, qt);

    if(y){
      Q qx = best(i, a, e[i]);
      if(qx.k != -1 && qx.b.empty() &&
         score(qx.t, qx.w) != score(e[i].t, e[i].w) &&
         score(qx.t, qx.w) > score(qr.t, qr.w)) qr = qx;
    }
    rec(i, a, qr);
  }
  t1 = clock();
}

// [#$%&'()] -> [abcdefg]
void write(){
  char x;
  int i,j;
  for(i = 0; i < M; ++i){
    x = (r[i].t >= '#' && r[i].t <= ')') ? r[i].t-'#'+'a' : r[i].t;
    if(x != ' ') printf("Take %c", x);
    if(x != ' ' && (DBG || TST)){
      printf(" (");
      for(j = 0; j < strlen(b[i]); ++j) printf("%c", b[i][j]);
      printf(")");
    }
    if(x != ' ') printf("\n");
    if(r[i].p[0] != -1) printf("Play %s\n", r[i].p);
    if(x == ' ') printf("Skip");
    if(x == ' ' && (DBG || TST)){
      printf(" (");
      for(j = 0; j < strlen(b[i]); ++j) printf("%c", b[i][j]);
      printf(")");
    }
    if(x == ' ') printf("\n");
  }
  if(TST) printf("ts = %d  time = %lld\n", ts, t1-t0);
}


int main(){
  read();
  init();
  solve();
  write();
  return 0;
}

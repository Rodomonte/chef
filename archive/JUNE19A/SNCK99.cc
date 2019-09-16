// SNCK99

#include <stdio.h>
#include <vector>

using std::vector;

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
  char c;
  int s;
  vector<int> e;
};

struct C {
  int i,j,w;
};

P a[513];
C c[130817];

struct B {
  int i;
  bool operator<(const B& o) const {
    return (double)a[c[i].i].s * a[c[i].j].s / c[i].w >
           (double)a[c[o.i].i].s * a[c[o.i].j].s / c[o.i].w;
  }
};

B b[130816];

void sort(B* a, int n){
  if(n < 2) return;
  B p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(p < *r){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1), sort(l, a+n-l);
}

int main(){
  int N,M,O, i,j;

  N = getn(), M = getn();
  for(i = 1; i <= N; ++i)
    a[i].s = getn(), a[i].c = 0;
  for(i = 1; i <= M; ++i)
    c[i].w = getn(), b[i-1].i = i;
  for(i = 1; i <= M; ++i)
    c[i].i = getn(), c[i].j = getn(), a[c[i].i].e.pb(i), a[c[i].j].e.pb(i);

  sort(b, M);
  for(i = 0; i < M; ++i){
    j = b[i].i;
    if(!a[c[j].i].c && !a[c[j].j].c) a[c[j].i].c = 'C', a[c[j].j].c = 'G';
    else if(!a[c[j].i].c) a[c[j].i].c = (a[c[j].j].c == 'C') ? 'G' : 'C';
    else if(!a[c[j].j].c) a[c[j].j].c = (a[c[j].i].c == 'C') ? 'G' : 'C';
    if(c[j].w > a[c[j].i].s * a[c[j].j].s) continue;

    if(a[c[j].i].c == a[c[j].j].c){
      printf("%d\n", j), fflush(stdout);
      O = getn();
      if(!O) j = getn(), a[j].s = getn();
      else if(O == 1) j = getn(), c[j].w = getn();
    }
  }

  for(i = 1; i <= N; ++i)
    if(!a[i].c) a[i].c = 'C';

  printf("-1\n");
  fflush(stdout);
  for(i = 1; i <= N; ++i)
    printf("%c", a[i].c);
  printf("\n");
  fflush(stdout);
  return 0;
}

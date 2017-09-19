// MOU1H

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

#define MOD 1000000009
#define MAXN 100000
#define MAXH 266667
int HASH;

typedef struct {
  int o, f, l;
} S ;
typedef struct {
  int f, l, s, e;
} E ;

int a[MAXN], N;
int b[MAXN * 2], bc;
E ea[MAXH];

int EC3(E* e, int f, int l, int s){
  e->f = f;
  e->l = l;
  e->s = s;
  e->e = bc++;
  return e->e;
}

void ESET(E *d, E *s){
  d->f = s->f;
  d->l = s->l;
  d->s = s->s;
  d->e = s->e;
}

int EH(int n, int c){
  return ((n << 8) + c) % HASH;
}

void EI(E *e){
  int i = EH(e->s, a[e->f]);
  while(ea[i].s != -1)
    i = ++i % HASH;
  ESET(&ea[i], e);
}

void ER(E* e){
  int i, j, r;
  i = EH(e->s, a[e->f]);
  while(ea[i].s != e->s || ea[i].f != e->f)
    i = ++i % HASH;
  while(1){
    ea[i].s = -1, j = i;
    while(1){
      i = ++i % HASH;
      if(ea[i].s == -1)
        return;
      r = EH(ea[i].s, a[ea[i].f]);
      if((i >= r && r > j) || (r > j && j > i) || (j > i && i >= r))
        continue;
      break;
    }
    ESET(&ea[j], &ea[i]);
  }
}

E* EF(int n, int c){
  int i = EH(n, c);
  while(1){
    if(ea[i].s == -1 || (ea[i].s == n && a[ea[i].f] == c))
      return &ea[i];
    i = ++i % HASH;
  }
}

int ES(E* e, S* s){
  int ne;
  E e2, n;
  ESET(&e2, e);
  ER(e);
  ne = EC3(&n, e2.f, e2.f + s->l - s->f, s->o);
  EI(&n);
  b[ne] = s->o;
  e2.f += s->l - s->f + 1, e2.s = ne;
  EI(&e2);
  return ne;
}

void SC(S* s){
  int n;
  E* e;
  if(s->f <= s->l){
    e = EF(s->o, a[s->f]);
    n = e->l - e->f;
    while(n <= s->l - s->f){
      s->f += n + 1, s->o = e->e;
      if(s->f <= s->l){
        e = EF(e->e, a[s->f]);
        n = e->l - e->f;
      }
    }
  }
}

void AP(S* s, int l){
  int p, lp = -1;
  E *e, n;
  while(1){
    p = s->o;
    if(s->f > s->l){
      e = EF(s->o, a[l]);
      if(e->s != -1)
        break;
    }else{
      e = EF(s->o, a[s->f]);
      if(a[e->f + s->l - s->f + 1] == a[l])
        break;
      p = ES(e, s);
    }
    EC3(&n, l, N-1, p);
    EI(&n);
    if(lp > 0)
      b[lp] = p;
    lp = p;
    if(s->o)
      s->o = b[s->o];
    else
      s->f++;
    SC(s);
  }
  if(lp > 0)
    b[lp] = p;
  s->l++;
  SC(s);
};

int eval(){
  int i, r = 0, t;
  for(i = 0; i < HASH; i++){
    E* e = ea + i;
    if(e->s == -1)
      continue;
    t = (N-1 > e->l) ? e->l : N-1;
    r += t - e->f + 1;
    if(r >= MOD)
      r -= MOD;
  }
  return r;
}

int main(){
  int T = getn(), i, n,p;
  while(T--){
    N = getn()-1, p = getn(), bc = 1;
    HASH = (double)(N*2) / 0.75;
    if(HASH % 2 == 0)
      HASH++;
    for(i = 0; i < N*2; i++)
      b[i] = -1;
    for(i = 0; i < HASH; i++)
      ea[i].s = -1;
    for(i = 0; i < N; i++){
      n = getn();
      a[i] = n - p + 202;
      p = n;
    }
    S s;
    s.o = 0, s.f = 0, s.l = -1;
    for(i = 0; i < N; i++)
      AP(&s, i);
    printf("%d\n",eval());
  }
    return 0;
};

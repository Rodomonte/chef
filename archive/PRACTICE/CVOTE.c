// CVOTE

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int KMOD;
int key(char* s){
  int i, k = 0;
  for(i = 0; s[i] != '\0'; i++)
    k += s[i];
  return k % KMOD;
}
struct C {
  char c[11];
  int v;
  struct C* n;
};
struct P {
  char p[11];
  int v;
  struct C* c;
  struct P* n;
};
struct P pa[10000], *pt[13333]={0}, *pp;
struct C ca[10000], *ct[13333]={0}, *cp;
int main(){
  char s[11], f, *mps,*mcs;
  int N,M, i,ci, k,mp,mc;
  N = getn(), M = getn(), ci = mp = mc = 0;
  KMOD = (double)N / 0.75;
  for(i = 0; i < N; i++){
    scanf("%s %s",pa[i].p,s);
    k = key(pa[i].p);
    pa[i].v = 0, pa[i].n = pt[k];
    pt[k] = pa+i;
    k = key(s);
    cp = ct[k], f = 1;
    while(cp && f){
      if(!strcmp(s, ct[k]->c)){
        f = 0;
        break;
      }
      cp = cp->n;
    }
    if(f){
      strcpy(ca[ci].c, s);
      ca[ci].v = 0, ca[ci].n = ct[k];
      ct[k] = ca+ci;
      ci++;
    }
    pa[i].c = ct[k];
  }
  for(i = 0; i < M; i++){
    scanf("%s",s);
    k = key(s);
    pp = pt[k];
    while(pp && strcmp(pp->p, s))
      pp = pp->n;
    pp->v++;
    if(pp->v > mp)
      mp = pp->v, mps = pp->p;
    else if(pp->v == mp && strcmp(pp->p, mps) < 0)
      mps = pp->p;
    cp = pp->c;
    cp->v++;
    if(cp->v > mc)
      mc = cp->v, mcs = cp->c;
    else if(cp->v == mc && strcmp(cp->c, mcs) < 0)
      mcs = cp->c;
  }
  printf("%s\n%s\n",mcs,mps);
  return 0;
}

// LMATRIX2

#include <stdio.h>
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}
int abs(int a){
  return a < 0 ? -a : a;
}
typedef struct {
  char v;
  int m,d,a[11];
} S ;
int r[9801][5],rn;
S a[100][100];
char sat(S* s, S* o){
  int i,j,g;
  for(i = 2; i <= 10; i++){
    for(j = 2; j <= 10; j++){
      if(s->a[i] != -1 && o->a[j] != -1){
        g = gcd(i, j);
        if(g > 1 && abs(s->a[i] - o->a[j]) % g > 0)
          return 0;
      }
    }
  }
  return 1;
}
int main(){
  char f;
  int N,M,D, i,j,k, ni,nj,vc,ms,mj,t, c[11][10]={{0}};
  S *ns,*s,*ls,*ts, cs,cs2;
  N = getn(), M = getn();
  for(i = 1; i <= N; i++)
    for(j = 1; j <= M; j++)
      a[i][j].m = getn();
  for(i = 1; i <= N; i++){
    for(j = 1; j <= M; j++){
      s = a[i]+j;
      D = s->m - getn();
      s->d = (D == s->m) ? 0 : D;
      s->v = 0;
    }
  }
  ni = nj = 1, ns = a[1]+1, rn = 0, vc = N*M;
  for(i = 1; i <= N; i++)
    for(j = 1; j <= M; j++)
      c[a[i][j].m][a[i][j].d]++;
  for(i = 2; i <= 10; i++)
    cs.a[i] = -1;
  for(i = 2; i <= 10; i++){
    for(ms = j = 0; j <= 9; j++){
      for(k = 2; k <= 10; k++)
        cs2.a[k] = cs.a[k];
      cs2.a[i] = j;
      if(sat(&cs,&cs2) && c[i][j] > ms)
        ms = c[i][j], cs.a[i] = j;
    }
  }
  f = 1, k = -1;
  while(f){
    k++, f = 0;
    for(i = 2; i <= 10; i++){
      if(cs.a[i] != -1 && cs.a[i] != k % i){
        f = 1;
        break;
      }
    }
  }
  if(k){
    for(i = 1; i <= N; i++){
      for(j = 1; j <= M; j++){
        s = a[i]+j;
        s->d = s->m - (((s->m - s->d) + k) % s->m);
        s->d = (s->d == s->m) ? 0 : s->d;
      }
    }
    r[0][0] = r[0][1] = 1;
    r[0][2] = N, r[0][3] = M;
    r[0][4] = k, rn++;
  }
  while(vc){
    if(ns->v){
      if(++nj > M)
        ni++, nj = 1;
      ns = a[ni]+nj;
      continue;
    }
    if(!ns->d){
      ns->v = 1, vc--;
      continue;
    }
    r[rn][0] = ni, r[rn][1] = nj;
    // Row 1
    for(k = 2; k <= 10; k++)
      ns->a[k] = -1;
    ns->a[ns->m] = ns->d;
    ls = ns, s = ns+1;
    for(j = nj+1; j <= M; j++){
      if(s->v) break;
      for(k = 2; k <= 10; k++)
        s->a[k] = ls->a[k];
      s->a[s->m] = s->d;
      if(!sat(s, ls)) break;
      ls++, s++;
    }
    ms = j-nj, r[rn][2] = ni, r[rn][3] = mj = j-1;
    // Row 2+
    for(i = ni+1; i <= N; i++){
      // Col 1
      ts = a[i-1]+nj, s = a[i]+nj;
      if(s->v) break;
      for(k = 2; k <= 10; k++)
        s->a[k] = ts->a[k];
      s->a[s->m] = s->d;
      if(!sat(s, ts)) break;
      if(i-ni+1 > ms)
        ms = i-ni+1, r[rn][2] = i, r[rn][3] = nj;
      // Col 2+
      ls = s, s++, ts++;
      for(j = nj+1; j <= mj; j++){
        if(s->v || !sat(ls, ts)) break;
        for(k = 2; k <= 10; k++){
          s->a[k] = ls->a[k];
          if(ts->a[k] != -1)
            s->a[k] = ts->a[k];
        }
        s->a[s->m] = s->d;
        if(!sat(s, ls) || !sat(s, ts)) break;
        t = (i-ni+1)*(j-nj+1);
        if(t > ms)
          ms = t, r[rn][2] = i, r[rn][3] = j;
        ls++, s++, ts++;
      }
      mj = j-1;
    }
    // Visit, find K
    for(i = r[rn][0]; i <= r[rn][2]; i++)
      for(j = r[rn][1]; j <= r[rn][3]; j++)
        a[i][j].v = 1, vc--;
    f = 1, k = -1, s = a[r[rn][2]]+r[rn][3];
    while(f){
      k++, f = 0;
      for(i = 2; i <= 10; i++){
        if(s->a[i] != -1 && s->a[i] != k % i){
          f = 1;
          break;
        }
      }
    }
    r[rn][4] = k, rn++;
    if(++nj > M)
      ni++, nj = 1;
    ns = a[ni]+nj;
  }
  printf("%d\n",rn);
  for(i = 0; i < rn; i++)
    printf("%d %d %d %d %d\n",r[i][0],r[i][1],r[i][2],r[i][3],r[i][4]);
  return 0;
}

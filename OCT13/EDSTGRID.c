// EDSTGRID

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

typedef struct {
  int i,j,gi,gj,d;
} B ;
void setB(B* d, B* s){
  d->i = s->i, d->j = s->j, d->d = s->d;
  d->gi = s->gi, d->gj = s->gj;
}
void sort(B* a, int n){
  if(n < 2) return;
  int p = a[n/2].d;
  B *l = a, *r = a+n-1, t;
  while(l <= r){
    if(l->d < p){ l++; continue; }
    if(r->d > p){ r--; continue; }
    setB(&t, l); setB(l, r); setB(r, &t);
    l++; r--;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}
int abs(int n){
  return n < 0 ? -n : n;
}

char a[101][101];
int r[8000][5], rn;
void move(B* p, int i, int j){
  a[p->i][p->j] = 0, a[i][j] = 1;
  r[rn][0] = 1, r[rn][1] = p->i, r[rn][2] = p->j;
  r[rn][3] = i, r[rn++][4] = j;
  p->i = i, p->j = j;
  p->d--;
}
int main(){
  char hm[101][101], c,f,f2;
  int T,N,M,C2,C3, i,j,k,l, h[310][2], hn,bn,s,t,t2;
  B b[1200], *p;
  T = getn();
  while(T--){
    N = getn(), M = getn(), C2 = getn(), C3 = getn(), hn = bn = rn = 0;
    for(i = 1; i <= N; i++)
      for(j = 1; j <= M; j++)
        hm[i][j] = 0;
    for(i = N/6+1, j = M/6+1; i <= 5*N/6+1; i++)
      h[hn][0] = i, h[hn++][1] = j, hm[i][j] = 1;
    for(i = N/6+1, j = 5*M/6+1; i <= (N>M?5*N/6+1:2*N/3+1); i++)
      h[hn][0] = i, h[hn++][1] = j, hm[i][j] = 1;
    for(i = N/6+1, j = M/6+1; j <= 5*M/6+1; j++)
      h[hn][0] = i, h[hn++][1] = j, hm[i][j] = 1;
    for(i = 5*N/6+1, j = (N>M?M/3+1:M/6+1); j <= 5*M/6; j++)
      h[hn][0] = i, h[hn++][1] = j, hm[i][j] = 1;
    if(N>M){
      for(i = N/6+2, j = M/2+1; i <= 2*N/3+1; i++)
        h[hn][0] = i, h[hn++][1] = j, hm[i][j] = 1;
    }else{
      for(i = N/2+1, j = M/6+2; j <= 2*M/3+1; j++)
        h[hn][0] = i, h[hn++][1] = j, hm[i][j] = 1;
    }
    for(i = 1; i <= N; i++){
      for(j = 1; j <= M; j++){
        c = gc();
        while(c != 'B' && c != 'W')
          c = gc();
        a[i][j] = (c=='B') ? 1 : 0;
        if(a[i][j]){
          b[bn].i = i, b[bn].j = j;
          b[bn].d = 200;
          for(k = 0; k < hn; k++){
            t = abs(i-h[k][0]) + abs(j-h[k][1]);
            if(t < b[bn].d){
              b[bn].d = t;
              b[bn].gi = h[k][0], b[bn].gj = h[k][1];
            }
          }
          bn++;
        }
      }
    }
    for(k = 0; k < bn; k++){
      sort(b+k, bn-k);
      p = b+k;
      // wtf why would removing this help..
      /*if(p->d > C3){
        a[p->i][p->j] = 0;
        r[rn][0] = 3, r[rn][1] = p->i, r[rn++][2] = p->j;
        continue;
      }*/
      s = (p->i < p->gi) ? 1 : -1;
      while(p->i != p->gi)
        move(p, p->i+s, p->j);
      s = (p->j < p->gj) ? 1 : -1;
      while(p->j != p->gj)
        move(p, p->i, p->j+s);
      if(!hm[p->i][p->j]){
        f = 1;
        char df[4] = {1,1,1,1};
        for(s = 1; s <= C2/4+1; s++){
          if(p->i-s >= 1 && a[p->i-s][p->j])
            df[0] = 0;
          if(df[0]){
            // N W
            for(i = p->i-s, j = p->j; j >= 1 && p->j-j < s; i++, j--){
              if(i < 1 || !hm[i][j] || a[i][j])
                continue;
              f2 = 1;
              for(l = j+1; l < p->j; l++){
                if(a[i][l]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = p->i-i, t2 = p->j-j;
                for(l = 0; l < t; l++)
                  move(p, p->i-1, p->j);
                for(l = 0; l < t2; l++)
                  move(p, p->i, p->j-1);
                break;
              }
            }
            if(!f) break;
            // N E
            for(i = p->i-s+1, j = p->j+1; j <= M && j-p->j < s; i++, j++){
              if(i < 1 || !hm[i][j] || a[i][j])
                continue;
              for(l = j-1, f2 = 1; l > p->j; l--){
                if(a[i][l]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = p->i-i, t2 = j-p->j;
                for(l = 0; l < t; l++)
                  move(p, p->i-1, p->j);
                for(l = 0; l < t2; l++)
                  move(p, p->i, p->j+1);
                break;
              }
            }
            if(!f) break;
          }
          if(p->j+s <= M && a[p->i][p->j+s])
            df[1] = 0;
          if(df[1]){
            // E N
            for(i = p->i, j = p->j+s; i >= 1 && p->i-i < s; i--, j--){
              if(j > M || !hm[i][j] || a[i][j])
                continue;
              f2 = 1;
              for(l = i+1; l < p->i; l++){
                if(a[l][j]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = j-p->j, t2 = p->i-i;
                for(l = 0; l < t; l++)
                  move(p, p->i, p->j+1);
                for(l = 0; l < t2; l++)
                  move(p, p->i-1, p->j);
                break;
              }
            }
            if(!f) break;
            // E S
            for(i = p->i+1, j = p->j+s-1; i <= N && i-p->i < s; i++, j--){
              if(j > M || !hm[i][j] || a[i][j])
                continue;
              f2 = 1;
              for(l = i-1; l > p->i; l--){
                if(a[l][j]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = j-p->j, t2 = i-p->i;
                for(l = 0; l < t; l++)
                  move(p, p->i, p->j+1);
                for(l = 0; l < t2; l++)
                  move(p, p->i+1, p->j);
                break;
              }
            }
            if(!f) break;
          }
          if(p->i+s <= N && a[p->i+s][p->j])
            df[2] = 0;
          if(df[2]){
            // S E
            for(i = p->i+s, j = p->j; j <= M && j-p->j < s; i--, j++){
              if(i > N || !hm[i][j] || a[i][j])
                continue;
              f2 = 1;
              for(l = j-1; l > p->j; l--){
                if(a[i][l]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = i-p->i, t2 = j-p->j;
                for(l = 0; l < t; l++)
                  move(p, p->i+1, p->j);
                for(l = 0; l < t2; l++)
                  move(p, p->i, p->j+1);
                break;
              }
            }
            if(!f) break;
            // S W
            for(i = p->i+s-1, j = p->j-1; j >= 1 && p->j-j < s; i--, j--){
              if(i > N || !hm[i][j] || a[i][j])
                continue;
              f2 = 1;
              for(l = j+1; l < p->j; l++){
                if(a[i][l]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = i-p->i, t2 = p->j-j;
                for(l = 0; l < t; l++)
                  move(p, p->i+1, p->j);
                for(l = 0; l < t2; l++)
                  move(p, p->i, p->j-1);
                break;
              }
            }
            if(!f) break;
          }
          if(p->j-s >= 1 && a[p->i][p->j-s])
            df[3] = 0;
          if(df[3]){
            // W S
            for(i = p->i, j = p->j-s; i <= N && i-p->i < s; i++, j++){
              if(j < 1 || !hm[i][j] || a[i][j])
                continue;
              f2 = 1;
              for(l = i-1; l > p->i; l--){
                if(a[l][j]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = p->j-j, t2 = i-p->i;
                for(l = 0; l < t; l++)
                  move(p, p->i, p->j-1);
                for(l = 0; l < t2; l++)
                  move(p, p->i+1, p->j);
                break;
              }
            }
            if(!f) break;
            // W N
            for(i = p->i-1, j = p->j-s+1; i >= 1 && p->i-i < s; i--, j++){
              if(j < 1 || !hm[i][j] || a[i][j])
                continue;
              f2 = 1;
              for(l = i+1; l < p->i; l++){
                if(a[l][j]){
                  f2 = 0;
                  break;
                }
              }
              if(f2){
                f = 0, t = p->j-j, t2 = p->i-i;
                for(l = 0; l < t; l++)
                  move(p, p->i, p->j-1);
                for(l = 0; l < t2; l++)
                  move(p, p->i-1, p->j);
                break;
              }
            }
            if(!f) break;
          }
        }
      }
      a[p->i][p->j] = 2;
      int g[4][2] = {{p->i-1,p->j},{p->i,p->j+1},
              {p->i+1,p->j},{p->i,p->j-1}};
      if(rand()%2){
        g[0][0]++; g[0][1]--; g[1][0]++; g[1][1]--;
        g[2][0]--; g[2][1]++; g[3][0]--; g[3][1]++;
      }
      for(j = 0; j < 4; j++){
        if(g[j][0] < 1 || g[j][0] > N || g[j][1] < 1 || g[j][1] > M)
          continue;
        if(a[g[j][0]][g[j][1]] != 2){
          for(i = k+1; i < bn; i++){
            p = b+i;
            t = abs(p->i-g[j][0]) + abs(p->j-g[j][1]);
            if(t < p->d)
              p->gi = g[j][0], p->gj = g[j][1], p->d = t;
          }
        }
      }
    }
    for(i = 0; i < hn; i++){
      if(!a[h[i][0]][h[i][1]]){
        a[h[i][0]][h[i][1]] = 2;
        r[rn][0] = 2, r[rn][1] = h[i][0], r[rn][2] = h[i][1];
        rn++;
      }
    }
    printf("%d\n",rn);
    for(i = 0; i < rn; i++){
      printf("%d %d %d",r[i][0],r[i][1],r[i][2]);
      if(r[i][0] == 1)
        printf(" %d %d",r[i][3],r[i][4]);
      printf("\n");
    }
  }
  return 0;
}

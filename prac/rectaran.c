// RECTARAN

#include <stdio.h>

#define gc getchar_unlocked
#define MX 1000
#define SKIP 10

int getn(){
  int n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int a){ return (a < 0) ? -a : a; }
int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

void sort(int* a, int n, char (*lt)()){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(lt(*l, p)){ l++; continue; }
    if(lt(p, *r)){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1, lt), sort(l, a+n-l, lt);
}

typedef struct {
  char d,v;
  int x,y,w,h;
} R ;

typedef struct {
  int i,j,x,y,a;
} O ;

typedef struct {
  char o,d;
  int i,t;
} C ;

int p[(MX*(MX-1))>>1], q[MX<<1], cn;
R a[MX];
O o[(MX*(MX-1))>>1];
C c[MX<<1];

char plt(int i, int j){
  return o[i].a > o[j].a;
}

char qlt(int i, int j){
  return c[i].t < c[j].t;
}

char ns(char d){ return !d || d == 2; }
char ew(char d){ return d == 1 || d == 3; }

void cmd(int i, char op, int t, char d){
  c[cn].i = i, c[cn].o = op, c[cn].t = t, c[cn].d = d, q[cn] = cn++;
}

int main(){
  char O[8];
  int T,N, i,j,k,ii, n,t,x,y,z;
  R u,v;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      a[i].x = getn(), a[i].y = getn(), a[i].w = getn(), a[i].h = getn(),
      a[i].d = getn(), a[i].v = 0;

    for(k = i = 0; i < N-1; ++i) for(j = i+1; j < N; ++j, ++k){
      o[k].i = i, o[k].j = j, p[k] = k, u = a[i], v = a[j];
      o[k].x = ((u.x >= v.x && u.x+u.w <= v.x+v.w)
             || (v.x >= u.x && v.x+v.w <= u.x+u.w))
             ? 0 : min(abs(u.x-v.x), abs((u.x+u.w)-(v.x+v.w)));
      o[k].y = ((u.y >= v.y && u.y+u.h <= v.y+v.h)
             || (v.y >= u.y && v.y+v.h <= u.y+u.h))
             ? 0 : min(abs(u.y-v.y), abs((u.y+u.h)-(v.y+v.h)));
      if(o[k].x+o[k].y >= (N<<1) + min(u.w,v.w) + min(u.h,v.h) - 1) o[k].a = 0;
      else if(o[k].x+o[k].y <= (N<<1)) o[k].a = min(u.w,v.w) * min(u.h,v.h);
      else{
        t = x+y-(N<<1);
        if(abs(min(u.w,v.w) - min(u.h,v.h)) >= t)
          o[k].a = (max(min(u.w,v.w), min(u.h,v.h)) - t)
                 * min(min(u.w,v.w), min(u.h,v.h));
        else t -= abs(min(u.w,v.w) - min(u.h,v.h)),
          o[k].a = (min(min(u.w,v.w), min(u.h,v.h))
                   - ((t >> 1) + (t & 1)))
                 * (min(min(u.w,v.w), min(u.h,v.h)) - (t >> 1));
      }
    }
    sort(p, k, plt);

    //! groups

    /* for(cn = ii = 0; ii < k && o[p[ii]].a; ++ii){ */
    /*   i = o[p[ii]].i, j = o[p[ii]].j, x = o[p[ii]].x, y = o[p[ii]].y; */
    /*   if(a[i].v || a[j].v) continue; */
    /*   a[i].v = a[j].v = 1; */

    /*   if(a[i].d == a[j].d){ */
    /*     if(!x && !y) continue; */
    /*     if((!x && ns(a[i].d)) || (!y && ew(a[i].d))) */
    /*       cmd(((!a[i].d && a[i].y > a[j].y) */
    /*         || (a[i].d == 1 && a[i].x > a[j].x) */
    /*         || (a[i].d == 2 && a[i].y < a[j].y) */
    /*         || (a[i].d == 3 && a[i].x < a[j].x)) ? i : j */
    /*         , 'E', N+1-((x ? x : y)>>1)-((x ? x : y)&1), -1); */

    /*     else if((!x && ew(a[i].d)) || (!y && ns(a[i].d))) */
    /*       cmd(i, 'O', N+1-((x ? x : y)>>1)-((x ? x : y)&1) */
    /*         , (a[i].y < a[j].y && ew(a[i].d))  ? 0 */
    /*         : ((a[i].x < a[j].x && ns(a[i].d)) ? 1 */
    /*         : ((a[i].y > a[j].y && ew(a[i].d)) ? 2 : 3))) */
    /*     , cmd(j, 'O', N+1-((x ? x : y)>>1)-((x ? x : y)&1) */
    /*         , (a[j].y < a[i].y && ew(a[j].d))  ? 0 */
    /*         : ((a[j].x < a[i].x && ns(a[j].d)) ? 1 */
    /*         : ((a[j].y > a[i].y && ew(a[j].d)) ? 2 : 3))); */

    /*     else{ */
    /*       if((!a[i].d && a[i].y > a[j].y) */
    /*       || (a[i].d == 1 && a[i].x > a[j].x) */
    /*       || (a[i].d == 2 && a[i].y < a[j].y) */
    /*       || (a[i].d == 3 && a[i].x < a[j].x)) n = i, t = j; */
    /*       else n = j, t = i; */
    /*       cmd(n, 'O', N+1-((x+y)>>1) */
    /*         , (a[n].y < a[t].y && ew(a[n].d))  ? 0 */
    /*         : ((a[n].x < a[t].x && ns(a[n].d)) ? 1 */
    /*         : ((a[n].y > a[t].y && ew(a[n].d)) ? 2 : 3))); */

    /*       if(x == y) continue; */
    /*       if((ns(a[n].d) && x > y) || (ew(a[n].d) && y > x)) */
    /*         z = n, n = t, t = z; */
    /*       cmd(n, 'O', N+1-((x+y)>>1)+min(x,y) */
    /*         , (y > x && (a[n].d == 2 || (ew(a[n].d) && a[n].y < a[t].y)))  ? 0 */
    /*         : ((x > y && (a[n].d == 3 || (ns(a[n].d) && a[n].x < a[t].x))) ? 1 */
    /*         : ((y > x && (a[n].d == 0 || (ew(a[n].d) && a[n].y > a[t].y))) ? 2 */
    /*         : 3))); */
    /*     } */

    /*   }else if(a[i].d == a[j].d+2 || a[i].d+2 == a[j].d){ */

    /*   }else{ */

    /*   } */
    /* } */
    /* sort(q, cn, qlt); */

    for(i = 0; i < N; ++i){
      scanf("%s", O);
      /* if(O[1] == 'E') */
      /* else */
    }
  }
  return 0;
}

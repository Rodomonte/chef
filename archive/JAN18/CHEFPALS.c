// CHEFPALS

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int n){ return (n < 0) ? -n : n; }

typedef struct { int i,l,b; } P ;
char lt(P a, P b){ return a.l/(a.b+1) < b.l/(b.b+1); }
void sort(P* a, int n){
  if(n < 2) return;
  P p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(lt(*l, p)){ l++; continue; }
    if(lt(p, *r)){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

void cc(char* q, int* l, int n, char s){
  char b[5];
  int i;
  if(!n) return;
  sprintf(b, "%d\0", n);
  if(s) for(i = strlen(b)-1; i >= 0; --i, --(*l)) q[*l] = b[i];
  else for(i = 0; i < strlen(b); ++i, ++(*l)) q[*l] = b[i];
}

char c[1001][1001];
int r[1000];
P a[1000];
int main(){
  char f,s, m[102], q[102];
  int N, i,j,k,l, n,t,x,y;

  N = getn();
  for(i = 0; i < N; ++i) a[i].l = getn(), a[i].i = i;
  for(i = 0; i < N; ++i){
    a[i].b = getn(), c[i][a[i].l] = 0, r[i] = -1;
    for(j = 0; j < a[i].l; ++j) c[i][j] = 'w';
  }

  //! Avoid zeros
  sort(a, N), x = m[0] = s = 0, y = N-1;
  for(i = 0; i < N; ++i){
    if(s){ // Match suffix to left side
      k = a[i].l - 1, l = 100;
      if(strlen(m)){
        for(j = 0; j < strlen(m); ++j){
          for(t = k, n = 0; k >= 0 && k > t-(m[j]-'0'); --k, ++n)
            c[a[i].i][k] = 'w';
          if(!a[i].b || k < 0){
            for(; k >= 0; --k, ++n) c[a[i].i][k] = 'w';
            cc(q, &l, n, s);
            break;
          }
          cc(q, &l, n, s);
          c[a[i].i][k--] = 'b', --a[i].b;
        }

        if(100-l < strlen(m)){
          for(k = 0; a[i].b; ++k){
            if(c[a[i].i][k] == 'w'){
              c[a[i].i][k] = 'b', --a[i].b;
              if(l < 100){
                if(q[l+1] > '0') --q[l+1]; //! Doesn't handle > 1 digit?
                else ++l;
              }
            }else if(k && c[a[i].i][k-1] == 'w') ++l;
          }
          while(l < 100 && q[l+1] == '0') ++l;
          for(j = 0, ++l; l < 101; ++j, ++l) m[j] = m[l];
          while(j > 0 && m[j-1] == '0') --j;
          m[j] = 0, r[y--] = a[i].i;
          continue;
        }
      }

      for(n = 0, l = 100; k >= 0; --k, ++n){
        if(c[a[i].i][k] == 'b' || (n == 9 && a[i].b)){
          if(c[a[i].i][k] != 'b') --a[i].b, c[a[i].i][k] = 'b';
          cc(m, &l, n, s), n = -1;
        }else c[a[i].i][k] = 'w';
      }
      f = n ? 0 : 1;
      for(k = 0; a[i].b; ++k){
        if(c[a[i].i][k] == 'w'){
          c[a[i].i][k] = 'b', --a[i].b;
          if(f && l < 100){
            if(m[l+1] > '0') --m[l+1]; //! Doesn't handle > 1 digit?
            else ++l;
          }else if(n) --n;
        }else{
          if(f && k && c[a[i].i][k-1] == 'w') ++l;
          n = 0, f = 1;
        }
      }
      while(l < 100 && m[l+1] == '0') ++l;
      cc(m, &l, n, s);
      for(j = 0, ++l; l < 101; ++j, ++l) m[j] = m[l];
      m[j] = 0, r[y--] = a[i].i, s = 1 - s;

    }else{ // Match prefix to right side
      k = l = 0;
      if(strlen(m)){
        for(j = strlen(m)-1; j >= 0; --j){
          for(t = k, n = 0; k < a[i].l && k < t+(m[j]-'0'); ++k, ++n)
            c[a[i].i][k] = 'w';
          if(!a[i].b || k >= a[i].l){
            for(; k < a[i].l; ++k, ++n) c[a[i].i][k] = 'w';
            cc(q, &l, n, s);
            break;
          }
          cc(q, &l, n, s);
          c[a[i].i][k++] = 'b', --a[i].b;
        }

        if(l < strlen(m)){
          for(k = a[i].l-1; a[i].b; --k){
            if(c[a[i].i][k] == 'w'){
              c[a[i].i][k] = 'b', --a[i].b;
              if(l > 0){
                if(q[l-1] > '0') --q[l-1];
                else --l;
              }
            }else if(k < a[i].l-1 && c[a[i].i][k+1] == 'w') --l;
          }
          while(l > 0 && q[l-1] == '0') --l;
          m[(j=strlen(m)-l)] = 0, r[x++] = a[i].i;
          while(j > 0 && m[j-1] == '0') --j;
          continue;
        }
      }

      for(n = l = 0; k < a[i].l; ++k, ++n){
        if(c[a[i].i][k] == 'b' || (n == 9 && a[i].b)){
          if(c[a[i].i][k] != 'b') --a[i].b, c[a[i].i][k] = 'b';
          cc(m, &l, n, s), n = -1;
        }else c[a[i].i][k] = 'w';
      }
      f = n ? 0 : 1;
      for(k = a[i].l-1; a[i].b; --k){
        if(c[a[i].i][k] == 'w'){
          c[a[i].i][k] = 'b', --a[i].b;
          if(f && l > 0){
            if(m[l-1] > '0') --m[l-1];
            else --l;
          }else if(n) --n;
        }else{
          if(f && k < a[i].l-1 && c[a[i].i][k+1] == 'w') --l;
          n = 0, f = 1;
        }
      }
      while(l > 0 && m[l-1] == '0') --l;
      cc(m, &l, n, s);
      m[l] = 0, r[x++] = a[i].i, s = 1 - s;
    }
  }

  for(i = 0; i < N; ++i) printf("%s\n", c[i]);
  for(i = 0; i < N; ++i) printf("%d ", r[i]+1);
  printf("\n");
  return 0;
}

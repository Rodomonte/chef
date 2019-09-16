// TWSTR

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

struct R {
  char n[1001];
  int p;
  struct R *r;
};
int main(){
  int N = getn(),Q, i,l;
  struct R *a[27], b[1000], *c,*p;
  char s[1001], k,f,*n;
  for(i = 0; i < 27; i++)
    a[i] = NULL;
  while(N--){
    scanf("%s ",b[N].n);
    b[N].p = getn();
    k = (b[N].n)[0] - 'a';
    p = NULL;
    if(k < 0)
      k = 26;
    c = a[k];
    while(c){
      if(b[N].p > c->p)
        break;
      p = c;
      c = c->r;
    }
    b[N].r = c;
    if(p)
      p->r = &b[N];
    else
      a[k] = &b[N];
  }
  Q = getn();
  while(Q--){
    scanf("%s",s);
    i = *s - 'a';
    if(i < 0)
      i = 26;
    c = a[i];
    while(c){
      f = 0, l = 0;
      n = c->n;
      while(s[l]){
        if(n == '\0')
          break;
        if(s[l] != n[l])
          break;
        l++;
      }
      if(s[l] == '\0'){
        f = 1;
        break;
      }
      c = c->r;
    }
    printf("%s\n",f?n:"NO");
  }
  return 0;
}

// KNPSK

#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

char pb[20];
inline void putll(ll n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

void rsort(int* a, int n){
  if(n < 2) return;
  int p = a[n/2], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l > p){ l++; continue; }
    if(*r < p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  rsort(a, r-a+1);
  rsort(l, a+n-l);
}

int c1[100000],n1;
int c2[100000],n2;
int main(){
  int N,M,W, i, p1,p2;
  ll r, t1,t2;
  N = getn(), r = M = n1 = n2 = p1 = p2 = 0;
  for(i = 0; i < N; i++){
    M += (W = getn());
    if(W == 1)
      c1[n1++] = getn();
    else
      c2[n2++] = getn();
  }
  rsort(c1, n1);
  rsort(c2, n2);
  for(i = 1; i <= M; i++){
    t1 = t2 = r;
    if(n1-p1){
      t1 += c1[p1];
    }
    if(n2-p2 && i-(p1+p2*2) >= 2){
      t2 += c2[p2];
    }else if(n2-p2 && p1){
      t2 -= c1[p1-1];
      t2 += c2[p2];
    }
    if(n1-p1 && t1 > t2){
      p1++;
      r = t1;
    }
    if(n2-p2 && i-(p1+p2*2) >= 2 && t2 >= t1){
      p2++;
      r = t2;
    }else if(n2-p2 && p1 && t2 >= t1){
      p1--;
      p2++;
      r = t2;
    }
    putll(r); pc(' ');
  }
  pc('\n');
  return 0;
}

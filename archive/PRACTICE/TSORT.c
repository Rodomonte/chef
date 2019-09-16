// TSORT

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n=0, c=gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define pc putchar_unlocked
inline void putn(int n){
  if(!n) pc('0');
  char pb[10];
  int pi = 0;
  while(n) pb[pi++] = (n) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

void quickSort(int* a, int n){
  if(n < 2) return;
  int p = a[n/2], *l = a, *r = a+n-1;
  while(l <= r){
    if(*l < p){
      l++;
      continue;
    }
    if(*r > p){
      r--;
      continue;
    }
    int t = *l;
    *l++ = *r;
    *r-- = t;
  }
  quickSort(a, r-a+1);
  quickSort(l, a+n-l);
}

int a[1000000];
int main(){
  int N, i;
    N = getn();
    for(i = 0; i < N; i++)
    a[i] = getn();
    quickSort(a, N);
    for(i = 0; i < N; i++){
    putn(a[i]);
    pc('\n');
    }
    return 0;
}

// ARRGAME2

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n/2], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int a[100000],b[100000],c[100000];
int main(){
  int T,N, i,j, c1,c2;
  double r;
  T = getn();
  while(T--){
    N = getn(), c1 = c2 = 0, r = 0;
    for(i = 0; i < N; i++)
      a[i] = getn(), c[i] = 0;
    for(i = 0; i < N; i++)
      b[i] = getn();
    sort(a, N);
    sort(b, N);
    for(j = 0; j < N && b[j] < 5; j++){
      if(b[j] == 1) c1++;
      else if(b[j] == 2) c2++;
    }
    for(i = 0; i < N && a[i] == 1; i++)
      c[i] = 0;
    for(j = i; j < N; j++)
      c[j] = c1;
    for(j = 0; j < N && b[j] < 5; j++);
    for(i = 0; i < N && a[i] < 2; i++);
    for(; i < N && a[i] == 2; i++)
      c[i] += N - j;
    for(; i < N && a[i] == 3; i++)
      c[i] += c2;
    for(i = 0; i < N && a[i] < 3; i++);
    for(j = 0; i < N; i++){
      while(j < N && b[j] <= a[i])
        j++;
      c[i] += N - j;
    }
    for(i = 0; i < N; i++)
      r += (double)c[i] / (double)N;
    printf("%.8f\n",r);
  }
  return 0;
}

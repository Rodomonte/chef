// STREGGS

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MAX 1000000000
void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}
void quickSort(int* a, int l, int r){
  int c,p,i,j;
  if(l + 10 <= r){
    c = (l + r) / 2;
    if(a[c] < a[l])
      swap(a+l, a+c);
    if(a[r] < a[l])
      swap(a+r, a+l);
    if(a[r] < a[c])
      swap(a+r, a+c);
    swap(a+c, a+r-1);
    p = a[r-1], i = l, j = r - 1;
    while(1){
      while(a[++i] < p);
      while(p < a[--j]);
      if(i < j)
        swap(a+i, a+j);
      else
        break;
    }
    swap(a+i, a+r-1);
    quickSort(a, l, i-1);
    quickSort(a, i+1, r);
  }else{
    for(i = l + 1; i <= r; i++){
      p = a[i];
      for(j = i; j > l && p < a[j-1]; j--)
        a[j] = a[j-1];
      a[j] = p;
    }
  }
}
int min(int a, int b){
  return a < b ? a : b;
}
int main(){
  int T = getn(),N,K, i,j, a[501],b[501], r,s,t;
  while(T--){
    N = getn(), K = getn(), r = MAX, s = a[0] = b[0] = 0;
    for(i = 1; i < N+1; ++i)
      a[i] = getn();
    quickSort(a, 1, N);
    for(i = 0; i < K+1; ++i){
      t = a[i];
      for(j = i; j < N+1; ++j){
        a[j] -= t;
        if(j)
          b[j] = b[j-1] + a[j];
        s += t;
      }
      t = MAX;
      for(j = N; j >= K; --j)
        t = min(t, (N - j) * a[j] + b[j] - b[j - (K - i)]);
      r = min(r, s + t);
    }
    printf("%d\n",r);
  }
  return 0;
}

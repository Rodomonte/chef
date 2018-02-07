// LELEMON

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

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
int main(){
  int T,N,M,C,V[100], i,j, a[100], r,t;
  T = getn();
  while(T--){
    N = getn(), M = getn(), r = 0;
    for(i = 0; i < N; i++)
      a[i] = 0;
    for(i = 0; i < M; i++)
      a[getn()]++;
    for(i = 0; i < N; i++){
      C = getn();
      if(a[i]){
        for(j = 0; j < C; j++)
          V[j] = getn();
        quickSort(V, 0, C-1);
        t = a[i] < C ? C-a[i] : 0;
        for(j = C-1; j >= t; j--)
          r += V[j];
      }else
        for(j = 0; j < C; j++)
          getn();
    }
    printf("%d\n",r);
  }
  return 0;
}

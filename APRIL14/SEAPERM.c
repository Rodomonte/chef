// SEAPERM

#include <stdio.h>
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[2001], p[2001];
void swap(int i, int j){
  int t;
  t = a[i], a[i] = a[j], a[j] = t;
  t = p[i], p[i] = p[j], p[j] = t;
}
int main(){
  char f;
  int T,N,K,S, i,j,k,s,m,mi;
  T = getn();
  while(T--){
    N = getn(), K = getn(), S = getn();
    for(i = 1; i <= N; i++)
      a[i] = getn(), p[i] = i;
    for(i = 1; i <= N-1;){
      s = a[i];
      //printf("a[i]=%d:\n",a[i]);
      while(1){
        m = 0;
        for(k = i+1; k <= N; k++)
          if(s + a[k] <= S && a[k] > m)
            m = a[k], mi = k;
        i++;
        if(m){
          swap(i, mi);
          //printf("  %d<->%d\n",a[mi],a[i]);
          s += m;
        }else
          break;
      }
    }
    for(i = 1; i <= N; i++)
      printf("%d ",p[i]);
    printf("\n");
  }
  return 0;
}

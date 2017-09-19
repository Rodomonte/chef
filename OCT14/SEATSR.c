// SEATSR

#include <stdio.h>
#include <string.h>

#define END 223223

int abs(int n){
  return (n < 0) ? 0-n : n;
}
int min(int a, int b){
  return (a < b) ? a : b;
}

char a[100002], b[100002];
int c[100001], p[100001];
int main(){
  int T,A,B,K, an,bn,i,j,n,i0,i1;
  scanf("%d", &T);
  while(T--){
    scanf("%s%s%d%d%d", a+1, b+1, &A, &B, &K);
    an = strlen(a+1), bn = strlen(b+1);
    if(!A){
      printf("0\n");
      continue;
    }
    if(abs(an-bn)*A > K){
      printf("-1\n");
      continue;
    }
    if(!B){
      printf("%d\n", abs(an-bn)*A);
      continue;
    }

    for(n = i = 0; i <= an && n <= K; i++)
      p[i] = n, c[i] = END, n += A;
    for(i1 = i; i <= an; i++)
      p[i] = c[i] = END;
    for(i0 = j = 1; j <= bn && i0 <= i1; j++){
      c[0] = (j*A > K) ? END : j*A;
      for(i = i0; i <= i1; i++){
        if(a[i] == b[j] && p[i-1] != END)
          c[i] = p[i-1];
        else
          c[i] = min(min(p[i]+A, c[i-1]+A), p[i-1]+B);
        c[i] = (c[i] > K) ? END : c[i];
      }
      for(i = i0-1; i <= i1; i++)
        p[i] = c[i];
      while(p[i0] == END && i0 < an)
        i0++;
      while(p[i1] != END && i1 < an)
        i1++;
    }

    if(c[an] > K)
      printf("-1\n");
    else
      printf("%d\n", c[an]);
  }
  return 0;
}
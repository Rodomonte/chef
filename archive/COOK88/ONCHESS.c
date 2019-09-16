//

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char u[100];
int a[100][6];
int main(){
  char s[16];
  int T,N, i,j,k;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i){
      a[i][0] = getn(), a[i][1] = getn(), a[i][2] = getn(), a[i][3] = getn();
      scanf("%s", s), a[i][4] = (s[0] == 'r') ? 1 : 0;
      scanf("%s", s), a[i][5] = (s[0] == 'r') ? 0 : ((s[0] == 'w') ? 1 : 2);
      u[i] = 0;
    }

    for(i = 0; i < N; ++i){
      k = -1;
      for(j = 0; j < i; ++j){
        if(u[j]) continue;
        if(a[i][0] >= a[j][1] && a[i][0] <= a[j][2] && a[j][0] >= a[i][1] &&
           a[j][0] <= a[i][2] && a[i][4] == a[j][4] && a[i][3] == a[j][3] &&
           ((a[i][5] == 0 && a[j][5] == 0) || (a[i][5] == 1 && a[j][5] == 2) ||
            (a[i][5] == 2 && a[j][5] == 1))){ k = j, u[k] = u[i] = 1; break; }
      }
      if(k == -1) printf("wait\n");
      else printf("%d\n", k+1);
    }
  }
  return 0;
}

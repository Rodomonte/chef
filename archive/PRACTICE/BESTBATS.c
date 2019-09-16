// BESTBATS

#include <stdio.h>

int main(){
  int T, K, c[12][12],i,j, sc[11], v;
  for(i = 0; i < 12; i++)
    for(j = 0; j < 12; j++){
      if(i < j) c[i][j] = 0;
      else if(i == 0 || j == 0 || i == j) c[i][j] = 1;
      else c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
  scanf("%d",&T);
  while(T--){
    int n=0, m=1;
    for(i = 0; i < 11; i++){
      scanf("%d",sc+i);
      j = i - 1;
      v = sc[i];
      while(j >= 0 && sc[j] < v){
        sc[j+1] = sc[j];
        j--;
      }
      sc[j+1] = v;
    }
    scanf("%d",&K);
    i = K - 2;
    while(i >= 0 && sc[i] == sc[i+1]){
      m++;
      i--;
    }
    i = K;
    while(i < 11 && sc[i] == sc[i-1]){
      n++;
      i++;
    }
    n += m;
    printf("%d\n",c[n][m]);
  }
  return 0;
}

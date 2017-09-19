// WSTRING

#include <stdio.h>

#define gc getchar_unlocked
int main(){
  char c;
  int T, i,j,k, a[10001][26],*b[4],p1[26],p4[26], p,r,s,t;
  scanf("%d\n",&T);
  while(T--){
    p = r = 0;
    for(i = 0; i < 26; i++)
      a[0][i] = 0;
    while((c = gc()) != '\n'){
      if(c == '#'){
        p++;
        for(i = 0; i < 26; i++)
          a[p][i] = 0;
      }else
        a[p][c-97]++;
    }
    for(i = 0; i < 26; i++)
      p1[i] = a[0][i], p4[i] = 0;
    for(i = 3; i <= p; i++)
      for(j = 0; j < 26; j++)
        p4[j] += a[i][j];
    b[0] = p1, b[1] = a[1], b[2] = a[2], b[3] = p4;
    for(i = 0; i < p-2; i++){
      s = 0;
      for(j = 0; j < 4; j++){
        t = 0;
        for(k = 0; k < 26; k++)
          if(b[j][k] > t)
            t = b[j][k];
        if(t == 0){
          s = 0;
          break;
        }
        s += t;
      }
      if(s > r)
        r = s;
      if(i == p-3)
        break;
      for(j = 0; j < 26; j++)
        p1[j] += b[1][j];
      b[1] = b[2];
      b[2] = a[i+3];
      for(j = 0; j < 26; j++)
        p4[j] -= b[2][j];
    }
    if(r > 0)
      r += 3;
    printf("%d\n",r);
  }
  return 0;
}

// DEVCLASS

#include <stdio.h>
#include <string.h>

int min(int a, int b){
  return (a < b) ? a : b;
}

char s[100001], a[100001];

int eval(char c, int N, int O){
  int i,j,k,r,u,v;
  r = 0;
  if(O){
    memset(a, 0, 100001);
    j = k = 1, u = v = 0;
    for(i = 0; i < N; ++i){
      while(j < N && (j <= i || s[j] != 'B' || a[j])){
        if(a[j])
          ++u;
        ++j;
      }
      while(k < N && (k <= i || s[k] != 'G' || a[k])){
        if(a[k])
          ++v;
        ++k;
      }
      if(a[i]){
        --u, --v;
        continue;
      }
      if(s[i] == c){
        c = (c == 'B') ? 'G' : 'B';
        continue;
      }
      if(c == 'B'){
        a[j] = 1, r += j-i-u;
        if(j < k)
          ++v;
      }else{
        a[k] = 1, r += k-i-v;
        if(k < j)
          ++u;
      }
    }
  }else{
    for(i = 0; i < N; ++i){
      a[i] = (s[i] == c) ? 0 : c;
      c = (c == 'B') ? 'G' : 'B';
    }
    j = k = 1;
    for(i = 0; i < N; ++i){
      if(!a[i])
        continue;
      while(j < N && (j <= i || a[j] != 'B'))
        ++j;
      while(k < N && (k <= i || a[k] != 'G'))
        ++k;
      if(s[i] == 'B')
        a[i] = a[j] = 0;
      else
        a[i] = a[k] = 0;
      ++r;
    }
  }
  return r;
}

int main(){
  char c;
  int T,O,N, i,j,b,g,r;
  scanf("%d", &T);
  while(T--){
    scanf("%d\n%s", &O, s);
    N = strlen(s), b = g = 0;
    for(i = 0; i < N; ++i){
      if(s[i] == 'B')
        ++b;
      else
        ++g;
    }
    if(b-g > 1 || b-g < -1){
      printf("-1\n");
      continue;
    }
    r = 2000000000;
    if(b-g >= 0)
      r = min(r, eval('B', N, O));
    if(b-g <= 0)
      r = min(r, eval('G', N, O));
    printf("%d\n", r);
  }
  return 0;
}

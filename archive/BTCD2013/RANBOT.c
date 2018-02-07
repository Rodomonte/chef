// RANBOT

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char s[6];
  int N,A,B, i, a[1000][2], n,x,y;
  N = getn(), n = 0;
  while(N--){
    scanf("%s",s);
    A = getn(), B = getn();
    if(s[0] == 'a'){
      a[n][0] = A, a[n++][1] = B;
    }else if(s[0] == 'e'){
      for(i = 0; i < n; i++)
        if(a[i][0] == A && a[i][1] == B){
          a[i][0] = a[i][1] = -1;
          break;
        }
    }else{
        x = y = 100001;
      for(i = 0; i < n; i++)
        if((a[i][0] > A && a[i][1] > B) && (a[i][0] < x ||
            (a[i][0] == x && a[i][1] < y)))
          x = a[i][0], y = a[i][1];
      if(x == 100001)
        printf("-1\n");
      else
        printf("%d %d\n",x,y);
    }
  }
  return 0;
}

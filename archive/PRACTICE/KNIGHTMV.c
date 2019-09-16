// KNIGHTMV

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), r,c;
  char s[11];
  while(T--){
    gets(s);
    if(s[5] != '\0' || s[2] != '-' || s[0] < 'a' || s[0] > 'h' || s[1] < '1' ||
      s[1] > '8' || s[3] < 'a' || s[3] > 'h' || s[4] < '1' || s[4] > '8')
        printf("Error\n");
    else{
      r = s[0] - s[3], c = s[1] - s[4];
      if(((r==1 || r==-1) && (c==2 || c==-2))
        || ((r==2 || r==-2) && (c==1 || c==-1)))
          printf("Yes\n");
      else printf("No\n");
    }
  }
  return 0;
}

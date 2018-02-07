// POTATOES

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
  char s[2004] = {0};
  int T, i,j;
  for(i = 2; i <= 2003; i++){
    if(s[i])
      continue;
    for(j = i+i; j <= 2003; j += i)
      s[j] = 1;
  }
  T = getn();
  while(T--){
    i = getn() + getn();
    j = i + 1;
    while(s[j])
      j++;
    printf("%d\n",j-i);
  }
  return 0;
}

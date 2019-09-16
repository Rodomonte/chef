// CHEFDIL

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char a[100001];
int main(){
  int T, i,n;

  T = getn();
  while(T--){
    scanf("%s", a);

    for(i = 0; a[i]; ++i)
      if(a[i] == '1'){
        a[i] = -1;
        if(a[i+1] == '0') a[i+1] = '1';
        else if(a[i+1] == '1') a[i+1] = '0';
        if(a[i-1] == '0') a[i-1] = '1', i -= 2;
      }

    for(n = i = 0; a[i]; ++i)
      if(a[i] == '0') ++n;
    printf(n ? "LOSE\n" : "WIN\n");
  }
  return 0;
}

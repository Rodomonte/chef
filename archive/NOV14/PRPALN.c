// PRPALN

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

char a[100001];
int main(){
  char r;
  int T, n,i,j;
  scanf("%d\n", &T);
  while(T--){
    scanf("%s", a);
    n = strlen(a);
    // Is already palindrome? abcba abba
    i = (n>>1)-1, j = (n+1)>>1, r = 1;
    for(; i >= 0; --i, ++j){
      if(a[i] != a[j]){
        r = 0;
        break;
      }
    }
    if(r || n == 2){
      printf("YES\n");
      continue;
    }
    if(n&1){
      // Odd, remove from right side abbca
      i = (n>>1)-1, j = n>>1, r = 1;
      for(; i >= 0; --i, ++j){
        if(a[i] != a[j]){
          if(r){
            ++i, r = 0;
          }else{
            r = -1;
            break;
          }
        }
      }
      if(r != -1){
        printf("YES\n");
        continue;
      }
      // Odd, remove from left side acbba
      i = (n>>1), j = (n>>1)+1, r = 1;
      for(; j < n; --i, ++j){
        if(a[i] != a[j]){
          if(r){
            --j, r = 0;
          }else{
            r = -1;
            break;
          }
        }
      }
      if(r != -1){
        printf("YES\n");
        continue;
      }
    }else{
      // Even, remove from right side abca
      i = (n>>1)-2, j = (n>>1), r = 1;
      for(; i >= 0; --i, ++j){
        if(a[i] != a[j]){
          if(r){
            ++i, r = 0;
          }else{
            r = -1;
            break;
          }
        }
      }
      if(r != -1){
        printf("YES\n");
        continue;
      }
      // Even, remove from left side acba
      i = (n>>1)-1, j = (n>>1)+1, r = 1;
      for(; j < n; --i, ++j){
        if(a[i] != a[j]){
          if(r){
            --j, r = 0;
          }else{
            r = -1;
            break;
          }
        }
      }
      if(r != -1){
        printf("YES\n");
        continue;
      }
    }
    printf("NO\n");
  }
  return 0;
}

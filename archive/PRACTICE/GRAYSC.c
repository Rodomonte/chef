// GRAYSC

#include <stdio.h>

#define gc getchar_unlocked
#define llu unsigned long long
inline llu getn(){
  int c = gc();
  llu n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int N = getn(), i,j,k,l;
  if(N >= 68){
    printf("Yes\n");
    return 0;
  }
  llu a[67];
  for(i = 0; i < N; i++)
    a[i] = getn();
  for(i = 0; i < N-3; i++)
    for(j = i+1; j < N-2; j++)
      for(k = j+1; k < N-1; k++)
        for(l = k+1; l < N; l++)
          if(!(a[i]^a[j]^a[k]^a[l])){
            printf("Yes\n");
            return 0;
          }
  printf("No\n");
  return 0;
}

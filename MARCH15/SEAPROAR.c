// SEAPROAR

#include <stdio.h>
#include <string.h>

#define uint unsigned int
#define gc getchar_unlocked

void gen(uint s, char* a, int N){
  int i;
  for(i = 0; i < N; ++i){
    s = s * 1103515245 + 12345;
    a[i] = (((s / 65536) % 32768) & 1) ? '1' : '0';
  }
  a[N] = 0;
}

char a[200001];
int main(){
  char b[201], f;
  int T,N;
  uint s;
  scanf("%d", &T);
  while(T--){
    scanf("%s", a);
    N = strlen(a), f = 0;
    if(N > 100)
      N = 100;
    a[N] = 0;
    for(s = 0; s <= 132000; ++s){
      gen(s, b, N);
      if(!strcmp(a, b)){
        f = 1;
        break;
      }
    }
    printf(f ? "LCG\n" : "Xorshift\n");
  }
  return 0;
}

// CHEFHPAL

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,A, i;

  T = getn();
  while(T--){
    N = getn(), A = getn();

    if(N == 1) printf("1 a\n");
    else if(A == 1){ printf("%d ", N); for(i = 0; i < N; ++i) printf("a");
      printf("\n");
    }else if(A == 2){
      if(N == 2) printf("1 ab\n");
      else if(N == 3) printf("2 aab\n");
      else if(N == 4) printf("2 aabb\n");
      else if(N == 5) printf("3 aaabb\n");
      else if(N == 6) printf("3 aaabbb\n");
      else if(N == 7) printf("3 aaababb\n");
      else if(N == 8) printf("3 aaababbb\n");
      else{ printf("4 "); for(i = 0; i < N-5; i += 6) printf("aababb");
        if(i++ < N) printf("a"); if(i++ < N) printf("a");
        if(i++ < N) printf("b"); if(i++ < N) printf("a");
        if(i++ < N) printf("b"); printf("\n");
      }
    }else{ printf("1 "); for(i = 0; i < N-2; i += 3) printf("abc");
      if(i++ < N) printf("a"); if(i++ < N) printf("b");
      if(i++ < N) printf("c"); printf("\n");
    }
  }
  return 0;
}

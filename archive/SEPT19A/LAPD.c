// LAPD

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b){ return ((a += b) >= MOD) ? a-MOD : a; }
int mmul(int a, int b){ return (int)((ll)a * b % MOD); }

int main(){
  int T,A,B,C, a,b,c,r;

  T = getn();
  while(T--){
    A = getn(), B = getn(), C = getn();

    for(r = 0, b = 1; b <= B; ++b){
      for(a = 2, c = b*b+1; a <= A && a <= c; ++a, c = (b*b)/(a-1)+1)
        if(c < C) r = madd(r, C-c);
      for(c = 2, a = b*b+1; c <= C && c <= a; ++c, a = (b*b)/(c-1)+1)
        if(a < A) r = madd(r, A-a);
      if(b < A-1 && b < C-1) r = madd(r, mmul(A-b-1, C-b-1));
    }

    printf("%d\n", r);
  }
  return 0;
}

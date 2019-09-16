// SEBICPU

#include <stdio.h>

#define ull unsigned long long
#define gc getchar_unlocked

ull getn(){
  ull n = 0; char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

typedef struct {
  char c[4];
  int i,j;
} C;

int p;
ull a[64][3], r[4];
C c[64*500];

void set(int i, char* _c, int _i, int _j){
  int k;
  for(k = 0; k < 4; ++k)
    c[i].c[k] = _c[k];
  c[i].i = _i, c[i].j = _j;
}

void inc(int i){ ++r[i], set(p++, "inc", i, -1); }
void dec(int i){ --r[i], set(p++, "dec", i, -1); }
void mov(int i, int j){ r[i] = r[j], set(p++, "mov", i, j); }
void or(int i, int j){ r[i] |= r[j], set(p++, "or", i, j); }
void shl(int i, int j){ r[i] <<= r[j], set(p++, "shl", i, j); }

int main(){
  int N, i,j,k;

  N = getn();
  for(i = 0; i < N; ++i)
    a[i][0] = getn(), a[i][1] = getn(), a[i][2] = getn();

  p = 0, inc(3);
  for(i = 0; i < N; ++i){
    for(j = 0; j < 3; ++j){
      if(!a[i][j]) continue;
      for(k = 63; !(a[i][j] & (1LLU << k)); --k);
      while(r[j] != a[i][j]){
        if(r[j]) shl(j, 3);
        if(a[i][j] & (1LLU << k)) or(j, 3);
        --k;
      }
    }
    if(i < N-1) dec(3), mov(0, 3), mov(1, 3), mov(2, 3), inc(3);
  }

  printf("%d\n", p);
  for(i = 0; i < p; ++i){
    printf("%s r%cx", c[i].c, 'a'+c[i].i);
    if(c[i].j != -1)
      printf(" r%cx", 'a'+c[i].j);
    printf("\n");
  }
  return 0;
}

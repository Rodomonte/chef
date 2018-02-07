// STRQ

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

// 0 1 2 3 4  5  6  7  8  9  10 11 12 13 14 15
// c h e f ch ce cf hc he hf ec eh ef fc fh fe
ll a[1000001][16]={{0}};
int main(){
  char A,B, c;
  int Q,L,R, i,j,l,r;
  i = 1;
  while((c = gc()) != '\n'){
    for(j = 0; j < 16; ++j)
      a[i][j] = a[i-1][j];
    if(c == 'c')
      ++a[i][0], a[i][7] += a[i][1], a[i][10] += a[i][2], a[i][13] += a[i][3];
    else if(c == 'h')
      ++a[i][1], a[i][4] += a[i][0], a[i][11] += a[i][2], a[i][14] += a[i][3];
    else if(c == 'e')
      ++a[i][2], a[i][5] += a[i][0], a[i][8] += a[i][1], a[i][15] += a[i][3];
    else
      ++a[i][3], a[i][6] += a[i][0], a[i][9] += a[i][1], a[i][12] += a[i][2];
    ++i;
  }
  Q = getn();
  while(Q--){
    A = gc(), gc(), B = gc(), L = getn(), R = getn();
    if(A == 'c'){
      l = 0;
      if(B == 'h') j = 4;
      else if(B == 'e') j = 5;
      else j = 6;
    }else if(A == 'h'){
      l = 1;
      if(B == 'c') j = 7;
      else if(B == 'e') j = 8;
      else j = 9;
    }else if(A == 'e'){
      l = 2;
      if(B == 'c') j = 10;
      else if(B == 'h') j = 11;
      else j = 12;
    }else{
      l = 3;
      if(B == 'c') j = 13;
      else if(B == 'h') j = 14;
      else j = 15;
    }
    if(B == 'c') r = 0;
    else if(B == 'h') r = 1;
    else if(B == 'e') r = 2;
    else r = 3;
    printf("%lld\n", a[R][j]-a[L-1][j]-(a[R][r]-a[L-1][r])*a[L-1][l]);
  }
  return 0;
}

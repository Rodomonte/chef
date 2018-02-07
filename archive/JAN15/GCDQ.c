// GCDQ

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}

int a[200000],an, li[20],ln;

void build(){
  int i,j,n;
  li[0] = 0, n = an, ln = 1;
  while(n > 1){ // 0 ?
    li[ln] = li[ln-1] + n;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++)
      a[j] = gcd(a[i], a[i+1]);
    n >>= 1, ln++;
  }
  an = j;
}

int query(int i0, int i1){
  int i,j,l,e,ia,ib,r;
  r = a[i0], ++i0;
  l = 0, e = 1, i = i0;
  while(i0 <= i1){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (i0 >> l+1);
      ia = (j - li[l+1]) << (l+1);
      ib = ia + (e << 1) - 1;
      if(ia == i0 && ib <= i1){
        i = j, e <<= 1, l++;
        continue;
      }
    }
    ia = (i - li[l]) << l;
    if(ia == i0){
      r = gcd(r, a[i]);
      i0 += e;
      if(i0 > i1)
        break;
    }
    if(i1 - i0 + 1 < e){
      e >>= 1, l--;
      i = li[l] + (ia >> l) + 1;
    }else{
      i++;
    }
  }
  return r;
}

int main(){
  int T,N,Q,L,R, i;
  T = getn();
  while(T--){
    N = an = getn(), Q = getn();
    for(i = 0; i < N; ++i)
      a[i] = getn();
    build();
    while(Q--){
      L = getn()-1, R = getn()-1;
      if(L > 0){
        if(R < N-1)
          printf("%d\n", gcd(query(0, L-1), query(R+1, N-1)));
        else
          printf("%d\n", query(0, L-1));
      }else
        printf("%d\n", query(R+1, N-1));
    }
  }
  return 0;
}

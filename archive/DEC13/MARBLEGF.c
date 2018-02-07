// MARBLEGF

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
#define ll long long
#define pc putchar_unlocked
char pb[20];
inline void putll(ll n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int N, li[20],ln,an;
ll a[2000000];
void build(){
  int i,j,s;
  li[0] = 0, s = N, ln = 1;
  while(s > 1){
  li[ln] = li[ln-1] + s;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++)
      a[j] = a[i] + a[i+1];
    s >>= 1;
  ln++;
  }
  an = j;
}
void update(int i, int v){
  int l;
  l = 1, a[i] += v;
  while(l < ln)
    a[(i >>= 1) + li[l++]] += v;
}
ll query(int i0, int i1){
  int i,j,l,e,ia,ib;
  ll r;
  r = l = 0, e = 1, i = i0;
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
    r += a[i];
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
  char O;
  int Q,A,B, i;
  N = getn(), Q = getn();
  for(i = 0; i < N; i++)
    a[i] = getn();
  build();
  while(Q--){
    O = gc();
    while(O != 'G' && O != 'T' && O != 'S')
    O = gc();
  A = getn(), B = getn();
    if(O == 'G'){
      update(A, B);
    }else if(O == 'T'){
      update(A, -B);
    }else{
      putll(query(A, B)); pc('\n');
    }
  }
  return 0;
}

// QSET

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char s[100001];
ll a[200000][10]={{0}},an, li[20],ln;

void combine(ll* i, ll* j, ll* k){
  k[0] = i[0] + j[0] + i[6]*j[3] + i[7]*j[5] + i[8]*j[4];
  k[1] = i[1] + j[1] + i[6]*j[4] + i[7]*j[3] + i[8]*j[5];
  k[2] = i[2] + j[2] + i[6]*j[5] + i[7]*j[4] + i[8]*j[3];
  k[3] = i[3] + j[(i[9]==0) ? 3 : ((i[9]==1) ? 5 : 4)];
  k[4] = i[4] + j[(i[9]==0) ? 4 : ((i[9]==1) ? 3 : 5)];
  k[5] = i[5] + j[(i[9]==0) ? 5 : ((i[9]==1) ? 4 : 3)];
  k[6] = j[6] + i[(j[9]==0) ? 6 : ((j[9]==1) ? 8 : 7)];
  k[7] = j[7] + i[(j[9]==0) ? 7 : ((j[9]==1) ? 6 : 8)];
  k[8] = j[8] + i[(j[9]==0) ? 8 : ((j[9]==1) ? 7 : 6)];
  k[9] = (i[9] + j[9]) % 3;
}

void build(){
  int i,j,n;
  for(i = 0; i < an; ++i){
    n = (s[i] - '0') % 3;
    a[i][n] = a[i][n+3] = a[i][n+6] = 1;
    a[i][9] = n;
  }
  if(an == 1)
    return;
  li[0] = 0, n = an, ln = 1;
  while(n > 1){
    li[ln] = li[ln-1] + n;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, ++j)
      combine(a[i], a[i+1], a[j]);
    n >>= 1, ++ln;
  }
  an = li[ln] = j;
}

void update(int i, int v){
  int j,l;
  s[i] = '0' + v;
  v %= 3;
  for(j = 0; j < 10; ++j)
    a[i][j] = 0;
  a[i][v] = a[i][v+3] = a[i][v+6] = 1;
  a[i][9] = v;
  j = i >> 1, l = 1;
  while(li[l-1]+(j<<1)+1 < li[l] && j + li[l] < an){
    combine(a[li[l-1]+(j<<1)], a[li[l-1]+(j<<1)+1], a[li[l]+j]);
    j >>= 1, ++l;
  }
}

ll query(int i0, int i1){
  int i,j,k,l,e,ia,ib;
  ll r[10]={0}, r2[10];
  l = 0, e = 1, i = i0;
  while(i0 <= i1){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (i0 >> l+1);
      ia = (j - li[l+1]) << (l+1);
      ib = ia + (e << 1) - 1;
      if(ia == i0 && ib <= i1){
        i = j, e <<= 1, ++l;
        continue;
      }
    }
    ia = (i - li[l]) << l;
    if(ia == i0){
      combine(r, a[i], r2);
      for(k = 0; k < 10; ++k)
        r[k] = r2[k];
      i0 += e;
      if(i0 > i1)
        break;
    }
    if(i1 - i0 + 1 < e){
      e >>= 1, --l;
      i = li[l] + (ia >> l) + 1;
    }else{
      ++i;
    }
  }
  return r[0];
}

int main(){
  int N,M,O,X,Y, i;
  N = an = getn(), M = getn();
  scanf("%s", s);
  build();
  while(M--){
    O = getn(), X = getn(), Y = getn();
    if(O == 1 && Y != s[X-1]-'0')
      update(X-1, Y);
    else if(O == 2)
      printf("%lld\n", query(X-1, Y-1));
  }
  return 0;
}

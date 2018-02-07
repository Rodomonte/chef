// EQUAKE

#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int max(int a, int b){
  return (a > b) ? a : b;
}

int lrot(int n, int o){
  int q = n / o;
  return (n - o*q)*10 + q;
}

typedef struct {
  int m[12],p, pn,lc,rc;
} A ;

int N, li[20],ln,an;
A a[1600000];

void build(){
  int i,j,s, k;
  li[0] = 0, s = N, ln = 1;
  for(i = 0; i < N; i++) // Bottom level has no children
    a[i].lc = a[i].rc = -1;
  while(s > 1){
    li[ln] = li[ln-1] + s;
    if(s & 1) // Last node of odd-size level has no parent
      a[li[ln]-1].pn = -1;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++){
      a[i].pn = a[i+1].pn = j; // Link to parents
      a[j].lc = i, a[j].rc = i+1; // Link to children
      // Problem-specific:
      a[j].p = 0;
      for(k = 0; k < 12; k++)
        a[j].m[k] = (a[i].m[k] > a[i+1].m[k]) ? a[i].m[k] : a[i+1].m[k];
      //
    }
    s >>= 1;
    ln++;
  }
  an = j;
  a[an-1].pn = -1; // Root has no parent
}

int mt[12];
void process(int i){
  if(!a[i].p)
    return;
  int j,k;
  // Cycle maxes
  for(j = 0; j < 12; j++)
    mt[j] = a[i].m[j];
  for(j = 0, k = a[i].p; j < 12; j++, k=(k==11)?0:k+1)
    a[i].m[j] = mt[k];
  // Push pending rotations to children
  if(a[i].lc != -1){
    a[a[i].lc].p += a[i].p;
    if(a[a[i].lc].p >= 12)
      a[a[i].lc].p -= 12;
    a[a[i].rc].p += a[i].p;
    if(a[a[i].rc].p >= 12)
      a[a[i].rc].p -= 12;
  }
  a[i].p = 0;
}

void pushmax(int i){
  int j,k,p,n,f,l,r;
  k = i;
  p = a[k].pn;
  while(p != -1){
    f = 0;
    for(j = 0; j < 12; j++){
      n = a[p].m[j];
      l = j+a[a[p].lc].p;
      if(l >= 12)
        l -= 12;
      r = j+a[a[p].rc].p;
      if(r >= 12)
        r -= 12;
      a[p].m[j] = max(a[a[p].lc].m[l], a[a[p].rc].m[r]);
      if(a[p].m[j] != n)
        f = 1;
    }
    if(!f)
      break;
    k = p;
    p = a[k].pn;
  }
}

void update(int L, int R, int F){
  int i,j,l,e,ia,ib;
  l = 0, e = 1, i = L;
  while(L <= R){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (L >> l+1);
      ia = (j - li[l+1]) << (l+1);
      ib = ia + (e << 1) - 1;
      if(ia == L && ib <= R){
        i = j, e <<= 1, l++;
        continue;
      }
    }
    ia = (i - li[l]) << l;
    if(ia == L){
      // Problem-specific:
      a[i].p += F;
      while(a[i].p >= 12)
        a[i].p -= 12;
      process(i);
      pushmax(i);
      //
      L += e;
      if(L > R)
        break;
    }
    if(R - L + 1 < e){
      e >>= 1, l--;
      i = li[l] + (ia >> l) + 1;
    }else{
      i++;
    }
  }
}

// Query O(M):
//   For each aggregate node O(2lgN):
//     Mark path to root O(lgN)
//     For each child down to node O(lgN):
//       Push down pending O(1)
//     For each parent up to root O(lgN):
//       Push up maxes O(1)
// -> O(M*2lgN*3lgN) = 4.6*10^8  :)
int query(int L, int R){
  int i,j,l,e,ia,ib, r,p[20],pi,k;
  r = l = 0, e = 1, i = L;
  while(L <= R){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (L >> l+1);
      ia = (j - li[l+1]) << (l+1);
      ib = ia + (e << 1) - 1;
      if(ia == L && ib <= R){
        i = j, e <<= 1, l++;
        continue;
      }
    }
    ia = (i - li[l]) << l;
    if(ia == L){
      // Problem-specific:
      p[0] = k = i, pi = 1;
      while(a[k].pn != -1)
        p[pi++] = (k = a[k].pn);
      while(--pi >= 0)
        process(p[pi]);
      pushmax(i);
      r = max(r, a[i].m[0]);
      //
      L += e;
      if(L > R)
        break;
    }
    if(R - L + 1 < e){
      e >>= 1, l--;
      i = li[l] + (ia >> l) + 1;
    }else{
      i++;
    }
    if(i >= an)
      gc();
  }
  return r;
}

int main(){
  int M,Q,L,R,F, i,j,n;
  int r[10000][12];

  for(i = 0; i < 10; i++)
    for(j = 0; j < 12; j++)
      r[i][j] = i;
  for(i = 10; i < 100; i++){
    for(j = 0; j < 12; j += 2)
      r[i][j] = i;
    n = lrot(i, 10);
    for(j = 1; j < 12; j += 2)
      r[i][j] = n;
  }
  for(i = 100; i < 1000; i++){
    for(j = 0; j < 12; j += 3)
      r[i][j] = i;
    n = lrot(i, 100);
    for(j = 1; j < 12; j += 3)
      r[i][j] = n;
    n = lrot(n, 100);
    for(j = 2; j < 12; j += 3)
      r[i][j] = n;
  }
  for(i = 1000; i < 10000; i++){
    for(j = 0; j < 12; j += 4)
      r[i][j] = i;
    n = lrot(i, 1000);
    for(j = 1; j < 12; j += 4)
      r[i][j] = n;
    n = lrot(n, 1000);
    for(j = 2; j < 12; j += 4)
      r[i][j] = n;
    n = lrot(n, 1000);
    for(j = 3; j < 12; j += 4)
      r[i][j] = n;
  }

  N = getn();
  if(N == 1){
    n = getn(), j = 0;
    M = getn();
    while(M--){
      Q = getn(), L = getn(), R = getn();
      if(Q)
        putn(r[n][j]), pc('\n');
      else
        j = (j + getn()) % 12;
    }
    return 0;
  }

  for(i = 0; i < N; i++){
    n = getn(), a[i].p = 0;
    for(j = 0; j < 12; j++)
      a[i].m[j] = r[n][j];
  }
  build();

  M = getn();
  while(M--){
    Q = getn(), L = getn(), R = getn();
    if(Q)
      putn(query(L,R)), pc('\n');
    else
      F = getn(), update(L,R,F);
  }
  return 0;
}

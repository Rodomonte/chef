//

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T;

  T = getn();
  while(T--){

  }
  return 0;
}

// METHODS

int abs(int a){ return (a < 0) ? -a : a; }
int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

int madd(int a, int b){ return ((a += b) >= MOD) ? a-MOD : a; }
int msub(int a, int b){ return ((a -= b) < 0) ? a+MOD : a; }
int mmul(int a, int b){ return (ll)a * b % MOD; }

// Negative integer input
#define gc getchar_unlocked
int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

// Negative integer output
#define pc putchar//_unlocked
char pb[10];
void putn(int n){
  if(!n) pc('0');
  if(n < 0){ pc('-'); n *= -1; }
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

// Fast power
#define ll long long
#define MOD 1000000007
int pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1) r = r * n % MOD;
    n = n * n % MOD, e >>= 1;
  }
  return (int)r;
}

// Greatest common denominator
int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}
// Least common multiple
int lcm(int a, int b){
  return a / gcd(a,b) * b;
}

// nCk recurrence relation
double nck[40][40]={{0}};
nck[0][0] = 1;
for(i = 1; i < 40; i++){
  nck[i][0] = 1;
  for(j = 1; j <= i; j++)
    nck[i][j] = nck[i-1][j-1] + nck[i-1][j];
}

// Divisors
int pf[1000001][256], pn[1000001];
for(i = 0; i <= 1000000; ++i) pn[i] = pf[i][0] = 1;
for(i = 2; i <= 1000000; ++i)
  for(j = i; j <= 1000000; j += i)
    pf[j][pn[j]++] = i;

// Sieve
char s[1000001]={0};
int p[78498], pn;
for(i = 2, pn = 0; i <= 1000000; ++i){
  if(s[i]) continue;
  for(j = (i<<1); j <= 1000000; j += i)
    s[i] = 1;
  p[pn++] = i;
}

// Quick sort
void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1), sort(l, a+n-l);
}

// FWT
int N, li[20],ln,an;
ll a[2000000];

void build(){
  int i,j,s;
  li[0] = 0, s = N, ln = 1;
  while(s > 1){
    li[ln] = li[ln-1] + s;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++)
      a[j] = a[i] + a[i+1]; //!
    s >>= 1, ++ln;
  }
  an = j;
}


// Need push fn
void update(int L, int R, int v){
  int i,j,l,e,ia,ib;
  l = 0, e = 1, i = L;
  while(L <= R){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (L >> l+1);
      ia = (j - li[l+1]) << (l+1), ib = ia + (e << 1) - 1;
      if(ia == L && ib <= R){ i = j, e <<= 1, l++; continue; }
    }
    ia = (i - li[l]) << l;
    if(ia == L){
      a[i] += v;
      push(i);
      L += e;
      if(L > R) break;
    }
    if(R - L + 1 < e) e >>= 1, l--, i = li[l] + (ia >> l) + 1;
    else i++;
  }
}

ll query(int L, int R){
  int i,j,l,e,ia,ib;
  ll r;
  r = l = 0, e = 1, i = L;
  while(L <= R){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (L >> l+1);
      ia = (j - li[l+1]) << (l+1), ib = ia + (e << 1) - 1;
      if(ia == L && ib <= R){ i = j, e <<= 1, l++; continue; }
    }
    ia = (i - li[l]) << l;
    if(ia == L){
      r += a[i]; //!
      L += e;
      if(L > R) break;
    }
    if(R - L + 1 < e) e >>= 1, l--, i = li[l] + (ia >> l) + 1;
    else i++;
  }
  return r;
}

// Hashing
int KMOD; // = N/.75 (# of hash buckets)
int key(char* s){
  // MURMUR
  int l,m,r,h,l4,i,i4,k;
  l = strlen(s), m = 0x5bd1e995, r = 24;
  h = 0x9747b28c ^ l, l4 = l / 4;
  for(i = 0; i < l4; i++){
    i4 = i * 4;
    k = (s[i4] & 0xff);
    k += ((s[i4+1] & 0xff) << 8);
    k += ((s[i4+2] & 0xff) << 16);
    k += ((s[i4+3] & 0xff) << 24);
    k *= m;
    k ^= k >> r;
    k *= m;
    h *= m;
    h ^= k;
  }
  switch(l % 4){
  case 3: h ^= (s[(l&~3)+2] & 0xff) << 16;
  case 2: h ^= (s[(l&~3)+1] & 0xff) << 8;
  case 1: h ^= (s[l&~3] & 0xff);
    h *= m;
  }
  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;
  return h % KMOD;
}

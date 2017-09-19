// SEACO

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b){ return (a+b >= MOD) ? a+b-MOD : a+b; }
int msub(int a, int b){ return (a-b < 0) ? a-b+MOD : a-b; }
int mmul(int a, int b){ return (ll)a * b % MOD; }

int getSum(int BITree[], int index){
  int sum = 0;
  index = index + 1;
  while(index > 0){
    sum = madd(sum, BITree[index]);
    index -= index & (-index);
  }
  return sum;
}

void updateBIT(int BITree[], int n, int index, int val){
  index = index + 1;
  while(index <= n){
    BITree[index] = madd(BITree[index], val);
    index += index & (-index);
  }
}

int sum(int x, int BITTree1[], int BITTree2[]){
  return msub(mmul(getSum(BITTree1, x), x), getSum(BITTree2, x));
}

void updateRange(int BITTree1[], int BITTree2[], int n, int val, int l, int r){
  updateBIT(BITTree1, n, l, val);
  updateBIT(BITTree1, n, r+1, msub(0, val));
  updateBIT(BITTree2, n, l, mmul(val, (l-1)));
  updateBIT(BITTree2, n, r+1, mmul(msub(0, val), r));
}

int rangeSum(int l, int r, int BITTree1[], int BITTree2[]){
  return msub(sum(r, BITTree1, BITTree2), sum(l-1, BITTree1, BITTree2));
}

struct C {
  int t,l,r;
  C(){}
  C(int _t, int _l, int _r): t(_t), l(_l), r(_r) {}
};

int a[100002], a2[100002], b[100002], b2[100002];
C c[100001];
int main(){
  int T,N,M, i;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i <= 100001; ++i) a[i] = a2[i] = b[i] = b2[i] = 0;
    for(i = 1; i <= M; ++i) c[i].t = getn(), c[i].l = getn(), c[i].r = getn();

    for(i = M; i >= 1; --i)
      if(c[i].t == 2)
        updateRange(b, b2, M+1, madd(1, rangeSum(i,i,b,b2)), c[i].l, c[i].r);
    for(i = 1; i <= M; ++i)
      if(c[i].t == 1)
        updateRange(a, a2, N+1, madd(1, rangeSum(i,i,b,b2)), c[i].l, c[i].r);

    for(i = 1; i <= N; ++i) printf("%d ", rangeSum(i,i,a,a2));
    printf("\n");
  }
  return 0;
}

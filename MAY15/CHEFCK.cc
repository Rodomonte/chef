// CHEFCK

#include <stdio.h>
#include <deque>

#define ll long long
#define MAX 10000001

int min(int a, int b){
  return (a < b) ? a : b;
}

int madd(int a, int b, int m){
  if((a += b) >= m)
    return a - m;
  return a;
}

int mmul(ll a, ll b, ll m){
  return (int)(a * b % m);
}

int a[MAX], b[MAX], c[MAX], l2[MAX], la[MAX], da[MAX];
int main(){
  int N,K,Q,A,B,C,D,E,F,R,S,T,M,L1,LA,LC,LM,D1,DA,DC,DM, i,j,bl,cl,t,r,rp;
  ll rs;
  std::deque<int> w;
  scanf("%d %d %d\n%d %d %d %d %d %d %d %d %d %d %d\n%d %d %d %d %d %d %d %d",
        &N, &K, &Q, &A, &B, &C, &D, &E, &F, &R, &S, &T, &M, a+1, &L1, &LA, &LC,
        &LM, &D1, &DA, &DC, &DM);

  C %= M, F %= M, l2[1] = 0, t = 2, j = T;
  for(i = 2; i <= N; ++i){
    j = mmul(j, T, S), r = a[i-1];
    a[i] = (j <= R) ?
        madd(madd(mmul(A, mmul(r, r, M), M), mmul(B, r, M), M), C, M) :
        madd(madd(mmul(D, mmul(r, r, M), M), mmul(E, r, M), M), F, M);
    l2[i] = l2[i-1];
    if(t == i)
      ++l2[i], t <<= 1;
  }

  bl = l2[K];
  cl = bl+1, t = 1<<bl;
  for(i = 1; i <= t; ++i){
    while(!w.empty() && a[i] <= a[w.back()])
      w.pop_back();
    w.push_back(i);
  }
  for(; i <= N; ++i){
    b[i-t] = a[w.front()];
    while(!w.empty() && a[i] <= a[w.back()])
      w.pop_back();
    while(!w.empty() && w.front() <= i-t)
      w.pop_front();
    w.push_back(i);
  }
  b[N-t+1] = a[w.front()];
  t = N-(1<<cl)+2, r = (1<<(cl-1))+1;
  for(i = 1; i < t; ++i, ++r){
    c[i] = min(b[i], b[r]);
  }

  LC %= LM, la[0] = LC;
  for(i = 1; i < N-K+1; ++i)
    la[i] = madd(la[i-1], LA, LM);
  la[L1] = madd(mmul(LA, L1, LM), LC, LM);
  DC %= DM, da[0] = DC;
  for(i = 1; i < K+1; ++i)
    da[i] = madd(da[i-1], DA, DM);
  da[D1] = madd(mmul(DA, D1, DM), DC, DM);

  rs = 0, rp = 1;
  while(Q--){
    L1 = la[L1], D1 = da[D1];
    i = L1 + 1;
    j = min(i+K-1+D1, N);
    t = l2[j-i+1];
    r = (t == bl) ? min(b[i], b[j-(1<<t)+1]) : min(c[i], c[j-(1<<t)+1]);
    rs += r;
    rp = mmul(rp, r, 1000000007);
  }
  printf("%lld %d\n", rs, rp);
  return 0;
}

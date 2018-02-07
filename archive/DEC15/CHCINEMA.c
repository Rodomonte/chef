// CHCINEMA

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline ll getll(){
  ll n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

ll min(ll a, ll b){
  return (a < b) ? a : b;
}

ll eval(ll N, ll M, ll Z, ll L, ll R, ll B){
  if(Z+L+R >= N*M)
    return N*M;
  if(M == 1)
    return min(Z+L+R+B, N*M);
  ll r,u,n,t;
  r = 0, u = N;

  if(M&1){
    // BZBZB
    n = min(min(B / ((M>>1)+1), Z / (M>>1)), u), t = n * (M>>1);
    B -= t+n, Z -= t, r += (t<<1)+n, u -= n;
  }else{
    if(M == 2){
      // LB
      n = min(min(L, B), u), L -= n, B -= n, r += (n<<1), u -= n;
      // BR
      n = min(min(B, R), u), B -= n, R -= n, r += (n<<1), u -= n;
    }else{
      // LBZBZB
      n = min(min(min(L, B / (M>>1)), Z / ((M>>1)-1)), u), t = n * (M>>1);
      L -= n, B -= t, Z -= t-n, r += (t<<1), u -= n;
      // BZBZBR
      n = min(min(min(B / (M>>1), Z / ((M>>1)-1)), R), u), t = n * (M>>1);
      B -= t, Z -= t-n, R -= n, r += (t<<1), u -= n;
    }
    // BZBZ
    n = min(min(B / (M>>1), Z / (M>>1)), u), t = n * (M>>1);
    B -= t, Z -= t, r += (t<<1), u -= n;
  }
  if(!u)
    return r;
  if(Z >= B)
    return r + min(Z+L+R+B, u * M);
  // ..BZBZB..
  B -= Z+1, t = M-(Z<<1)-1, Z = 0, r += M-t;

  // L/R column
  if(!(M&1)){
    if(L+R <= u)
      return r + L+R + min(B, (t>>1)+((u-1) * (M>>1)));
    n = min(L, u), L -= n, R -= u-n, r += u, --t, --M;
  }
  // LL..
  n = min(L, t), L -= n, r += n, t -= n;
  // ..RR
  n = min(R, t), R -= n, r += n, t -= n;
  // ..-B-B
  n = min(B, t>>1), B -= n, r += n, --u;
  // LLB
  n = min(min(L / (M-1), B), u), t = n * M, L -= t-n, B -= n, r += t, u -= n;
  // BRR
  n = min(min(R / (M-1), B), u), t = n * M, R -= t-n, B -= n, r += t, u -= n;
  if(!u)
    return r;
  if(!B)
    return r + min(Z+L+R, u * M);
  // LLB..
  --B, r += L+1, t = M-L-1, L = 0;
  // ..RR
  n = min(R, t), R -= n, r += n, t -= n;
  // ..-B-B
  n = min(B, t>>1), B -= n, r += n, --u;
  if(!u)
    return r;
  // ..RR
  r += R, t = M-R, R = 0;
  // B-B-B..
  n = min(B, (t+1)>>1), B -= n, r += n, --u;
  // B-B-B
  n = min(B / ((M>>1)+1), u), t = n * ((M>>1)+1), B -= t, r += t, u -= n;
  return r + (u ? B : 0);
}

int main(){
  ll T,N,M,Z,L,R,B, r;
  T = getll();
  while(T--){
    N = getll(), M = getll(), Z = getll();
    L = getll(), R = getll(), B = getll();
    printf("%lld\n", eval(N, M, Z, L, R, B));
  }
  return 0;
}

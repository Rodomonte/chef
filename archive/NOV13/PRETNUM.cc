// PRETNUM

#include <stdio.h>
#include <string.h>
#include <math.h>

#define ll long long
#define gc getchar_unlocked
inline ll getl(){
  char c = gc();
  ll n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char pf[999984]={0}, prf[1000001];
int p0[168] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,
    83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,
    179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,
    271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,
    379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,
    479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,
    599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,
    701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,
    823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,
    941,947,953,967,971,977,983,991,997};
int p[78498], fm[78498], f[12];
int main(){
  int T, i,j, pi,fi, d,n,r;
  ll L,R, k,t;
  for(i = 0; i < 168; i++){
    j = p0[i]*2;
    while(j < 999984){
      pf[j] = 1;
      j += p0[i];
    }
  }
  pi = 0;
  for(i = 2; i < 999984; i++)
    if(!pf[i])
      p[pi++] = i;
  T = (int)getl();
  while(T--){
    L = getl(), R = getl();
    // Count primes
    d = R-L, j = r = 0;
    memset(prf, 0, sizeof(prf));
    if(L == 1)
      prf[0] = 1;
    while(1){
      if(p[j] < 1)
        while(1);
      n = L % p[j];
      if(!n)
        i = (L==p[j]) ? p[j] : 0;
      else if(L + (p[j]-n) == p[j])
        i = p[j]*2 - n;
      else
        i = p[j] - n;
      for(; i <= d; i += p[j])
        prf[i] = 1;
      j++;
      if((ll)p[j]*p[j] > R || j > 78497)
        break;
    }
    for(i = 0; i <= d; i++)
      if(prf[i] == 0)
        r++;
    // Count perfect squares with prime # divisors
    for(k = L; k <= R; k++){
      if(k == 1)
        continue;
      t = (ll)sqrt(k);
      if(t*t == k){
        t = k, i = fi = 0;
        memset(fm, 0, sizeof(fm));
        while(t > 1){
          if(p[i] < 1)
            while(1);
          if(t % p[i]){
            i++;
          }else{
            fm[i]++;
            if(!fi || f[fi-1] != i)
              f[fi++] = i;
            t /= p[i];
          }
        }
        n = 1;
        for(i = 0; i < fi; i++)
          n *= fm[f[i]] + 1;
        for(i = 0; p[i] < n; i++);
        if(n == p[i])
          r++;
      }
    }
    printf("%d\n",r);
  }
  return 0;
}

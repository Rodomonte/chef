// WCOUNT

#include <stdio.h>
#include <string.h>

#define llu unsigned long long
#define MOD 1000000007
int a[58];
llu b[501]={1,1,2,6,24,120,720,5040,40320,362880,3628800,
    39916800,479001600,227020758,178290591,674358851,
    789741546,425606191,660911389,557316307,146326063},
  c[11]={1,1,500000004,166666668,41666667,808333339,
    301388891,900198419,487524805,831947206,283194722};
int main(){
  char s[501];
  int T, i, l,n=20;
  llu r;
  scanf("%d\n",&T);
  while(T--){
    gets(s);
    l = strlen(s);
    for(i = 0; i < 58; i++)
      a[i] = 0;
    for(i = 0; i < l; i++)
      a[s[i]-65]++;
    while(n < l)
      b[++n] = (b[n-1] * n) % MOD;
    r = b[l];
    for(i = 0; i < 58; i++)
      r = (r * c[a[i]]) % MOD;
    printf("%llu\n",r);
  }
  return 0;
}

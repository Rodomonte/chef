// ABCSTR

#include <stdio.h>
#include <string.h>
#include <map>
using std::map;

#define ll long long
#define MAX 1000000
char s[MAX+1];
ll sfac(ll n){
  if(n < 1)
    return 0;
  return n+sfac(n-1);
}
int main(){
  int N, i,a,b,c,t;
  ll n,r;
  map<ll,int> m;
  map<ll,int>::iterator it;
  scanf("%s",s);
  N = strlen(s);
  a = b = c = 0;
  n = MAX;
  n <<= 32;
  n += MAX;
  m[n] = 1;
  for(i = 0; i < N; i++){
    if(s[i] == 'A') a++;
    else if(s[i] == 'B') b++;
    else c++;
    //printf("abc: %d %d %d\n",a,b,c);
    n = 0;
    n = a - b + MAX;
    //printf("a-b+MAX: %lld\n",n);
    n <<= 32;
    n += b - c + MAX;
    //printf("b-c+MAX: %d\n",b-c+MAX);
    //printf("-- n: %lld\n\n",n);
    if(m.find(n) == m.end())
      m[n] = 1;
    else
      m[n]++;
  }
  r = 0;
  for(it = m.begin(); it != m.end(); it++){
    //printf("%lld -> %d\n",it->first,it->second);
    t = it->second;
    if(t > 1)
      r += sfac(t-1);
  }
  printf("%lld\n",r);
  return 0;
}

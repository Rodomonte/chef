// VK18

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int n){ return (n < 0) ? -n : n; }

int d(int n){
  char s[8];
  int i, e,o;
  sprintf(s, "%d", n), e = o = 0;
  for(i = 0; s[i]; ++i)
    if((s[i]-'0')&1) o += s[i]-'0';
    else e += s[i]-'0';
  return abs(e - o);
}

int b[2000000];
ll a[1000001];
int main(){
  int T, i;

  for(i = b[1] = 2; i < 2000000; ++i) b[i] = b[i-1] + d(i+1);
  for(i = a[1] = 2; i <= 1000000; ++i)
    a[i] = a[i-1] + b[i+i-1] + b[i+i-2] - (b[i-1]<<1);

  T = getn();
  while(T--) printf("%lld\n", a[getn()]);
  return 0;
}

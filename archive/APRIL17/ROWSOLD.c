// ROWSOLD

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[100001];
int main(){
  int T, i,o,z;
  ll r;

  T = getn();
  while(T--){
    scanf("%s", a);

    r = o = i = 0;
    while(a[i] == '0')
      ++i;
    while(a[i]){
      while(a[i] == '1')
        ++o, ++i;
      z = 0;
      while(a[i] == '0')
        ++z, ++i;
      if(z)
        r += (ll)(z+1) * (ll)o;
    }

    printf("%lld\n", r);
  }
  return 0;
}

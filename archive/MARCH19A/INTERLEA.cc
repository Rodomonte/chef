// INTERLEA

#include <stdio.h>
#include <string.h>
#include <unordered_set>

#define uset std::unordered_set
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char a[10001][101];
int c[10001], d[10001], r[1000000], s[1000000];
uset<int> b[10];
int main(){
  bool u;
  int N, i,j,k,mi, l,m,n,t;

  N = getn(), l = 0;
  for(i = 1; i <= N; ++i){
    scanf("%s", a[i]);
    c[i] = strlen(a[i]), l += c[i], d[i] = 0;
    for(j = 0; j < c[i]; ++j)
      a[i][j] -= '0';
  }

  if(N == 1){
    k = strlen(a[1]);
    for(i = 0; i < k; ++i)
      r[i] = 1;

  }else{
    for(i = 2; i <= N; ++i)
      b[a[i][0]].insert(i);
    b[a[1][1]].insert(1), r[0] = k = 1, s[0] = a[1][0], d[1] = 1, u = true;

    while(k < l){
      for(i = 0, m = 10; i < 10; ++i){
        if(b[i].empty()) continue;
        else if(u && i >= s[k-1] && i - s[k-1] < m) m = i - s[k-1], mi = i;
        else if(!u && i <= s[k-1] && s[k-1] - i < m) m = s[k-1] - i, mi = i;
      }

      if(m == 10){ u = !u; continue; }
      r[k] = t = *(b[mi].begin()), s[k] = mi, ++k, ++d[t];
      if(d[t] < c[t] && a[t][d[t]] != mi)
        b[a[t][d[t]]].insert(t), b[mi].erase(b[mi].begin());
      else if(d[t] == c[t]) b[mi].erase(b[mi].begin());
    }
  }

  for(i = 0; i < k; ++i)
    printf("%d ", r[i]);
  printf("\n");
  return 0;
}

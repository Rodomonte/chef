// UASEQ

#include <stdio.h>
#include <map>
using std::map;

#define gc getchar_unlocked
#define pc putchar_unlocked
#define INF 2000000000

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  if(n < 0) pc('-'), n = 0-n;
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int a[100000];
int main(){
  int N,K, i,j,m,n,c[50],d[50];
  map<int,int> b;
  map<int,int>::iterator it;
  N = getn(), K = getn();
  for(i = 0; i < N; i++)
    a[i] = getn();
  if(N > 50){
    m = 1;
    for(i = 1; i < N; i++){
      n = a[i] - a[i-1];
      it = b.find(n);
      if(it != b.end()){
        it->second++;
        if(it->second > m)
          m = it->second, j = i;
      }else
        b[n] = 1;
    }
    n = a[j] - a[j-1];
    for(i = j+1; i < N; i++)
      if(a[i]-a[i-1] != n)
        a[i] = a[i-1] + n;
    for(i = j-1; i > 0; i--)
      if(a[i]-a[i-1] != n)
        a[i-1] = a[i] - n;
    for(i = 0; i < N; i++)
      putn(a[i]), pc(' ');
    pc('\n');
  }else{
    for(i = 1; i < N; i++){
      n = a[i] - a[i-1];
      if(b.find(n) == b.end())
        b[n] = i;
    }
    m = n = INF;
    for(it = b.begin(); it != b.end(); it++){
      for(i = 0; i < N; i++)
        c[i] = a[i];
      j = 0;
      for(i = it->second+1; i < N; i++)
        if(c[i]-c[i-1] != it->first)
          c[i] = a[i-1] + it->first, j++;
      for(i = it->second-1; i > 0; i--)
        if(c[i]-c[i-1] != it->first)
          c[i-1] = c[i] - it->first, j++;
      if(j > K)
        continue;
      if(c[0] < n || (c[0] == n && c[1]-c[0] < m)){
        n = c[0], m = c[1]-c[0];
        for(i = 0; i < N; i++)
          d[i] = c[i];
      }
    }
    for(i = 0; i < N; i++)
      putn(d[i]), pc(' ');
    pc('\n');
  }
  return 0;
}

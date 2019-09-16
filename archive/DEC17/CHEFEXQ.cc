// CHEFEXQ

#include <stdio.h>
#include <math.h>
#include <utility>
#include <unordered_map>

using std::pair;
using std::unordered_map;

#define gc getchar

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int N, s, a[100001], d[100001], x[320];
unordered_map<int,int> b[320];
unordered_map<int,int>::iterator it;

void update(int i, int k){
  int j, n,t;
  t = a[i] ^ k, a[i] = k;
  for(j = i, n = j/s; j <= N && j % s; ++j){
    it = b[n].find(d[j]);
    if(it->second == 1) b[n].erase(it);
    else --it->second;
    d[j] ^= t, it = b[n].find(d[j]);
    if(it == b[n].end()) b[n].insert(pair<int,int>(d[j], 1));
    else ++it->second;
  }
  if(j > N) return;
  for(j /= s; j <= s+3; ++j) x[j] ^= t;
}

int query(int i, int k){
  int j, n,r;
  for(j = i, n = j/s, r = 0; j > 0 && (j+1) % s; --j)
    if((d[j] ^ x[n]) == k) ++r;
  if(!j) return r;
  for(j /= s; j >= 0; --j){
    it = b[j].find(k ^ x[j]);
    if(it != b[j].end()) r += it->second;
  }
  return r;
}

int main(){
  int Q,O,I,K, i,j;

  N = getn(), Q = getn(), s = sqrt(N), d[0] = 0;
  for(i = 1, j = 0; i <= N; ++i){
    if(i == j*s+s) ++j;
    a[i] = getn(), d[i] = d[i-1] ^ a[i], it = b[j].find(d[i]);
    if(it == b[j].end()) b[j].insert(pair<int,int>(d[i], 1));
    else ++it->second;
  }
  for(i = 0; i <= s+3; ++i) x[i] = 0;

  while(Q--){
    O = getn(), I = getn(), K = getn();
    if(O == 1) update(I, K);
    else printf("%d\n", query(I, K));
  }
  return 0;
}

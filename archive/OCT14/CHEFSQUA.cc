// CHEFSQUA

#include <stdio.h>
#include <unordered_set>
using std::unordered_set;

#define gc getchar_unlocked
#define ll long long
#define OFF 1000000

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

bool ins(int n){
  return (n >= 0 && n <= 2000000);
}

unordered_set<int> a[2000001];
int main(){
  bool f,f1,f2;
  int N,X[2000],Y[2000], i,j,x1,y1,x2,y2;
  N = getn();
  if(N == 0){
    printf("4\n");
    return 0;
  }else if(N == 1){
    printf("3\n");
    return 0;
  }
  for(i = 0; i < N; i++){
    X[i] = getn()+OFF, Y[i] = getn()+OFF;
    a[X[i]].insert(Y[i]);
  }
  f = false;
  for(i = 0; i < N-1; i++){
    for(j = i+1; j < N; j++){
      x1 = X[i]+Y[i]-Y[j], y1 = Y[i]+X[j]-X[i];
      f1 = ins(x1) && ins(y1) && (a[x1].find(y1) != a[x1].end());
      x2 = X[j]+Y[i]-Y[j], y2 = Y[j]+X[j]-X[i];
      f2 = ins(x2) && ins(y2) && (a[x2].find(y2) != a[x2].end());
      if(f1){
        if(f2){
          printf("0\n");
          return 0;
        }else
          f = true;
      }else if(f2)
        f = true;
      x1 = X[i]-(Y[i]-Y[j]), y1 = Y[i]-(X[j]-X[i]);
      f1 = ins(x1) && ins(y1) && (a[x1].find(y1) != a[x1].end());
      x2 = X[j]-(Y[i]-Y[j]), y2 = Y[j]-(X[j]-X[i]);
      f2 = ins(x2) && ins(y2) && (a[x2].find(y2) != a[x2].end());
      if(f1){
        if(f2){
          printf("0\n");
          return 0;
        }else
          f = true;
      }else if(f2)
        f = true;
    }
  }
  printf((f) ? "1\n" : "2\n");
  return 0;
}

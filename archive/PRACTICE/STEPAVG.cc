// STEPAVG

#include <stdio.h>
#include <utility>
#include <map>

using std::multimap;

#define pdi std::pair<double,int>
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

double abs(double d){ return (d < 0) ? -d : d; }

int main(){
  int T,N,K,X, i,k;
  double s,t;
  multimap<double,int> a;
  multimap<double,int>::iterator it,jt;

  T = getn();
  while(T--){
    N = getn(), K = getn(), a.clear(), s = 0;
    for(i = 0; i < N; ++i) X = getn(), s += X, a.insert(pdi(X, i));

    k = N;
    while(a.size() > 1){
      if(s / a.size() < K) it = jt = a.begin(), ++jt;
      else it = a.end(), --it, jt = it, --jt;
      t = s - it->first - jt->first + (it->first+jt->first)/2;
      // printf("sdif=%lf tdif=%lf\n", abs(s / a.size() - K),
      //        abs(t / a.size() - K));
      if(abs(t / (a.size()-1) - K) > abs(s / a.size() - K))
        it = a.begin(), jt = a.end(), --jt;
      a.insert(pdi((it->first+jt->first)/2, k++));
      printf("%d %d\n", it->second+1, jt->second+1);
      s += (it->first+jt->first)/2 - it->first - jt->first;
      a.erase(it), a.erase(jt);
    }
    // printf("final = %lf\n", a.begin()->first);
  }
  return 0;
}

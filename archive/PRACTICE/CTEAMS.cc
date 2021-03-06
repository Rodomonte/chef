// CTEAMS
// Priority queue practice: C++ benchmark

#include <stdio.h>
#include <queue>
using namespace std;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define pq priority_queue
struct P {
  int a, r;
  P(int a0, int r0): a(a0), r(r0) {}
};
class ycomp {
  public:
  bool operator()(P a, P b){
    return a.a < b.a;
  }
};
class ocomp {
  public:
  bool operator()(P a, P b){
    return a.a > b.a;
  }
};
int abs(int a){
  return a < 0 ? -a : a;
}
int main(){
  bool e;
  int N,A,R, ry,ro;
  pq<P, vector<P>, ycomp> qy;
  pq<P, vector<P>, ocomp> qo;
  N = getn()-1, A = getn(), R = getn();
  ry = R, ro = 0, e = false;
  qy.push(P(A,R));
  printf("%d\n",R);
  while(N--){
    A = getn(), R = getn();
    if(e){
      if(A <= qo.top().a){
        qy.push(P(A,R));
        ry += R;
      }else{
        ry += qo.top().r;
        ro += R - qo.top().r;
        qy.push(qo.top());
        qo.pop();
        qo.push(P(A,R));
      }
    }else{
      if(A >= qy.top().a){
        qo.push(P(A,R));
        ro += R;
      }else{
        ry += R - qy.top().r;
        ro += qy.top().r;
        qo.push(qy.top());
        qy.pop();
        qy.push(P(A,R));
      }
    }
    e = e ? false : true;
    printf("%d\n",abs(ry-ro));
  }
  return 0;
}

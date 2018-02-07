// REBXOR

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct Node {
  int l,r,v;
};
vector<Node> b;

int init(){
  Node n;
  n.l = n.r = n.v = -1;
  b.push_back(n);
  return b.size()-1;
}

void insert(int v){
  int n,i,t;
  n = 0;
  for(i = 28; i >= 0; --i){
    if(v & (1 << i)){
      if(b[n].r == -1){
  t = init();
        b[n].r = t;
      }
      n = b[n].r;
    }else{
      if(b[n].l == -1){
  t = init();
  b[n].l = t;
      }
      n = b[n].l;
    }
  }
  b[n].v = v;
}

int query(int v){
  int n,i;
  n = 0;
  for(i = 28; i >= 0; --i){
    if(v & (1 << i))
      n = (b[n].l == -1) ? b[n].r : b[n].l;
    else
      n = (b[n].r == -1) ? b[n].l : b[n].r;
  }
  return b[n].v;
}

int a[400000], c[400000];
int main(){
  int N, i,m,x,t;

  N = getn();
  for(i = 0; i < N; ++i)
    a[i] = getn();

  init();
  insert(0);
  m = x = 0;
  for(i = 0; i < N-1; ++i){
    x ^= a[i];
    insert(x);
    t = x ^ query(x);
    if(t > m)
      m = t;
    c[i] = m;
  }

  b.clear();
  init();
  insert(0);
  m = x = 0;
  for(i = N-1; i > 0; --i){
    x ^= a[i];
    insert(x);
    t = c[i-1] + (x ^ query(x));
    if(t > m)
      m = t;
  }

  printf("%d\n", m);
  return 0;
}

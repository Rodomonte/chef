// LEEXAMS

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int N, a[16][3];
double r;
void fn1(int i, double p, char* v){
  if(i >= N){
    r += p;
    return;
  }
  if(!v[a[i][1]]){
    char vn[17];
    memcpy(vn, v, 17);
    vn[a[i][1]] = 1;
    fn1(i+1, p*((double)a[i][0]/100), vn);
  }
  if(!v[a[i][2]]){
    char vn[17];
    memcpy(vn, v, 17);
    vn[a[i][2]] = 1;
    fn1(i+1, p*((double)(100-a[i][0])/100), vn);
  }
}
int main(){
  int T,A,B, i;
  T = getn();
  while(T--){
    N = getn();
    if(N > 16){
      for(i = 0; i < N; i++)
        getn(), getn(), getn();
      printf("0.0\n");
      continue;
    }
    for(i = 0; i < N; i++)
      a[i][0] = getn(), a[i][1] = getn(), a[i][2] = getn();
    r = 0;
    char v[17]={0};
    fn1(0,1.0,v);
    printf("%.7f\n",r);
  }
  return 0;
}

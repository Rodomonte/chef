// DX

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

#define pb push_back
#define INF 2000000000

double a[10000], b[100][100], r[10000][3];

bool cmp(int i, int j){ return a[i] > a[j]; }

int main(){
  int A,B,N, i,j,k,ii,jj,mi,mj, d,m,m2;
  vector<int> c;

  scanf("%d %d\n%d", &A, &B, &N), c.clear();
  for(i = 0; i < N; ++i)
    scanf("%lf", a+i), c.pb(i);

  for(i = 0; i < A; ++i)
    for(j = 0; j < B; ++j)
      b[i][j] = 0;
  sort(c.begin(), c.end(), cmp);

  for(k = 0; k < N; ++k){
    m = INF, d = (int)ceil(a[c[k]]*2);
    for(i = 0; i < A-d+1; ++i){
      for(j = 0; j < B-d+1; ++j){
        m2 = 0;
        for(ii = i; ii < i+d; ++ii)
          for(jj = j; jj < j+d; ++jj)
            if(b[ii][jj] > m2) m2 = b[ii][jj];
        if(m2 < m) m = m2, mi = i, mj = j;
      }
    }

    for(i = mi; i < mi+d; ++i)
      for(j = mj; j < mj+d; ++j)
        b[i][j] = m + d;
    r[c[k]][0] = (double)d/2 + mi;
    r[c[k]][1] = (double)d/2 + mj;
    r[c[k]][2] = b[mi][mj] - (double)d/2;
  }

  for(i = 0; i < N; ++i)
    printf("%.2lf %.2lf %.2lf\n", r[i][0], r[i][1], r[i][2]);
  return 0;
}

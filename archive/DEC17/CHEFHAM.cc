// CHEFHAM

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define MX 100000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[MX], b[MX],bn, c[MX+1][3], p[MX/2][3],pn, s[MX][2],sn;

void shuf(vector<int>& v){
  int i,j,t;
  for(i = v.size()-1; i > 0; --i)
    j = rand()%(i+1), t = v[i], v[i] = v[j], v[j] = t;
}

void fill(vector<int>& v){
  char f;
  int i;
  while(1){
    for(i = 0, f = 1; i < v.size(); ++i) if(v[i] == a[bn+i]){ f = 0; break; }
    if(f) break;
    shuf(v);
  }
  for(i = 0; i < v.size(); ++i) b[bn++] = v[i];
}

int main(){
  int T,N, i,j;
  vector<int> v;

  T = getn();
  while(T--){
    N = getn();
    for(i = 1; i <= MX; ++i) c[i][0] = 0;
    for(i = 0; i < N; ++i) a[i] = getn(), c[a[i]][++c[a[i]][0]] = i;

    if(N == 1){ printf("0\n%d\n", a[0]); continue;
    }else if(N == 2){
      if(a[0] == a[1]) printf("0\n%d %d\n", a[0], a[1]);
      else printf("2\n%d %d\n", a[1], a[0]);
      continue;
    }else if(N == 3){
      if(a[0] == a[1] && a[0] == a[2])
        printf("0\n%d %d %d\n", a[0], a[1], a[2]);
      else if(a[0] == a[1] || a[0] == a[2])
        printf("2\n%d %d %d\n", a[0], a[2], a[1]);
      else if(a[1] == a[2]) printf("2\n%d %d %d\n", a[1], a[0], a[2]);
      else printf("3\n%d %d %d\n", a[1], a[2], a[0]);
      continue;
    }

    for(i = 1, pn = sn = 0; i <= MX; ++i){
      if(!c[i][0]) continue;
      if(c[i][0] == 2) p[pn][0] = i, p[pn][1] = c[i][1], p[pn++][2] = c[i][2];
      else s[sn][0] = i, s[sn++][1] = c[i][1];
    }

    for(bn = i = j = 0; bn < N;){
      v.clear();
      if((sn-j)&1){ // {1,3,5..}s
        if(sn-j > 1){ // {3,5,7..}s
          if(pn-i == 1){ // 1p{3,5,7..}s
            v.pb(p[i][0]), v.pb(p[i][0]), v.pb(s[j][0]), v.pb(s[j+1][0]);
            v.pb(s[j+2][0]), fill(v), ++i, j += 3;
          }else // {2+}p{3,5,7..}s
            v.pb(s[j][0]), v.pb(s[j+1][0]), v.pb(s[j+2][0]), fill(v), j += 3;

        }else if(pn-i == 3){ // 3p1s
          v.pb(p[i][0]), v.pb(p[i][0]), v.pb(p[i+1][0]), v.pb(p[i+1][0]);
          v.pb(p[i+2][0]), v.pb(p[i+2][0]), v.pb(s[j][0]), fill(v), i += 3, ++j;
        }else{ // {2,4+}p1s
          v.pb(p[i][0]), v.pb(p[i][0]), v.pb(p[i+1][0]), v.pb(p[i+1][0]);
          v.pb(s[j][0]), fill(v), i += 2, ++j;
        }

      }else if((pn-i)&1){ // {1,3,5..}p{0,2,4..}s
        if(pn-i > 1){ // {3,5,7..}p{0,2,4..}s
          v.pb(p[i][0]), v.pb(p[i][0]), v.pb(p[i+1][0]), v.pb(p[i+1][0]);
          v.pb(p[i+2][0]), v.pb(p[i+2][0]), fill(v), i += 3;
        }else{ // 1p{2,4,6..}s
          v.pb(p[i][0]), v.pb(p[i][0]), v.pb(s[j][0]), v.pb(s[j+1][0]);
          fill(v), ++i, j += 2;
        }

      }else if(sn-j){ // {0,2,4..}p{2,4,6..}s
        v.pb(s[j][0]), v.pb(s[j+1][0]), fill(v), j += 2;
      }else if(pn-i){ // {2,4,6..}p0s
        v.pb(p[i][0]), v.pb(p[i][0]), v.pb(p[i+1][0]), v.pb(p[i+1][0]);
        fill(v), i += 2;
      }
    }

    printf("%d\n", N);
    for(i = 0; i < bn; ++i) printf("%d ", b[i]);
    printf("\n");
  }
  return 0;
}

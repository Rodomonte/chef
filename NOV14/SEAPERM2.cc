// SEAPERM2

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int N,Q[301][300];
vector<vector<int> > vv;

vector<int> rf(int i, vector<bool> vf, vector<int> vr){
  bool f1,f2,f3;
  int j,k,n;
  vector<bool> vfn;
  vector<int> vrn;

  if(i <= N){
    for(j = 0; j < vv[i].size(); ++j){
      n = vv[i][j];
      if(vf[n])
        continue;
      vfn = vf, vrn = vr;
      vfn[n] = true;
      vrn.pb(n);
      vrn = rf(i+1, vfn, vrn);
      if(!vrn.empty())
        return vrn;
    }
    return vrn;
  }

  f1 = true;
  for(i = 1; i <= N; ++i)
    vf[i] = false;
  for(i = 1; i <= N; ++i){
    vrn = vr;
    for(j = 1; j <= N; ++j)
      if(vrn[j] > vrn[i])
        --vrn[j];
    vrn.erase(vrn.begin() + i);
    f2 = false;
    for(j = 1; j <= N; ++j){
      if(vf[j])
        continue;
      f3 = true;
      for(k = 1; k < N; ++k){
        if(vrn[k] != Q[j][k]){
          f3 = false;
          break;
        }
      }
      if(f3){
        vf[j] = f2 = true;
        break;
      }
    }
    if(!f2){
      f1 = false;
      break;
    }
  }
  if(!f1)
    vr.clear();
  return vr;
}

int main(){
  int T, i,j,k,a,b,c,d;
  vector<bool> vf;
  vector<int> vr;
  T = getn();
  while(T--){
    N = getn();
    for(i = 1; i <= N; ++i)
      for(j = 1; j < N; ++j)
        Q[i][j] = getn();

    vv.clear();
    vector<int> v0;
    vv.pb(v0);
    for(i = 1; i <= N; ++i){
      vector<int> v;
      for(j = 1; j <= N; ++j){
        a = b = c = d = 0;
        for(k = 1; k <= N; ++k){
          if(i > 1){
            if(Q[k][i-1] == j-1)
              ++a;
            else if(Q[k][i-1] == j)
              ++b;
          }
          if(Q[k][i] == j-1)
            ++c;
          else if(Q[k][i] == j)
            ++d;
        }
        if(a+c >= j-1 && b+d >= N-j && a+b >= i-1 && c+d >= N-i)
          v.pb(j);
      }
      vv.pb(v);
    }

    vf.clear();
    for(i = 0; i <= N; ++i)
      vf.pb(false);
    vr.clear();
    vr.pb(0);
    vr = rf(1, vf, vr);

    for(i = 1; i <= N; ++i)
      printf("%d ", vr[i]);
    printf("\n");
  }
  return 0;
}

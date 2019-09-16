// CHFNFRN

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char a[1001][1001];
int main(){
  int T,N,M,X,Y, i,j,k, f,g;
  vector<int> e,t,u,v, qu,qv;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 1; i <= N; ++i) for(j = 1; j <= N; ++j) a[i][j] = 0;
    while(M--) X = getn(), Y = getn(), a[X][Y] = a[Y][X] = 1;

    e.clear(), u.clear(), v.clear();
    for(i = 1, f = 0; i < N; ++i){
      for(j = i+1; j <= N; ++j) if(!a[i][j]){ f = 1; break; }
      if(f) break;
    }
    if(!f || N < 3){ printf("YES\n"); continue; }
    u.pb(i), v.pb(j);

    for(i = 1; i <= N; ++i){
      if(i == u[0] || i == v[0]) continue;
      for(j = 0, f = 1; j < u.size(); ++j) if(!a[i][u[j]]){ f = 0; break; }
      for(j = 0, g = 1; j < v.size(); ++j) if(!a[i][v[j]]){ g = 0; break; }

      if(!f && !g) break;
      if(f && g){ e.pb(i); continue; }
      if(f) qu.pb(i);
      else qv.pb(i);

      while(!qu.empty() || !qv.empty()){
        t.clear();
        if(!qu.empty()){
          j = qu.back(), qu.pop_back(), u.pb(j);
          for(k = 0; k < qu.size(); ++k) if(!a[j][qu[k]]){ f = g = 0; break; }
          for(k = 0; k < e.size(); ++k)
            if(!a[j][e[k]]) qv.pb(e[k]); else t.pb(e[k]);
        }else{
          j = qv.back(), qv.pop_back(), v.pb(j);
          for(k = 0; k < qv.size(); ++k) if(!a[j][qv[k]]){ f = g = 0; break; }
          for(k = 0; k < e.size(); ++k)
            if(!a[j][e[k]]) qu.pb(e[k]); else t.pb(e[k]);
        }
        e = t;
      }
      if(!f && !g) break;
    }

    while(!e.empty()){
      qu.pb(e.back()), e.erase(e.begin()+e.size()-1);
      while(!qu.empty() || !qv.empty()){
        t.clear();
        if(!qu.empty()){
          j = qu.back(), qu.pop_back(), u.pb(j);
          for(k = 0; k < qu.size(); ++k) if(!a[j][qu[k]]){ f = g = 0; break; }
          for(k = 0; k < e.size(); ++k)
            if(!a[j][e[k]]) qv.pb(e[k]); else t.pb(e[k]);
        }else{
          j = qv.back(), qv.pop_back(), v.pb(j);
          for(k = 0; k < qv.size(); ++k) if(!a[j][qv[k]]){ f = g = 0; break; }
          for(k = 0; k < e.size(); ++k)
            if(!a[j][e[k]]) qu.pb(e[k]); else t.pb(e[k]);
        }
        e = t;
      }
    }

    printf((f || g) ? "YES\n" : "NO\n");
  }
  return 0;
}

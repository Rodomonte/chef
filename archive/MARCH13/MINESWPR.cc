// MINESWPR

#include <stdio.h>
#include <vector>

using std::vector;

struct G {
  int m;
  vector<int> lv;
  G(int m0): m(m0) {}
};

int main(){
  char c;
  int N,M,K, i,j,k,ii, x=1,y=1, l, uc;
  float mp=0;
  G *g, *g2;
  vector<int> nv;
  scanf("%d %d %d",&N,&M,&K);
  vector<G*> gv[N][N], *v;
  bool u[N][N], f;
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      u[i][j] = true;
  while(M > 0){
    uc = 0;
    for(i = 0; i < N; i++)
      for(j = 0; j < N; j++)
        if(u[j][i])
          uc++;
    if(K >= uc){
      for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
          if(u[j][i])
            printf("N %d %d\n",j,i);
      break;
    }
    if(mp < .9){
      printf("S %d %d\n",x,y);
      fflush(stdout);
      scanf(" %c",&c);
    }
    u[x][y] = false;
    if(c == 'M'){
      K--;
      M--;
      printf("N %d %d\n",x,y);
      for(i = 0; i < gv[x][y].size(); i++){
        g = gv[x][y].at(i);
        if(g->m == 1){
          for(j = 0; j < g->lv.size(); j++){
            l = g->lv.at(j);
            if(x != l%N || y != l/N){
              v = &gv[l%N][l/N];
              for(k = 0; k < v->size(); k++){
                g2 = v->at(k);
                if(g2 != g){
                  for(ii = 0; ii < g2->lv.size(); ii++)
                    if(g2->lv.at(ii) == l)
                      break;
                  g2->lv.erase(g2->lv.begin() + ii);
                }
              }
              u[l%N][l/N] = false;
              v->clear();
            }
          }
        }else{
          for(j = 0; j < g->lv.size(); j++)
            if(g->lv.at(j) == y*N+x)
              break;
          g->lv.erase(g->lv.begin() + j);
          --g->m;
        }
      }
      gv[x][y].clear();
    }else{
      nv.clear();
      if(c == '0') nv.push_back(y*N+x);
      if(x > 0 && y > 0 && u[x-1][y-1]) nv.push_back((y-1)*N+x-1);
      if(y > 0 && u[x][y-1]) nv.push_back((y-1)*N+x);
      if(x < N - 1 && y > 0 && u[x+1][y-1]) nv.push_back((y-1)*N+x+1);
      if(x < N - 1 && u[x+1][y]) nv.push_back(y*N+x+1);
      if(x < N - 1 && y < N - 1 && u[x+1][y+1]) nv.push_back((y+1)*N+x+1);
      if(y < N - 1 && u[x][y+1]) nv.push_back((y+1)*N+x);
      if(x > 0 && y < N - 1 && u[x-1][y+1]) nv.push_back((y+1)*N+x-1);
      if(x > 0 && u[x-1][y]) nv.push_back(y*N+x-1);
      if(c != '0') g = new G(c-48);
      for(i = 0; i < nv.size(); i++){
        l = nv.at(i);
        if(c == '0'){
          u[l%N][l/N] = false;
          for(j = 0; j < gv[l%N][l/N].size(); j++){
            g = gv[l%N][l/N].at(j);
            for(k = 0; k < g->lv.size(); k++){
              if(g->lv.at(k) == l){
                g->lv.erase(g->lv.begin() + k);
                break;
              }
            }
          }
          gv[l%N][l/N].clear();
        }else{
          g->lv.push_back(l);
          gv[l%N][l/N].push_back(g);
        }
      }
      if(c != '0'){
        for(i = 0; i < gv[x][y].size(); i++){
          g = gv[x][y].at(i);
          for(j = 0; j < g->lv.size(); j++)
            if(g->lv.at(j) == y*N+x)
              break;
          g->lv.erase(g->lv.begin() + j);
        }
        gv[x][y].clear();
      }
    }
    f = false;
    for(i = 1; i < N - 1; i++){
      for(j = 1; j < N - 1; j++){
        if(u[j-1][i-1] && u[j][i-1] && u[j+1][i-1]
          && u[j+1][i] && u[j+1][i+1] && u[j][i+1]
          && u[j-1][i+1] && u[j-1][i] && u[j][i]){
          x = j, y = i;
          f = true;
          break;
        }
      }
      if(f) break;
    }
    if(!f){
      for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
          if(u[j][i] && !gv[j][i].size()){
            x = j, y = i;
            f = true;
            break;
          }
        }
        if(f) break;
      }
    }
    if(!f){
      mp = 0;
      for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
          if(u[j][i]){
            for(k = 0; k < gv[j][i].size(); k++){
              g = gv[j][i].at(k);
              if((float)g->m / (float)g->lv.size() > mp){
                mp = (float)g->m / (float)g->lv.size();
                x = j, y = i;
              }
            }
          }
        }
      }
      if(mp > .9) c = 'M';
    }
  }
  printf("Done\n");
  fflush(stdout);
  return 0;
}

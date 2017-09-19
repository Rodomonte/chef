// FIRESC

#include <stdio.h>
#include <vector>

using std::vector;

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N,n, M, i,j, r, w,wi,wo;
  while(T--){
    vector<vector<int>*> v;
    vector<int> *vn,*vi,*vj;
    N = getn(), M = getn();
    int a[N+1];
    for(n = 1; n <= N; n++) a[n] = -1;
    while(M--){
      i = getn(), j = getn();
      if(a[i] < 0){
        if(a[j] < 0){
          a[i] = v.size(), a[j] = v.size();
          vn = new vector<int>();
          vn->push_back(i);
          vn->push_back(j);
          v.push_back(vn);
        }else{
          a[i] = a[j];
          v[a[j]]->push_back(i);
        }
      }else{
        if(a[j] < 0){
          a[j] = a[i];
          v[a[i]]->push_back(j);
        }else if(a[i] == a[j])
          continue;
        else{
          vi = v[a[i]], vj = v[a[j]];
          if(vi->size() < vj->size()){
            for(n = 0; n < vi->size(); n++){
              a[vi->at(n)] = a[j];
              vj->push_back(vi->at(n));
            }
            vi->clear();
          }else{
            for(n = 0; n < vj->size(); n++){
              a[vj->at(n)] = a[i];
              vi->push_back(vj->at(n));
            }
            vj->clear();
          }
        }
      }
    }
    r = 0, w = 1;
    for(n = 1; n <= N; n++)
      if(a[n] < 0)
        r++;
    for(n = 0; n < v.size(); n++){
      if(v[n]->size() > 0){
        r++;
        wo = w;
        for(wi = 1; wi < v[n]->size(); wi++){
          w += wo;
          if(w >= 1000000007) w-= 1000000007;
        }
      }
    }
    printf("%d %d\n",r,w);
  }
  return 0;
}

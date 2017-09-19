// CHEFWORD

#include <stdio.h>
#include <string.h>
#include <string>
#include <set>

std::set<std::string> s;

int min(int a, int b){
  return (a < b) ? a : b;
}

int main(){
  char S[4], a[16],b[16], f;
  int T,N,K, i,j,k,l;
  double x[26][26], y[26][26], z[26][26], p,r;
  std::set<std::string>::iterator it;

  scanf("%d", &T);
  while(T--){
    scanf("%d %d\n%s", &N, &K, S);
    for(i = 0; i < 26; ++i){
      for(j = 0; j < 26; ++j){
        scanf("%lf", x[i]+j);
        y[i][j] = x[i][j];
      }
    }
    l = strlen(S);
    s.clear();
    for(i = 0; i < N; ++i){
      scanf("%s", a);
      if(strlen(a) == l)
        s.insert(a);
    }

    for(k = 0; k < min(K-1, 100); ++k){
      for(i = 0; i < 26; ++i){
        for(j = 0; j < 26; ++j){
          z[i][j] = 0.0;
          for(l = 0; l < 26; ++l)
            z[i][j] += y[i][l] * x[l][j];
        }
      }
      for(i = 0; i < 26; ++i)
        for(j = 0; j < 26; ++j)
          y[i][j] = z[i][j];
      if(f)
        break;
    }

    r = 0.0;
    for(it = s.begin(); it != s.end(); ++it){
      p = 1.0, l = strlen(S);
      for(i = 0; i < l; ++i)
        p *= y[S[i]-'a'][(*it)[i]-'a'];
      r += p;
    }
    printf("%.8lf\n", r);
  }
  return 0;
}

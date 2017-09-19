// WSITES01

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>

using std::sort;
using std::string;
using std::vector;

#define pb push_back

struct P {
  char a;
  bool b,u,e;
  int p,c[26];
  P(): b(false), u(false), e(false), p(-1) {
    for(int i = 0; i < 26; ++i)
      c[i] = -1;
  }
};

char s[200001], sb[200001], sr[200001];
P a[200000];
int main(){
  char c,f;
  int N, i,j,k,n,an;
  vector<string> v;

  scanf("%d", &N);
  an = 1, f = 0;
  for(i = 0; i < N; ++i){
    scanf("%s %s", sb, s);
    n = strlen(s), c = sb[0];
    if(a[0].c[s[0]-'a'] == -1)
      a[0].c[s[0]-'a'] = an++, a[a[0].c[s[0]-'a']].p = 0;
    k = a[0].c[s[0]-'a'];
    for(j = 0; j < n; ++j){
      a[k].a = s[j];
      if((j == n-1 || a[k].e) && (a[k].b && c == '+'))
        f = 1;
      a[k].e = (j == n-1 && !a[k].u && !a[k].b) ? true : false;
      if(c == '+')
        a[k].u = true;
      else
        a[k].b = true;
      if(j < n-1){
        if(a[k].c[s[j+1]-'a'] == -1)
          a[k].c[s[j+1]-'a'] = an++, a[a[k].c[s[j+1]-'a']].p = k;
        k = a[k].c[s[j+1]-'a'];
      }
    }
  }
  if(f){
    printf("-1\n");
    return 0;
  }

  for(i = 0; i < an; ++i){
    if(a[i].b && a[i].u && a[i].e){
      printf("-1\n");
      return 0;
    }
    if(!a[i].b || a[i].u || !a[i].e)
      continue;
    for(j = i, k = -1; j && a[j].b && !a[j].u; k = j, j = a[j].p);
    sr[0] = a[k].a;
    for(k = 1; j; j = a[j].p, ++k)
      sr[k] = a[j].a;
    for(j = 0; j < k; ++j)
      sb[k-j-1] = sr[j];
    sb[k] = 0;
    v.pb(string(sb));
  }

  sort(v.begin(), v.end());
  n = v.size();
  for(i = 1; i < v.size(); ++i)
    if(v[i] == v[i-1])
      --n;

  printf("%d\n", n);
  if(!v.empty())
    printf("%s\n", v[0].c_str());
  for(i = 1; i < v.size(); ++i)
    if(v[i] != v[i-1])
      printf("%s\n", v[i].c_str());
  return 0;
}

// SPELL

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back

const char cf[] = "etaoinshrdlcumwfgypbvkjxqz";
const int NCA = 1;

unordered_map<string, int> d;
unordered_map<string, int>::iterator it;
char b[12000000];
char* r[6000000];
int bn,rn;

char* fix(char* s, char* w){
  if(d.find(s) != d.end())
    return s;
  char c;
  int i,j, l = strlen(s), m = 0;
  string ms = "";

  // Insertion
  for(i = 0; i < l; ++i){
    c = s[i];
    if(c < 'a' || c > 'z')
      return s;
    string t(s, i);
    t += string(s+i+1);
    it = d.find(t);
    if(it != d.end() && it->second > m)
      m = it->second, ms = t;
  }

  // Swap
  for(i = 0; i < l-1; ++i){
    for(j = i+1; j < l; ++j){
      c = s[i], s[i] = s[j], s[j] = c;
      string t(s);
      it = d.find(t);
      if(it != d.end() && it->second > m)
        m = it->second, ms = t;
      c = s[i], s[i] = s[j], s[j] = c;
    }
  }

  // Replacement
  if(l <= 2){
    for(i = 0; i < l; ++i){
      c = s[i];
      for(j = 0; j < NCA; ++j){
        s[i] = cf[j];
        string t(s);
        it = d.find(t);
        if(it != d.end() && it->second > m)
          m = it->second, ms = t;
      }
      s[i] = c;
    }
  }

  if(m){
    for(i = 0; i < ms.size(); i++)
      w[i] = ms[i];
    w[i] = '\0';
    return w;
  }
  return s;
}

int main(){
  int D, i,j;
  char w[128], c, *p;
  scanf("%d\n", &D);
  while(D--){
    scanf("%s\n", w);
    d[w] = 0;
  }
  bn = rn = i = 0;
  while(1){
    c = gc();
    if(c == ' ' || c == '\n'){
      b[bn++] = '\0';
      r[rn++] = b+i;
      string s(b+i);
      it = d.find(s);
      if(it != d.end())
        ++it->second;
      if(c == '\n')
        break;
      i = bn;
      continue;
    }
    b[bn++] = c;
  }
  for(i = 0; i < rn; i++){
    p = fix(r[i], w);
    c = p[0], j = 0;
    while(c != '\0'){
      pc(c);
      c = p[++j];
    }
    pc(' ');
  }
  pc('\n');
  return 0;
}

// CHEFBATL

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using std::vector;
using std::multiset;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct P {
  int i,j;
  P(int i0, int j0): i(i0), j(j0) {}
};

char _a[] =
"#........#"
"#........#"
"#.#......."
"..#......#"
"#.#......#"
"#.#......."
"#........#"
"..#......."
"#........."
"#.#......#";
int ss[] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};

bool av[11][11];
char a[11][11], b[11][11];
int c[11][11];

multiset<int> rem(){
  int i,j,k,t;
  multiset<int> s;
  multiset<int>::iterator si;

  for(i = 0; i < 10; ++i)
    s.insert(ss[i]);
  for(i = 1; i <= 10; ++i)
    for(j = 1; j <= 10; ++j)
      av[i][j] = false;

  for(i = 1; i <= 10; ++i){
    for(j = 1; j <= 10; ++j){
      if(av[i][j] || b[i][j] != 'x')
        continue;
      t = 1;
      for(k = i-1; k >= 1 && b[k][j] == 'x'; --k)
        ++t;
      for(k = i+1; k <= 10 && b[k][j] == 'x'; ++k)
        ++t, av[k][j] = true;
      for(k = j-1; k >= 1 && b[i][k] == 'x'; --k)
        ++t;
      for(k = j+1; k <= 10 && b[i][k] == 'x'; ++k)
        ++t, av[i][k] = true;
      si = s.find(t);
      if(si != s.end())
        s.erase(si);
    }
  }
  return s;
}

void prob(){
  bool f;
  int i,j,k,l,t;
  multiset<int> s;
  multiset<int>::iterator si;

  for(i = 1; i <= 10; ++i)
    for(j = 1; j <= 10; ++j)
      c[i][j] = 0;
  s = rem();
  for(l = 1; l <= 4; ++l){
    for(t = 0, si = s.begin(); si != s.end(); ++si)
      if(*si == l)
        ++t;
    if(!t)
      continue;

    for(i = 1; i <= 10; ++i){
      for(j = 1; j <= 10; ++j){
        if(b[i][j] != '.')
          continue;
        if(i+l-1 <= 10){
          for(k = i, f = true; k < i+l; ++k)
            if(b[k][j] != '.')
              f = false;
          if(f)
            for(k = i; k < i+l; ++k)
              c[k][j] += t;
        }

        if(j+l-1 <= 10){
          for(k = j, f = true; k < j+l; ++k)
            if(b[i][k] != '.')
              f = false;
          if(f)
            for(k = j; k < j+l; ++k)
              c[i][k] += t;
        }
      }
    }
  }
}

void tar(int& i, int& j){
  int m;
  if(i > 1 && b[i-1][j] == 'x'){
    if(i > 2 && b[i-2][j] == 'x'){
      if(i > 3 && b[i-3][j] == '.'){
        i -= 3;
        return;
      }else if(i < 10 && b[i+1][j] == '.'){
        ++i;
        return;
      }
    }else if(i > 2 && b[i-2][j] == '.'){
      i -= 2;
      return;
    }else if(i < 10 && b[i+1][j] == '.'){
      ++i;
      return;
    }
  }

  if(i < 10 && b[i+1][j] == 'x'){
    if(i < 9 && b[i+2][j] == 'x'){
      if(i < 8 && b[i+3][j] == '.'){
        i += 3;
        return;
      }else if(i > 1 && b[i-1][j] == '.'){
        --i;
        return;
      }
    }else if(i < 9 && b[i+2][j] == '.'){
      i += 2;
      return;
    }else if(i > 1 && b[i-1][j] == '.'){
      --i;
      return;
    }
  }

  if(j > 1 && b[i][j-1] == 'x'){
    if(j > 2 && b[i][j-2] == 'x'){
      if(j > 3 && b[i][j-3] == '.'){
        j -= 3;
        return;
      }else if(j < 10 && b[i][j+1] == '.'){
        ++j;
        return;
      }
    }else if(j > 2 && b[i][j-2] == '.'){
      j -= 2;
      return;
    }else if(j < 10 && b[i][j+1] == '.'){
      ++j;
      return;
    }
  }

  if(j < 10 && b[i][j+1] == 'x'){
    if(j < 9 && b[i][j+2] == 'x'){
      if(j < 8 && b[i][j+3] == '.'){
        j += 3;
        return;
      }else if(j > 1 && b[i][j-1] == '.'){
        --j;
        return;
      }
    }else if(j < 9 && b[i][j+2] == '.'){
      j += 2;
      return;
    }else if(j > 1 && b[i][j-1] == '.'){
      --j;
      return;
    }
  }

  prob(), m = -1;
  if(i > 1 && c[i-1][j] > m)
    m = c[i-1][j];
  if(i < 10 && c[i+1][j] > m)
    m = c[i+1][j];
  if(j > 1 && c[i][j-1] > m)
    m = c[i][j-1];
  if(j < 10 && c[i][j+1] > m)
    m = c[i][j+1];

  if(i > 1 && c[i-1][j] == m)
    --i;
  else if(i < 10 && c[i+1][j] == m)
    ++i;
  else if(j > 1 && c[i][j-1] == m)
    --j;
  else if(j < 10 && c[i][j+1] == m)
    ++j;
}

int main(){
  int T,R,N,X,Y, i,j,k,m,hi,hj,ti,tj,ii,jj,ni,nj;
  multiset<int> s;
  multiset<int>::iterator si;

  for(T = 1; T <= 100; ++T){
    for(i = 1, k = 0; i <= 10; ++i)
      for(j = 1; j <= 10; ++j, ++k)
        a[i][j] = _a[k], b[i][j] = '.';
    printf("1\n");
    for(i = 1; i <= 10; ++i){
      for(j = 1; j <= 10; ++j)
        printf("%c", a[i][j]);
      printf("\n");
    }

    hi = hj = -1;
    while(1){
      if(hi != -1){
        i = hi, j = hj;
        tar(i, j);
      }else{
        prob();
        for(ii = 1, m = 0; ii <= 10; ++ii)
          for(jj = 1; jj <= 10; ++jj)
            if(c[ii][jj] > m)
              m = c[ii][jj], ti = ii, tj = jj;
        i = ti, j = tj;
      }
      printf("%d %d\n", i, j);
      fflush(stdout);

      R = getn();
      if(R == 1 || R == 5){
        b[i][j] = '0';
        N = getn();
        for(k = 0; k < N; ++k)
          X = getn(), Y = getn(), a[X][Y] = (a[X][Y] == '#') ? 'x' : '0';
      }
      if(R == 2){
        if(hi == -1)
          hi = i, hj = j;
        b[i][j] = 'x';
      }
      if(R == 3){
        hi = hj = -1, b[i][j] = 'x', ti = ii = i, tj = jj = j;
        while(ti > 1 && b[ti][j] == 'x') --ti;
        while(tj > 1 && b[i][tj] == 'x') --tj;
        while(ii < 10 && b[ii][j] == 'x') ++ii;
        while(jj < 10 && b[i][jj] == 'x') ++jj;
        for(ni = ti; ni <= ii; ++ni)
          for(nj = tj; nj <= jj; ++nj)
            if(b[ni][nj] == '.')
              b[ni][nj] = '0';
      }
      if(R == 4 || R == 5)
        break;

        /*
      printf("\nb:\n");
      for(ii = 1; ii <= 10; ++ii){
        for(jj = 1; jj <= 10; ++jj)
          printf("%c", b[ii][jj]);
        printf("\n");
      }

      s = rem();
      printf("\ns: {");
      for(si = s.begin(); si != s.end(); ++si)
        printf("%d ", *si);
      printf("}\n");

      prob();
      printf("\nc: {\n");
      for(ii = 1; ii <= 10; ++ii){
        for(jj = 1; jj <= 10; ++jj)
          printf("%2d ", c[ii][jj]);
        printf("\n");
      }
      */

    }
  }

  printf("0\n");
  return 0;
}

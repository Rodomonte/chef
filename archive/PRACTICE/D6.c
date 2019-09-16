// D6
 
#include <stdio.h>
 
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}
 
#define pc putchar_unlocked
char pb[10];
int pi;
inline void putn(int n){
  if(!n) pc('0');
  pi = 0;
  while(n)
    pb[pi++] = (n) + '0', n /= 10;
  while(pi)
    pc(pb[--pi]);
}
 
int main(){
  char s[101][101];
  int T = getn(),N, i,j, x[500],y[500], a,b,c,d,dx,dy,n,r;
  while(T--){
    for(i = 0; i <= 100; i++)
      for(j = 0; j <= 100; j++)
        s[i][j] = 0;
    N = getn(), r = 0;
    for(i = 0; i < N; i++){
      x[i] = getn()+50, y[i] = getn()+50;
      s[x[i]][y[i]] = 1;
    }
    for(i = 0; i < N-1; i++){
      a = x[i], b = y[i];
      for(j = i+1; j < N; j++){
        c = x[j], d = y[j];
        dx = a>c ? a-c : c-a;
        if(b == d){
          n = b + dx;
          if(n < 101 && s[a][n] && s[c][n])
            r++;
        }else{
          dy = b>d ? b-d : d-b;
          if(a<c && b>d && a+dy<101 && b+dx<101 && s[a+dy][b+dx]
              && c+dy<101 && d+dx<101 && s[c+dy][d+dx])
            r++;
          else if(a>c && b<d && d+dx<101 && c+dy<101 && s[c+dy][d+dx]
              && a+dy<101 && b+dx<101 && s[a+dy][b+dx])
            r++;
        }
      }
    }
    putn(r);
    pc('\n');
  }
  return 0;
}
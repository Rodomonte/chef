// SSTORY

#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
#define alloc(n) sa_mem + sa_mem_ptr; sa_mem_ptr += n
#define dealloc(n) sa_mem_ptr -= n
#define leq2(a1,a2,b1,b2) (a1<b1 || a1==b1 && a2<=b2)
#define leq3(a1,a2,a3,b1,b2,b3) (a1<b1 || a1==b1 && leq2(a2,a3,b2,b3))
#define sa_i() (sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2)

int sa_mem[3000224], sa_mem_ptr=0;

void sa_radix(int* a, int* b, int* r, int n, int K){
  int i, *c;
  c = alloc(K+2);
  for(i = 0; i <= K; i++)
    c[i] = 0;
  for(i = 0; i < n; i++)
    c[r[a[i]]+1]++;
  for(i = 0; i < K; i++)
    c[i+1] += c[i];
  for(i = 0; i < n; i++)
    b[c[r[a[i]]]++] = a[i];
  dealloc(K+2);
}

void sa_gen(int* s, int* sa, int n, int K){
  int n0,n1,n2,n02, *s0,*sa0,*s12,*sa12, i,j,k,p,t,u,c0,c1,c2;
  n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
  s0 = alloc(n0), sa0 = alloc(n0);
  s12 = alloc(n02+3), sa12 = alloc(n02+3);
  s12[n02] = s12[n02+1] = s12[n02+2] = 0;
  sa12[n02] = sa12[n02+1] = sa12[n02+2] = 0;
  u = 0, c0 = c1 = c2 = -1;
  for(i = j = 0; i < n+(n0-n1); i++)
    if(i%3)
      s12[j++] = i;
  sa_radix(s12, sa12, s+2, n02, K);
  sa_radix(sa12, s12, s+1, n02, K);
  sa_radix(s12, sa12, s, n02, K);
  for(i = 0; i < n02 && u < n02; i++){
    if(s[sa12[i]] != c0 || s[sa12[i]+1] != c1 || s[sa12[i]+2] != c2)
      u++, c0 = s[sa12[i]], c1 = s[sa12[i]+1], c2 = s[sa12[i]+2];
    if(sa12[i]%3 == 1)
      s12[sa12[i]/3] = u;
    else
      s12[sa12[i]/3+n0] = u;
  }
  if(u < n02){
    sa_gen(s12, sa12, n02, u);
    for(i = 0; i < n02; i++)
      s12[sa12[i]] = i+1;
  }else{
    for(i = 0; i < n02; i++)
      sa12[s12[i]-1] = i;
  }
  for(i = j = 0; i < n02; i++)
    if(sa12[i] < n0)
      s0[j++] = sa12[i]*3;
  sa_radix(s0, sa0, s, n0, K);
  for(p = k = 0, t = n0-n1; k < n; k++){
    i = sa_i(), j = sa0[p];
    if((sa12[t] < n0 && leq2(s[i], s12[sa12[t]+n0], s[j], s12[j/3])) ||
        (sa12[t] >= n0 && leq3(s[i], s[i+1], s12[sa12[t]-n0+1], s[j],
        s[j+1], s12[j/3+n0]))){
      sa[k] = i, t++;
      if(t == n02)
        for(k++; p < n0; p++, k++)
          sa[k] = sa0[p];
    }else{
      sa[k] = j, p++;
      if(p == n0)
        for(k++; t < n02; t++, k++)
          sa[k] = sa_i();
    }
  }
  dealloc(n0+n0+n02+n02+6);
}

int s[500004], sa[500004], lcp[500004], rank[500004];

void lcp_gen(int n){
  int i,j,k;
  for(i = 0; i < n; i++)
    rank[sa[i]] = i;
  for(k = i = 0; i < n; i++){
    if(k > 0)
      k--;
    if(rank[i] == n-1){
      lcp[n-1] = -1;
      k = 0;
      continue;
    }
    j = sa[rank[i]+1];
    while(s[i+k] == s[j+k])
      k++;
    lcp[rank[i]] = k;
  }
}

int min(int a, int b){
  return (a < b) ? a : b;
}
int max(int a, int b){
  return (a > b) ? a : b;
}

int main(){
  char c,mf;
  int i,m,n,r,ri,nm;
  m = 0;
  while((c=gc()) != '\n')
    s[m++] = c;
  n = m;
  s[n++] = '#';
  while((c=gc()) != '\n')
    s[n++] = c;
  s[n] = s[n+1] = s[n+2] = 0;
  sa[n] = sa[n+1] = sa[n+2] = 0;
  sa_gen(s, sa, n, 256);
  lcp_gen(n);
  r = mf = 0, ri = nm = n;
  for(i = 1; i < n-1; i++)
    if(lcp[i] > r && min(sa[i],sa[i+1]) < m && max(sa[i],sa[i+1]) > m)
      r = lcp[i];
  for(i = 1; i < n-1; i++){
    if(lcp[i] < r){
      if(mf && nm < ri)
        ri = nm;
      mf = 0, nm = n;
      continue;
    }
    if(min(sa[i],sa[i+1]) < m)
      mf = 1;
    if(sa[i] > m && sa[i] < nm)
      nm = sa[i];
    if(sa[i+1] > m && sa[i+1] < nm)
      nm = sa[i+1];
  }
  if(mf && nm < ri)
    ri = nm;
  if(r){
    for(i = ri; i < ri+r; i++)
      pc(s[i]);
    printf("\n%d\n",r);
  }else
    printf("0\n");
  return 0;
};

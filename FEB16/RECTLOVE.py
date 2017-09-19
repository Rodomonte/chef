# RECTLOVE

def rect(x, y):
  return x * (x+1) * y * (y+1) // 4

T = int(input())
while T != 0:
  T -= 1
  (N,M,K) = (int(n) for n in input().split(' '))
  a = [int(n)-1 for n in input().split(' ')]
  r = 0
  for n in a:
    i = n // M + 1
    j = n % M + 1
    r += rect(N,M) - rect(i-1,M) - rect(N,M-j) - rect(N-i,M) - rect(N,j-1) \
         + rect(i-1,j-1) + rect(i-1,M-j) + rect(N-i,M-j) + rect(N-i,j-1)
  print('%.8f' % (r/rect(N,M)))

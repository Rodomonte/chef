# ENCODING

MOD = 1000000007

def madd(a, b): return a + b - MOD if a + b >= MOD else a + b
def msub(a, b): return a - b + MOD if a - b < 0 else a - b
def mmul(a, b): return a * b % MOD

def fn(n):
  if n < 10: return n * (n+1) // 2
  s = '00' + str(n)
  N = len(s)

  e = [0 for i in range(N)]
  e[N-1] = 1
  for i in range(N-2, -1, -1):
    e[i] = mmul(e[i+1], 10)

  e2 = [0 for i in range(N)]
  e2[N-1] = 1
  for i in range(N-2, -1, -1):
    e2[i] = mmul(e2[i+1], 100)

  a = [0 for i in range(len(s)+1)]
  a[N-1] = int(s[N-1])
  for i in range(N-2, -1, -1):
    a[i] = madd(mmul(int(s[i]), e[i]), a[i+1])

  b = [0 for i in range(len(s))]
  b[0] = int(s[0])
  for i in range(1, N):
    b[i] = madd(mmul(b[i-1], 10), int(s[i]))

  r = 0
  for i in range(N-1, 1, -1):
    d = int(s[i-1])
    for j in range(1, d):
      r = madd(r, mmul(mmul(madd(b[i-2], 1), j), e2[i]))
    if d < int(s[i]):
      r = madd(r, mmul(mmul(madd(b[i-2], 1), d), e2[i]))
    elif d >= int(s[i]):
      r = madd(r, mmul(mmul(b[i-2], d), e2[i]))
    if d == int(s[i]):
      r = madd(r, mmul(mmul(madd(a[i+1], 1), d), e[i]))
    for j in range(d+1, 10):
      r = madd(r, mmul(mmul(b[i-2], j), e2[i]))

  t = n if n % 2 == 1 else n // 2
  u = n + 1 if (n + 1) % 2 == 1 else (n + 1) // 2
  return msub(mmul(t % MOD, u % MOD), r)

T = int(input())
while T > 0:
  tok = input().split(' ')
  L = int(tok[1])
  tok = input().split(' ')
  R = int(tok[1])

  print(msub(fn(R), fn(L-1)))
  T -= 1

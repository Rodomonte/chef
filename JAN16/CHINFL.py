# CHINFL

class A:
  def __init__(s, p2di, d2p, p, d):
    (s.p2di, s.d2p, s.p, s.d) = (p2di, d2p, p, d)
    (s.p2d, s.ip2di, s.id2p, s.pa, s.da) = (1/p2di, int(p2di), int(d2p), 2, 1)
class B:
  def __init__(s, i, j, f):
    (s.i, s.j, s.f, s.n, s.d) = (i, j, f, 1, 1)

def pmax(a, b):
  return a if (a[0] > b[0]) else b
def r1():
  print('Quintillionnaire')
  exit()

(N, M, D) = (int(t) for t in input().split(' '))
df = float(D)
a = [[] for i in range(M)]
for j in range(N):
  k = [float(t) for t in input().split(' ')]
  for i in range(0,M<<1,2):
    a[i>>1] += [A(k[i], k[i+1], 1, 1)]
  (a[0][j].p, a[0][j].d) = (df, df * a[0][j].p2d)

qf = float(10**18+10**6)
for i in range(1,M):
  for j in range(N):
    p = pmax((a[i-1][j].d * a[i][j].d2p, 1), (a[i-1][j].p, 2))
    d = pmax((a[i-1][j].p * a[i][j].p2d, 1), (a[i-1][j].d, 2))
    if j != 0:
      (p, d) = (pmax(p, (a[i-1][j-1].p, 3)), pmax(d, (a[i-1][j-1].d, 3)))
    if j != N-1:
      (p, d) = (pmax(p, (a[i-1][j+1].p, 4)), pmax(d, (a[i-1][j+1].d, 4)))
    if p[0] > qf or d[0] > qf:
      r1()
    (a[i][j].p, a[i][j].pa, a[i][j].d, a[i][j].da) = (p[0], p[1], d[0], d[1])

b = [B(M-1, 0, True), B(M-1, 0, False)]
for j in range(1,N):
  b[0].j = j if (a[M-1][j].p > a[M-1][b[0].j].p) else b[0].j
  b[1].j = j if (a[M-1][j].d > a[M-1][b[1].j].d) else b[1].j
for i in range(2):
  while b[i].i >= 0:
    t = a[b[i].i][b[i].j]
    c = t.pa if b[i].f else t.da
    b[i].n = (b[i].n * t.id2p) if (c == 1 and b[i].f) else b[i].n
    b[i].d = (b[i].d * t.ip2di) if (c == 1 and (not b[i].f)) else b[i].d
    b[i].f = (not b[i].f) if (c == 1) else b[i].f
    b[i].i -= 1
    b[i].j = b[i].j if (c < 3) else ((b[i].j - 1) if (c == 3) else (b[i].j + 1))
  b[i].n *= D

from decimal import *
getcontext().prec = 32
q = Decimal(10) ** Decimal(18)
d = Decimal(b[1].n) / Decimal(b[1].d)
p = Decimal(b[0].n) / Decimal(b[0].d)
if d > q or p > q:
  r1()
print('%.8f' % p)

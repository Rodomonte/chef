# CODECRCK

from math import *
from decimal import *

getcontext().prec = 200

args1 = input().split(' ')
args2 = input().split(' ')
I = int(args1[0])
K = int(args1[1])
S = Decimal(args1[2])
A = Decimal(args2[0])
B = Decimal(args2[1])

s2 = Decimal(2.0)**Decimal(0.5)
s6 = Decimal(6.0)**Decimal(0.5)
a1 = s2*(A+B) - s6*(A-B)
af1 = a1 / A
b1 = s2*(A-B) + s6*(A+B)
bf1 = b1 / B
a2 = s2*(a1+b1) - s6*(a1-b1)
af2 = a2 / a1
b2 = s2*(a1-b1) + s6*(a1+b1)
bf2 = b2 / b1

d2 = Decimal(2.0)
ak = A
bk = B
if K >= I:
  p = Decimal((K-I)//2)
  s = S
  c = 0
  while fabs(p) > 1.0 or fabs(s) > 1.0:
    p /= d2
    s /= d2
    c += 1
  c2 = Decimal(2**c)
  ak *= ((af1*af2)**p / d2**s) ** c2
  bk *= ((bf1*bf2)**p / d2**s) ** c2
  if (K-I) % 2 == 1:
    ak *= af1
    bk *= bf1
else:
  p = Decimal((I-K)//2)
  s = S
  c = 0
  while fabs(p) > 1.0 or fabs(s) > 1.0:
    p /= d2
    s /= d2
    c += 1
  c2 = Decimal(2**c)
  ak /= ((af1*af2)**p * d2**s) ** c2
  bk /= ((bf1*bf2)**p * d2**s) ** c2
  if (I-K) % 2 == 1:
    ak /= af2
    bk /= bf2

getcontext().prec = 16

if fabs(ak+bk) < 0.001:
  print(0)
else:
  print(ak+bk)

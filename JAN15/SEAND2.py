# SEAND2

from random import randint

T = int(input())
for TI in range(T):
  A = input()
  N = int(input())
  B = []
  inp = input().split(' ')
  for n in inp:
    B += [int(n)]
  mr = 10**9
  r = 0
  for ii in range(500 if len(A) > 100 else 2000):
    A2 = int(A)
    tr = 0
    for k in range(N):
      tr += A2 % B[k]
    if tr < mr:
      mr = tr
      r = A2
    i = randint(0, len(A)-2)
    j = randint(i+1, len(A)-1)
    A = A[:i] + A[j] + A[i+1:j] + A[i] + A[j+1:]
  print(r)

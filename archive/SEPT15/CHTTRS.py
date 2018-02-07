# CHTTRS

# 0:Prod 1:Dbg 2:Test
mode = 0
g = 100

from random import randint

# width height pv rot pbot
S = [[[4, 1, [[0,0],[0,1],[0,2],[0,3]], 'a', [0,1,2,3], []], \
      [1, 4, [[0,0],[1,0],[2,0],[3,0]], 'b', [3], []]], \
     [[3, 2, [[0,0],[1,0],[1,1],[1,2]], 'a', [1,2,3], [0]], \
      [2, 3, [[0,1],[1,1],[2,0],[2,1]], 'b', [2,3], [1]], \
      [2, 3, [[0,0],[0,1],[1,0],[2,0]], 'c', [1,3], [0,1]], \
      [3, 2, [[0,0],[0,1],[0,2],[1,2]], 'd', [0,1,3], [2]]], \
     [[3, 2, [[0,2],[1,0],[1,1],[1,2]], 'a', [1,2,3], [2]], \
      [2, 3, [[0,0],[1,0],[2,0],[2,1]], 'b', [2,3], [0]], \
      [3, 2, [[0,0],[0,1],[0,2],[1,0]], 'c', [1,2,3], [0]], \
      [2, 3, [[0,0],[0,1],[1,1],[2,1]], 'd', [0,3], [0,1]]], \
     [[2, 2, [[0,0],[0,1],[1,0],[1,1]], 'a', [2,3], [0,1]]], \
     [[3, 2, [[0,1],[0,2],[1,0],[1,1]], 'a', [1,2,3], [1]], \
      [2, 3, [[0,0],[1,0],[1,1],[2,1]], 'b', [1,3], [0,1]]], \
     [[3, 2, [[0,1],[1,0],[1,1],[1,2]], 'a', [1,2,3], [1]], \
      [2, 3, [[0,0],[1,0],[1,1],[2,0]], 'b', [2,3], [0]], \
      [3, 2, [[0,0],[0,1],[0,2],[1,1]], 'c', [0,2,3], [1]], \
      [2, 3, [[0,1],[1,0],[1,1],[2,1]], 'd', [1,3], [1]]], \
     [[3, 2, [[0,0],[0,1],[1,1],[1,2]], 'a', [0,2,3], [1]], \
      [2, 3, [[0,1],[1,0],[1,1],[2,0]], 'b', [2,3], [0,1]]]]

a = [[0 for i in range(15)] for j in range(15)]

def clr(i, pv):
  t = 0
  for j in range(15):
    if a[i][j] == 1:
      t += 1
  for p in pv:
    if p[0] == i:
      t += 1
  if t == 15:
    return True
  return False

def move(s):
  mv = []
  for j in range(16-s[0]):
    for i in range(16-s[1]):
      f = False
      for p in s[2]:
        if a[p[0]+i][p[1]+j] == 1:
          f = True
      if f:
        i -= 1
        break
    if i == 16-s[1]:
      i -= 1
    if i == -1:
      continue
    pv = []
    for p in s[2]:
      pv += [[p[0]+i, p[1]+j]]

    v = i
    d = 0
    e = 0
    for pi in s[4]:
      o = 0
      for t in range(pv[pi][0]+1, 15):
        if a[t][pv[pi][1]] == 1:
          break
        o += 1
        if s[2][pi][1] in s[5]:
          e += 1
      d += o*o
    v -= 20*d
    c = 0
    for t in range(i, i+s[1]):
      c += clr(t, s[2])
    if c > 0 and e == 0:
      v = 20*c

    m = [s[3], i+s[1]-1, j, v, pv]
    mv += [m]
  return mv

def play():
  score = 0
  while True:
    # Input
    T = 0
    F = 0
    R = ''
    if mode > 0:
      T = 2 if randint(0,4) == 0 else 1
      F = 1 + randint(0,6)
      if T == 2:
        if F == 1 or F == 5 or F == 7:
          R = chr(ord('a') + randint(0,1))
        elif F == 2 or F == 3 or F == 6:
          R = chr(ord('a') + randint(0,3))
        else:
          R = 'a'
      if mode == 1:
        print(T,F,R)
    else:
      inp = input().split(' ')
      if inp[0] == 'Game':
        break
      T = int(inp[0])
      F = int(inp[1])
      if T == 2:
        R = inp[2]

    # Score moves
    mv = []
    if T == 1:
      for s in S[F-1]:
        mv += move(s)
    else:
      mv += move(S[F-1][ord(R)-ord('a')])

    # Pick best move
    v = -1000000
    mb = []
    for m in mv:
      if m[3] > v:
        v = m[3]
        mb = m
    if v == -1000000:
      break
    score += 1

    # Output
    if mode < 2:
      print(mb[0], mb[1]+1, mb[2]+1)

    # Mark move
    for p in mb[4]:
      a[p[0]][p[1]] = 1;

    # Clear rows
    c = 0
    for i in range(15):
      if not clr(i, []):
        continue
      c += 1
      for t in range(i, 0, -1):
        for j in range(15):
          a[t][j] = a[t-1][j]
      for j in range(15):
        a[0][j] = 0
    score += 10*c*c

    # Print board
    if mode == 1:
      for i in range(15):
        print('|', end='')
        for j in range(15):
          print('x' if a[i][j] == 1 else ' ', end='')
        print('|')
      print('-----------------\n')
      input()

  if mode < 2:
    print('e 0 0')
  return score

if mode < 2:
  play()
else:
  s = 0
  for i in range(g):
    a = [[0 for i in range(15)] for j in range(15)]
    s += play()
  print(g,'games: Avg score',s/g)

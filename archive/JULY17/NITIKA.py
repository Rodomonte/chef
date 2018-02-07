# NITIKA

T = int(raw_input())
for ti in range(T):
  tok = raw_input().split(' ')
  r = ''
  if len(tok) == 1:
    r += tok[0][0].upper()
    for i in range(1, len(tok[0])):
      r += tok[0][i].lower()
  elif len(tok) == 2:
    r += tok[0][0].upper() + '. '
    r += tok[1][0].upper()
    for i in range(1, len(tok[1])):
      r += tok[1][i].lower()
  elif len(tok) == 3:
    r += tok[0][0].upper() + '. '
    r += tok[1][0].upper() + '. '
    r += tok[2][0].upper()
    for i in range(1, len(tok[2])):
      r += tok[2][i].lower()
  print r

# FACTORIZ

def main():
  MAX = 65000 +1
  sieve = [True for i in range(MAX)]
  primes = []
  for i in range(2, MAX):
    if sieve[i] == False:
      continue;
    primes += [i]
    for j in range(i+i, MAX, i):
      sieve[j] = False

  T = int(input())
  for TI in range(T):
    N = int(input())
    r = []
    pm = len(primes)
    for pi in range(pm):
      p = primes[pi]
      while N % p == 0:
        r += [p]
        N //= p
    if N != 1:
      r += [N]
    print(len(r))
    for f in r:
      print(f)

main()

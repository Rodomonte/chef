# LEBALONS
 
def epc(d):
    r = [0, 1, 0]
    for i in range(len(d)):
        p = r[0]
        for j in range(1,len(r)):
            t = r[j]
            r[j] = p + t * d[i]
            p = t
        r += [0]
    r = r[1:-1]
    r.reverse()
    return r
 
def main():
    T = int(input())
    while T > 0:
        line = input().split(' ')
        N = int(line[0])
        M = int(line[1])
        n = {}
        d = {}
        for i in range(N):
            line = input().split(' ')
            C = int(line[0])
            P = int(line[1])
            if C in n:
                n[C] += P
                d[C] = (d[C]+1)*2-1
            else:
                n[C] = P
                d[C] = 1
        K = len(n)
        for c in n:
            n[c] = n[c] * (d[c] - ((d[c]+1)/2-1)) / d[c]
        b = [[],[]]
        d0 = []
        dp = 1
        for c in d:
            b[0] += [0]
            b[1] += [d[c]]
            d0 += [d[c]]
            dp *= d[c]
        e0 = epc(d0)
        for m in range(2,K+1):
            b += [[]]
        for i in range(len(d0)):
            d1 = []
            for j in range(i):
                d1 += [d0[j]]
            for j in range(i+1,len(d0)):
                d1 += [d0[j]]
            e1 = epc(d1)
            for m in range(2,K):
                b[m] += [e0[m] - e1[m]]
            b[-1] += [dp]
        n0 = []
        for c in n:
            n0 += [n[c]]
        rn = 0
        rd = 0
        for i in range(M,K+1):
            rd += e0[i]
            for j in range(K):
                rn += n0[j] * b[i][j]
        print('%.8f'%(rn/rd))
        T -= 1
 
main()

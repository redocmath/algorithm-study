def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b)

def lcm(a, b):
    if a < b: return a*b//gcd(b, a)
    return a*b//gcd(a,b)

n, c = [int(e) for e in input().split()]
a = []

for i in range(n):
    a.append(int(input()))

su = 0
for i in a:
    su += c // i

if (len(a) != 1):
    lc = lcm(a[0], a[1])
    for i in range(2, len(a)-2):
        lc = lcm(lc, a[i])
    su -= c // lc

print(su)

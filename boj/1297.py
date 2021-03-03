from math import floor

a = [int(e) for e in input().split()]
tmp = ((a[0] ** 2) / (a[1] ** 2 + a[2] ** 2)) ** (1/2)
print(floor(tmp * a[1]), floor(tmp * a[2]))

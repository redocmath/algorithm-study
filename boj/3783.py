from decimal import *

getcontext().rounding = ROUND_HALF_DOWN
getcontext().prec = 1000

t = int(input())
for i in range(t):
    n = Decimal(input())
    n = n ** (Decimal('1.0') / Decimal('3.0'))
    a = str(round(n, 100))
    print(a[:list(a).index('.')+11])

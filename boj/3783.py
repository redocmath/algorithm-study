# not working
from decimal import *

getcontext().rounding = ROUND_HALF_DOWN
getcontext().prec = 1000

t = int(input())
for i in range(t):
    tmp = str(int(input()))
    n = Decimal(input())
    n = n ** (Decimal('1.0') / Decimal('3.0'))
    print(str(round(n, 101))[:12])


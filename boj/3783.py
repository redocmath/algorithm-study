from decimal import *

getcontext().prec = 1000

t = int(input())
for i in range(t):
    n = Decimal(input().rstrip() + ".0000000000")
    n = Decimal(n ** (Decimal('1.0') / Decimal('3.0')))
    n = round(n, 500)
    n = n.quantize(Decimal("0.0000000001"), rounding=ROUND_DOWN)
    print(n)

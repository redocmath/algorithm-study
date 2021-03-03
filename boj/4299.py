a, b = [int(e) for e in input().split()]
if ((a + b) % 2 == 1 or (a + b) % 2 == 1): print("-1")
else: 
    a = (a+b)//2
    b = (a-b)//2
    if (a > b): print(a, b)
    else: print(b, a)

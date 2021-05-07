# C++ should adopt Big Integer
def e_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = e_gcd(b, a%b)
    return g, y, x-(a//b)*y
 
 
a, b, S = [int(e) for e in input().split()]
if a == 0 and b == 0:
    if S == 0: print("YES")
    else: print("NO")
elif a == 0:
    if S % b == 0: print("YES")
    else: print("NO")
elif b == 0:
    if S % a == 0: print("YES")
    else: print("NO")
else:
    g, x, y = e_gcd(a, b)
    if S % g:
        print("NO")
    else:
        x *= S // g
        y *= S // g
        # Similar algorithm with Euclidean Algorithm
        for k in range(-g*x//b+1, g*y//a+1):
            tmp, _, _ = e_gcd(x + k*b//g, y - k*a//g)
            if tmp == 1:
                print("YES")
                exit()
        print("NO")

a = [int(e) for e in input().split()]
a.sort()
x,y,z=a
if x == y and y == z:
    print(10000+1000*x)
elif x == y:
    print(1000+100*x)
elif y == z:
    print(1000+100*z)
else:
    print(100*z)

a = input()
if (a.find('x') == -1):
    print(0)
elif (a[0] == 'x'):
    print(1)
elif (a[0] == '-' and a[1] == 'x'):
    print(-1)
else:
    print(a[:a.find('x')])

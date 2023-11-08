import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
x = []
y = []
s = []

for i in range(N):
    inp = [int(e) for e in input().split()]
    x.append(inp[0])
    y.append(inp[1])

s = [int(e) for e in input().split()]

direction = [0,0,0,0]

for i in range(N):
    if abs(x[i]-s[0]) <= y[i]-s[1]:
        direction[0] = 1
    if abs(y[i]-s[1]) <= x[i]-s[0]:
        direction[1] = 1
    if abs(x[i]-s[0]) <= -y[i]+s[1]:
        direction[2] = 1
    if abs(y[i]-s[1]) <= -x[i]+s[0]:
        direction[3] = 1

if (direction.count(0)): print("YES")
else: print("NO")

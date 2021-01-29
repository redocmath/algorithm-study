a = [int(e) for e in input().split()]
b = [1, 1, 2, 2, 2, 8]

for i in range(6):
    print(b[i] - a[i], end=" ")

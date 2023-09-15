n = int(input())

def get(x, y, size):
    if (size == 1): return '*'
    if (size/3 <= x < 2*size/3 and size/3 <= y < 2*size/3):
        return ' '
    return get(x%(size/3), y%(size/3), size/3)

for i in range(0, n):
    for j in range(0, n):
        print(get(i,j,n), end="")
    print()

m,n,h = [int(e) for e in input().split()]
dpos = [(-1,0,0),(1,0,0),(0,-1,0),(0,1,0),(0,0,-1),(0,0,1)]
tomatoes = []
queue = []
left = 0
for i in range(h):
    box = []
    for j in range(n):
        row = [int(e) for e in input().split()]
        for k in range(m):
            if (row[k] == 1): queue.append((i,j,k))
            elif (row[k] == 0): left += 1
        box.append(row)
    tomatoes.append(box)

count = 0
while len(queue) > 0:
    tmp = queue.copy()
    queue.clear()
    for searching in tmp:
        for dp in dpos:
            target = tuple(map(lambda i, j: i+j, searching, dp))
            if (target[0] < 0 or target[0] >= h
                or target[1] < 0 or target[1] >= n
                or target[2] < 0 or target[2] >= m
                or tomatoes[target[0]][target[1]][target[2]] != 0):
                continue
            tomatoes[target[0]][target[1]][target[2]] = 1
            queue.append(target)
            left -= 1
    count += 1

if left != 0: print(-1)
else: print(count-1)
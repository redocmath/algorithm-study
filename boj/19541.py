import sys
input = sys.stdin.readline
print = sys.stdout.write

N, M = [int(e) for e in input().split()]
meeting_info = []
for i in range(M):
    inp = [int(e)-1 for e in input().split()]
    meeting_info.append(inp[1:])

init_status = [int(e) for e in input().split()]
status = init_status.copy()

for i in reversed(range(M)):
    isinfected = 1
    for idx in meeting_info[i]:
        if (not status[idx]):
            isinfected = 0
            break
    
    if (isinfected): continue
    for idx in meeting_info[i]: status[idx] = 0

init = status.copy()

for i in range(M):
    isinfected = 0
    for idx in meeting_info[i]:
        if (init[idx]):
            isinfected = 1
            break
    
    if (not isinfected): continue
    for idx in meeting_info[i]:
        init[idx] = 1

if (init == init_status):
    print("YES\n")
    for e in status: print(str(e) + " ")
else:
    print("NO")

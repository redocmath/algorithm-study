n = int(input())
s = input()
q = int(input())

for i in range(q):
    t, a, b = [int(e) for e in input().split()]
    if t == 1:
        tmp = list(s)[a-1]
        sss = list(s)
        sss[a-1] = sss[b-1]
        sss[b-1] = tmp
        s = ''.join(sss)
    else:
        sa = s[:n]
        sb = s[n:]
        s = sb + sa

print(s)

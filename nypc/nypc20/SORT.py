# solved 00:01:32
a = input()
idx = 0
for e in list(a):
    if (e == "S"):
        idx += 1
    else:
        idx += 4 - (idx % 4)

print(idx)

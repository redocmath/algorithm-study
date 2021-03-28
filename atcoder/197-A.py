s = list(input())
tmp = s[0]
s[0] = s[1]
s[1] = s[2]
s[2] = tmp
print(''.join(s))

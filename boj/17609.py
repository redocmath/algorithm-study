def isPal(s):
	for i in range(len(s) // 2):
		if s[i] != s[len(s) - i - 1]:
			return False
	return True

def pal(s):
	for i in range(len(s) // 2):
		if s[i] != s[len(s) - i - 1]:
			sc = list(s)
			del sc[i]
			if isPal(''.join(sc)):
				return 1
			else:
				sc = list(s)
				del sc[len(s) - i - 1]
				if isPal(''.join(sc)):
					return 1
				else:
					return 2
	return 0

n = int(input())
li = [input() for i in range(n)]

for listt in li:
    print(pal(listt))

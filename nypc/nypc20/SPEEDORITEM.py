# solved 00:03:17

t = int(input())
for i in range(t):
    a = [int(e) for e in input().split()]
    team1 = a[:4]
    team2 = a[4:]
    if(max(team1) > max(team2)):
        if (sum(team1) > sum(team2)):
            print("R")
        else:
            print("I")
    elif (sum(team1) > sum(team2)):
        if (max(team1) > max(team2)):
            print("R")
        else:
            print("S")
    else:
        print("R")

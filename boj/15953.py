for i in range(int(input())):
    a, b = [int(x) for x in input().split(' ')]
    sum = 0

    if a == 0 or a > 21:
        pass
    elif a == 1:
        sum += 5000000
    elif a <= 3:
        sum += 3000000
    elif a <= 6:
        sum += 2000000
    elif a <= 10:
        sum += 500000
    elif a <= 15:
        sum += 300000
    else:
        sum += 100000
    
    if b == 0 or b > 31:
        pass
    elif b == 1:
        sum += 5120000
    elif b <= 3:
        sum += 2560000
    elif b <= 7:
        sum += 1280000
    elif b <= 15:
        sum += 640000
    else:
        sum += 320000
    
    print(sum)
    
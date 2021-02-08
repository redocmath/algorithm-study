while True:
    stri = list(input())
    if stri == ['0']: break
    
    isPal = True
    for j in range(int(len(stri) / 2)):
        if (stri[j] != stri[len(stri) - j - 1]):
            isPal = False
            break
    
    if isPal:
        print("yes")
    else:
        print("no")

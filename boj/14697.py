def proc():
    inp = input()
    A = int(inp.split(' ')[0])
    B = int(inp.split(' ')[1])
    C = int(inp.split(' ')[2])
    N = int(inp.split(' ')[3])
    isnotPos = True

    for i in range((N // A) + 1):
        for j in range(((N - i * A) // B) + 1):
            for k in range(((N - i * A - j * B) // C) + 1):
                if i * A + j * B + k * C == N:
                    if isnotPos:
                        print("1", end="")
                    isnotPos = False

    if isnotPos:
        print("0")


if __name__ == '__main__':
    proc()
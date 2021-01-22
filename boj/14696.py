def proc():
    N = int(input())

    for i in range(N):
        pattern_a = {"star": 0, "circle": 0, "square": 0, "triangle": 0}
        pattern_b = {"star": 0, "circle": 0, "square": 0, "triangle": 0}

        a = input()
        a_count = int(a.split(' ')[0])

        for j in range(1, a_count + 1):
            if int(a.split(' ')[j]) == 4:
                pattern_a["star"] += 1
            elif int(a.split(' ')[j]) == 3:
                pattern_a["circle"] += 1
            elif int(a.split(' ')[j]) == 2:
                pattern_a["square"] += 1
            else:
                pattern_a["triangle"] += 1

        b = input()
        b_count = int(b.split(' ')[0])

        for j in range(1, b_count + 1):
            if int(b.split(' ')[j]) == 4:
                pattern_b["star"] += 1
            elif int(b.split(' ')[j]) == 3:
                pattern_b["circle"] += 1
            elif int(b.split(' ')[j]) == 2:
                pattern_b["square"] += 1
            else:
                pattern_b["triangle"] += 1

        if pattern_a["star"] > pattern_b["star"]:
            print("A")
            continue
        elif pattern_a["star"] < pattern_b["star"]:
            print("B")
            continue
        else:
            if pattern_a["circle"] > pattern_b["circle"]:
                print("A")
                continue
            elif pattern_a["circle"] < pattern_b["circle"]:
                print("B")
                continue
            else:
                if pattern_a["square"] > pattern_b["square"]:
                    print("A")
                    continue
                elif pattern_a["square"] < pattern_b["square"]:
                    print("B")
                    continue
                else:
                    if pattern_a["triangle"] > pattern_b["triangle"]:
                        print("A")
                        continue
                    elif pattern_a["triangle"] < pattern_b["triangle"]:
                        print("B")
                        continue
                    else:
                        print("D")

if __name__ == '__main__':
    proc()
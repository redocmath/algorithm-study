# solved 00:04:53 
t1 = [int(e) for e in input().split(":")]
t1_ret = t1[0] * 6000 + t1[1] * 100 + t1[0]
t2 = [int(e) for e in input().split(":")]
t2_ret = t2[0] * 6000 + t2[1] * 100 + t2[0]
t3 = [int(e) for e in input().split(":")]
t3_ret = t3[0] * 6000 + t3[1] * 100 + t3[0]

t = int(input())
for i in range(t):
    tmp = [int(e) for e in input().split(":")]
    tmp_ret = tmp[0] * 6000 + tmp[1] * 100 + tmp[2]
    if (tmp_ret <= t3_ret):
        print("***")
    elif (tmp_ret <= t2_ret):
        print("**")
    elif (tmp_ret <= t1_ret):
        print("*")
    else:
        print(":(")

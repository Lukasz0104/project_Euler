def check(num):
    c = num
    s = 0
    while (c):
        s = s + c%10
        c = c//10
    if (s==1):
        return False
    while (num>1 and num%s==0):
        num = num/s
    return (num==1)


UPPER = 70

print(list(filter(lambda x: x>9 and check(x), sorted(set([a**b for a in range(2,UPPER+1) for b in range(2,UPPER+1)]))))[29])
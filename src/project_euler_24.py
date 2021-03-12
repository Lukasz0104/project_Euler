from itertools import permutations as p
print(int(''.join(sorted(p("0123456789"))[1000000-1])))
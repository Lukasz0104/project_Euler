with open(".\\data\\p022_names.txt",'r') as f:
    c = f.read().split('\n')

c = sorted(c)

def worth(name):
    r = 0
    for letter in name:
        r += ord(letter)-ord('A')+1
    return r
print(worth("COLIN"))
print(sum([worth(x)*(i+1) for i,x in enumerate(c)]))
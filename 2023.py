caseNumber = {'A' : 1, 'B' : 2, 'D' : 3, 'G' : 3, 'J': 3, \
        'P' : 1, 'O' : 1, 'M' : 2, 'K' : 3, \
        'R' : 1, 'S' : 2, 'T' : 3, 'W' : 3}
s = 0
n = int(raw_input())
p = 1
for i in range(1, n):
    name = raw_input()[0]
    pp = caseNumber[name]
    s += abs(pp - p)
    p = pp
print s



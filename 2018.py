n,a,b = (int(x) for x in raw_input().split(' '))

sa = [0 for i in range (a)]
sb = [0 for i in range (b)]
sa[0] = 1
sb[0] = 1
ssa = 1
ssb = 1
ss = ssa + ssb
for k in range(1,n):
    osa = sa[k%a]
    osb = sb[k%b]
    sa[k%a] = ssb
    sb[k%b] = ssa
    ssa = (ss - osa) %1000000007
    ssb = (ss - osb) %1000000007
    ss = ssa + ssb
print ss % 1000000007

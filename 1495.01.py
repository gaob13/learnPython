n = int(raw_input())
u = {0}
for p in range(30):
    uu = set() 
    for e in u:
        uu.add((e + 10 ** p) % n)
        uu.add((e + 10 ** p * 2) % n)
    if 0 in uu:
        print p
    u = uu
print False
    
def dp(p, u):
    if p >= 30 return ''
    uu = set()
    for e in u:
        r = e + 10 ** p) % n
        if r == 0:
            return '1'
        uu.add(r)
        r = e + 10 ** p * 2) % n
        if r == 0:
            return '2'
        uu.add(r)
        child = dp(p + 1, uu)
        if child == '' :
            return ''
        
            
    

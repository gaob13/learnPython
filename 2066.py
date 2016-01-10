a = []
o = ['+', '-', '*']
ans = 1e9
for i in range(0,3):
    a.append(raw_input())
for i in range(0,3):
    o1 = o[i]
    for j in range(0,3):
        o2 = o[j]
        e = eval(a[0] + o1 + a[1] + o2 + a[2])
        ans = min(e, ans)
print ans
        

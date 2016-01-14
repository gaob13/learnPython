n = int(raw_input())
base = [[pow(10,i)%n for i in range(30)], [pow(10,i)*2%n for i in range(0,30)]]
maps = []
m = {base[1][0]:2, base[0][0]:1}
maps.append(m)
for i in range(1,30):
    if 0 in m.keys():
        break
    m = {(base[1][i] + x)%n:2 for x in maps[-1].keys()}
    for x in maps[-1].keys():
        m[(base[0][i] + x)%n] = 1
    maps.append(m)
#print(maps)
if not 0 in maps[len(maps) - 1].keys():
    print 'Impossible'
    exit()
an = ''
v = 0
for i in range(len(maps) - 1, -1, -1):
    k = maps[i][v]
    an = an + str(k)
    v = (v - k * pow(10, i)) % n
print an
    
    


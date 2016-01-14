n,k = (int(x) for x in raw_input().split(' '))

a = [[0 for i in range(n)]]
for i in range(n - 1):
    b = [int(x) for x in raw_input().split(' ')]
    b.reverse()
    a.append(b)

parquet = [[0 for j in range (n)] for i in range(n)]

for j in range(n):
    s = 0
    for i in range(1, n - j):
        s += a[i][j]
        parquet[i][j] = parquet[i][j - 1] + s

dp = [[0 for i in range(k+1)]]
dpr = [["" for i in range(k+1)] for j in range(n)]
for i in range(1, n):
    b = [0]
    for j in range(1,k+1):
        m = 0
        for u in range(i):
            s = dp[u][j - 1]
            #s += sum(a[t][k] for t in range(u + 1,i + 1) for k in range(n - i))
            #s += sua[i][u]
            s += parquet[i][n - i - 1] - parquet[u][n - i - 1]
            if s > m:
                dpr[i][j] = dpr[u][j - 1] + ' ' + str(i)
                m = s
        b.append(m)
    dp.append(b)

ans = 0
anss = ''
for i in range(n):
    if dp[i][k] > ans:
        ans = dp[i][k]
        anss = dpr[i][k]

print(ans)
print(anss[1:])

#print(m)
#print(dp)
#print(dpr)
#for i in range(n - 1):

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
long long dp[501][501];
int dpr[501][501];

void showStack(int u, int d) {
    stack<int> stack;
    while(d > 0)
    {
        stack.push(u);
        u = dpr[u][d --];
    }
    while(! stack.empty())
    {
        u = stack.top();
        stack.pop();
        printf("%d ", u);
    }

//    if (d <= 0)
//    {
//        return;
//    }
//    else
//    {
//        showStack(dpr[u][d], d - 1);
//        printf("%d ", u);
//    }
}


int main() {
    int n, k;
    cin >> n >> k;
    long long a[501][501];
    long long parquet[501][501];
    long long s = 0;
    long long m = 0;
    for (int j = 0; j < 501; j ++)
        parquet[0][j] = parquet[j][0] = a[0][j] = 0;
    for (int i = 1; i < n; ++ i)
    {
        for (int j = 0; j < n - i; ++ j)
        {
            cin >> a[i][n - j - i - 1];
        }
    }
    for (int j = 0; j < n; ++ j)
    {
        s = 0;
        for (int i = 1; i < n - j; ++ i)
        {
            s += a[i][j];
            parquet[i][j] = parquet[i][j - 1] + s;
        }
    }

//    for (int i = 0; i < n; i ++)
//    {
//        for (int j = 0; j < n; j ++)
//            printf("%d ", a[i][j]);
//        printf("\n");
//    }

    for (int j = 0; j < 501; j ++)
        dp[0][j] = 0;
    for (int i = 1; i < n; i ++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= min(k,i); j ++)
        {
            m = 0;
            for (int u = 0; u < i; u ++)
            {
                s = dp[u][j - 1] + parquet[i][n - i - 1] - parquet[u][n - i - 1];
                if (s > m)
                {
                    dpr[i][j] = u;
                    m = s;
                }
            }
            dp[i][j] = m;
        }
    }
    
    long long ans = 0;
    int pos = 0;
    for (int i = 0; i <= n; i ++)
    {
        if (dp[i][k] > ans)
        {
            ans = dp[i][k];
            pos = i;
        }
    }

    cout << ans << endl;
    showStack(dpr[pos][k], k - 1);
    printf("%d\n", pos);
    //cout << dpr[pos][k];

    return 0;
}


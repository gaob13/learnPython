#include <cstdio>  
#include <ctime>  
#include <cstdlib>  
#include <cstring>  
#include <queue>  
#include <string>  
#include <set>  
#include <stack>  
#include <map>  
#include <cmath>  
#include <vector>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
#define FF(i, a, b) for(int i = (a); i < (b); ++i)  
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)  
#define FD(i, b, a) for(int i = (b); i >= (a); --i)  
#define REP(i, N) for(int i = 0; i < (N); ++i)  
#define CLR(a, v) memset(a, v, sizeof(a))  
#define PB push_back  
#define MP make_pair  
  
typedef long long LL;  
const int INF = 0x3f3f3f3f;  
const int MAXN = 100010;  
  
int n, k;  
int c[510][510];  
int d[510][510];  
int dp[510][510];  
int path[510][510];  
  
void out(int i, int kk)  
{  
    if (kk) out(path[i][kk], kk - 1);  
    else return ;  
    if (kk != 1) printf(" ");  
    printf("%d", i);  
}  
int main ()  
{  
    int x;  
    while (~scanf("%d%d", &n, &k))  
    {  
        --n;  
        CLR(c, 0);  
        FE(i, 1, n)  
            for (int j = i; j <= n; j++)  
            {  
                scanf("%d", &x);  
                c[i][j] = c[i - 1][j] + x;  
            }  
        CLR(d, 0);  
        FE(i, 1, n) FD(j, i, 1)  
            FE(r, i, n)///!!!  
                d[j][i] += c[i][r] - c[j - 1][r];  
  
        CLR(dp, -1);//!!!  
        CLR(path, 0);  
        dp[0][0] = 0;  
        FE(i, 1, n) FE(kk, 1, min(k, i)) FE(j, 1, i)  
            if (dp[i][kk] < dp[j - 1][kk - 1] + d[j][i])  
            {  
                dp[i][kk] = dp[j - 1][kk - 1] + d[j][i];  
                path[i][kk] = j - 1;  
            }  
        int ans = -1;///!!!  
        int ansi = 0;  
        FE(i, k, n)  
            if(ans < dp[i][k])  
            {  
                ans = dp[i][k];  
                ansi = i;  
            }  
        printf("%d\n", ans);  
        out(ansi, k);  
        printf("\n");  
  
    }  
    return 0;  
}  

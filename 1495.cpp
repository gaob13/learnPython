#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

unsigned char k[30][1000000];

int main() {
    int n;
    scanf("%d", &n);
    long long base[2][30];
    base[0][0] = 1 % n;
    base[1][0] = 2 % n;
    for (int i = 1; i < 30; i ++)
    {
        base[0][i] = base[0][i - 1] * 10 % n;
        base[1][i] = base[1][i - 1] * 10 % n;
    }
    memset(k, 0, sizeof(k));
    k[0][2%n] = 2;
    k[0][1%n] = 1;
    int i = 0;
    for (i = 1; i < 30; i ++)
    {
        if(k[i - 1][0] != 0) 
        {
            break;
        }
        for (int j = 1; j < n; j ++)
        {
            if (k[i - 1][j] != 0)
            {
                k[i][(j + base[1][i]) % n] = 2;
            }
        }
        for (int j = 1; j < n; j ++)
        {
            if (k[i - 1][j] != 0)
            {
                k[i][(j + base[0][i]) % n] = 1;
            }
        }
    }
    if (i >= 30 && k[29][0] == 0)
    {
        printf("Impossible");
    }
    else 
    {
        long long v = 0;
        int key = 0;
        for (i = i - 1; i >= 0; i --)
        {
            key = k[i][v];
            printf("%d", key);
            v = ((long long)n * n + v - key * base[0][i]) % n;
        }
    }
    printf("\n");
    return 0;
}

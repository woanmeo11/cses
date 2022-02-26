// cses: Rectangle Cutting
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

int f[505][505];

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            if (i != j) {
                f[i][j] = 1e9;
                for (int k = 1; k < i; ++k)
                    f[i][j] = min(f[i][j], 1 + f[k][j] + f[i - k][j]);
                for (int k = 1; k < j; ++k)
                    f[i][j] = min(f[i][j], 1 + f[i][k] + f[i][j - k]);
            }
    printf("%d", f[a][b]);
}


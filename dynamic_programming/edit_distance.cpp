// cses: Edit Distance
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;

char a[MAX_N], b[MAX_N];
int f[MAX_N][MAX_N];

int main() {
    scanf("%s%s", a + 1, b + 1);

    int n = strlen(a + 1), m = strlen(b + 1);

    for (int i = 1; i <= n; ++i)
        f[i][0] = i;
    for (int j = 1; j <= m; ++j)
        f[0][j] = j;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = 1 + min({f[i - 1][j - 1], f[i][j - 1], f[i - 1][j]});
    printf("%d", f[n][m]);
}


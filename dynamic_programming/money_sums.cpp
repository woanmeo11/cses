// cses: Money Sums
// tags: dp
// huycon

#include <bits/stdc++.h>

int a[105];
bool f[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    f[0] = true;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 1e5; j >= a[i]; --j)
            if (!f[j] && f[j - a[i]]) {
                ++cnt;
                f[j] = true;
            }
    printf("%d\n", cnt);
    for (int i = 1; i <= 1e5; ++i)
        if (f[i])
            printf("%d ", i);
}


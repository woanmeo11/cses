// cses: Removal Game
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

long long dp[5005][5005];

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &dp[i][i]);
        sum += dp[i][i];
    }
    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j < n; ++j)
            dp[i][j] = max(dp[i][i] - dp[i + 1][j], dp[j][j] - dp[i][j - 1]);
    printf("%lld", (sum + dp[0][n - 1]) / 2);
}


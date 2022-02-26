// cses: Coin Combinations II
// tags: dp
// huycon

#include <bits/stdc++.h>

const int MAX_N = 105, MAX_VALUE = 1e6 + 5, MOD = 1e9 + 7;
int c[MAX_N], f[MAX_N][MAX_VALUE];

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);

	f[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= x; ++j) {
			f[i][j] = f[i - 1][j];
			if (j >= c[i])
				f[i][j] = (f[i][j] + f[i][j - c[i]]) % MOD;
		}

	printf("%d", f[n][x]);
}

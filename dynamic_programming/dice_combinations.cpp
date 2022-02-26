// cses: Dice Combinations
// tags: dp
// huycon

#include <bits/stdc++.h>

const int MAX_N = 1e6 + 5, MOD = 1e9 + 7;
int f[MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 6; ++j)
			if (i - j >= 0)
				f[i] = (f[i] + f[i - j]) % MOD;
			else
				break;
	printf("%d", f[n]);
}


// cses: Grid Paths
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
char a[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);

	if (a[1][1] == '*' || a[n][n] == '*') {
		putchar('0');
		return 0;
	}

	f[1][1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j] == '.')
				f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1]) % 1000000007;

	printf("%d", f[n][n]);
}

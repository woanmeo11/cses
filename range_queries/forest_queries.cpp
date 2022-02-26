// cses: Forest Queries
// tags: dp
// huycon

#include <bits/stdc++.h>

const int N = 1005;
int a[N][N];

int main() {
	int n, q;
	scanf("%d%d\n", &n, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			char c;
			scanf("%c\n", &c);
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (c == '*');
		}

	while (q--) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]);
	}
}

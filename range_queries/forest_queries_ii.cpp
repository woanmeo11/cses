// cses: Forest Queries II
// tags: bit
// huycon

#include <bits/stdc++.h>

const int N = 1005;
int f[N][N], a[N][N], n;

void update(int x, int y, int v) {
	while (x <= n) {
        int yy = y;
		while (yy <= n) {
			f[x][yy] += v;
			yy += yy & -yy;
		}
		x += x & -x;
	}
}

int get(int x, int y) {
	int res = 0;
	while (x > 0) {
		int yy = y;
		while (yy > 0) {
			res += f[x][yy];
			yy &= yy - 1;
		}
		x &= x - 1;
	}
	return res;
}

int main() {
	int q;
	scanf("%d%d\n", &n, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			char c;
			scanf("%c\n", &c);
			if (c == '*') {
				a[i][j] = 1;
				update(i, j, 1);
			}
		}

	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (a[x][y] == 1)
				update(x, y, -1);
			else
				update(x, y, 1);
			a[x][y] = 1 - a[x][y];
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1));
		}
	}
}

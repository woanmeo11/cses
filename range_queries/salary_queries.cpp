// cses: Salary Queries
// tags: bit
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int m, f[3 * N], a[N], b[3 * N];

struct query {
	int type, j, k;
} p[N];

void update(int i, int v) {
	while (i <= m) {
		f[i] += v;
		i += i & -i;
	}
}

int get(int i) {
	int res = 0;
	while (i > 0) {
		res += f[i];
		i &= i -1;
	}
	return res;
}

int pos(int x) {
	int low = 0, high = m;
	while (high - low > 1) {
		int mid = (low + high) >> 1;
		if (b[mid] <= x)
			low = mid;
		else
			high = mid;
	}
	return low + 1;
}

int main() {
	int n, q;
	scanf("%d%d\n", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d\n", a + i);
		b[m++] = a[i];
	}

	for (int i = 0; i < q; ++i) {
		char c;
		int j, k;
		scanf("%c%d%d\n", &c, &j, &k);
		p[i] = {c == '?', j, k};
		b[m++] = j;
		b[m++] = k;
	}

	sort(b, b + m);
	m = unique(b, b + m) - b;

	for (int i = 1; i <= n; ++i)
		update(pos(a[i]), 1);

	for (int i = 0; i < q; ++i) {
		int j = p[i].j, k = p[i].k;
		if (p[i].type) {
			int u = pos(j), v = pos(k);
			printf("%d\n", get(v) - get(u - 1));
		}
		else {
			int u = pos(a[j]), v = pos(k);
			a[j] = k;
			update(u, -1);
			update(v, 1);
		}
	}
}

// cses: Hotel Queries
// tags: segment tree
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t[4 * N], a[N];

void build(int p, int l, int r) {
	if (l == r) {
		t[p] = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);

	t[p] = max(t[p << 1], t[p << 1 | 1]);
}

int process(int p, int l, int r, int x) {
	if (t[p] < x)
		return 0;

	if (l == r) {
		t[p] -= x;
		return l;
	}

	int mid = (l + r) >> 1, res;
	if (t[p << 1] >= x)
		res = process(p << 1, l, mid, x);
	else
		res = process(p << 1 | 1, mid + 1, r, x);

	t[p] = max(t[p << 1], t[p << 1 | 1]);
	return res;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	build(1, 1, n);

	while (m--) {
		int x;
		scanf("%d", &x);
		int idx = process(1, 1, n, x);
		printf("%d ", idx);
	}
}

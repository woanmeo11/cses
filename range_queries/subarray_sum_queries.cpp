// cses: Subarray Sum Queries
// tags: segment tree
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int a[N];

struct node {
	ll sum, max_prefix, max_suffix, max_subarr;
} t[4 * N];

node combine(node a, node b) {
	ll sum = a.sum + b.sum;
	ll max_prefix = max(a.max_prefix, a.sum + b.max_prefix);
	ll max_suffix = max(b.max_suffix, b.sum + a.max_suffix);
	ll max_subarr = max(a.max_suffix + b.max_prefix, max(a.max_subarr, b.max_subarr));
	return {sum, max_prefix, max_suffix, max_subarr};
}

void build(int p, int l, int r) {
	if (l == r) {
		int x = max(0, a[l]);
		t[p] = {a[l], x, x, x};
		return;
	}

	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);

	t[p] = combine(t[p << 1], t[p << 1 | 1]);
}

void update(int p, int l, int r, int i, int x) {
	if (r < i || i < l)
		return;
	if (l == i && i == r) {
		int y = max(0, x);
		t[p] = {x, y, y, y};
		return;
	}

	int mid = (l + r) >> 1;
	update(p << 1, l, mid, i, x);
	update(p << 1 | 1, mid + 1, r, i, x);

	t[p] = combine(t[p << 1], t[p << 1 | 1]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	build(1, 1, n);

	while (m--) {
		int k, x;
		scanf("%d%d", &k, &x);
		update(1, 1, n, k, x);
		printf("%lld\n", t[1].max_subarr);
	}
}

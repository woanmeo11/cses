// cses: Polynomial Queries
// tags: segment tree
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int N = 2e5 + 5;

int a[N];

struct node {
	ll sum, subtract, cnt;
} t[4 * N];

ll sum_range(int l, int r) {
	return 1LL * (r - l + 1) * (l + r) >> 1;
}

void push_down(int p, int l, int mid, int r) {
	ll subtract = t[p].subtract, cnt = t[p].cnt;

	t[p << 1].subtract += subtract;
	t[p << 1 | 1].subtract += subtract;

	t[p << 1].cnt += cnt;
	t[p << 1 | 1].cnt += cnt;

	t[p << 1].sum += sum_range(l, mid)*cnt - subtract*(mid - l + 1);
	t[p << 1 | 1].sum += sum_range(mid + 1, r)*cnt - subtract*(r - mid);

	t[p].subtract = t[p].cnt = 0;
}

void build(int p, int l, int r) {
	if (l == r) {
		t[p].sum = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);

	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

void update(int p, int l, int r, int i, int j) {
	if (j < l || r < i)
		return;
	if (i <= l && r <= j) {
		++t[p].cnt;
		t[p].subtract += i - 1;
		t[p].sum += sum_range(l, r) - 1LL*(r - l + 1)*(i - 1);
		return;
	}

	int mid = (l + r) >> 1;
	push_down(p, l, mid, r);

	update(p << 1, l, mid, i, j);
	update(p << 1 | 1, mid + 1, r, i, j);

	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

ll get(int p, int l, int r, int i, int j) {
	if (r < i || j < l)
		return 0;
	if (i <= l && r <= j)
		return t[p].sum;

	int mid = (l + r) >> 1;
	push_down(p, l, mid, r);

	return get(p << 1, l, mid, i, j) + get(p << 1 | 1, mid + 1, r, i, j);
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	build(1, 1, n);

	while (q--) {
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		if (type == 1)
			update(1, 1, n, l, r);
		else
			printf("%lld\n", get(1, 1, n, l, r));
	}
}

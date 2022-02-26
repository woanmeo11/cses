// cses: Range Updates and Sums
// tags: segment tree
// huycon

#include <bits/stdc++.h>

typedef long long ll;
const int N = 2e5 + 5;

int a[N];

struct node {
	ll sum, set_all, increment;
} t[4 * N];

void push_down(int p, int lsize, int rsize) {
	ll set_all = t[p].set_all, increment = t[p].increment;
	if (set_all) {
		t[p << 1] = {lsize * (set_all + increment), set_all, increment};
		t[p << 1 | 1] = {rsize * (set_all + increment), set_all, increment};
	}
	else {
		t[p << 1].increment += increment;
		t[p << 1 | 1].increment += increment;

		t[p << 1].sum += lsize * increment;
		t[p << 1 | 1].sum += rsize * increment;
	}
	t[p].set_all = t[p].increment = 0;
}

void build(int p, int l, int r) {
	if (l == r) {
		t[p] = {a[l], 0, 0};
		return;
	}

	int mid = (l + r) >> 1;

	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);

	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

void update(int p, int l, int r, int i, int j, ll val, bool set_all) {
	if (r < i || j < l)
		return;

	if (i <= l && r <= j) {
		if (set_all)
			t[p] = {(r - l + 1) * val, val, 0};
		else {
			t[p].sum += (r - l + 1) * val;
			t[p].increment += val;
		}
		return;
	}

	int mid = (l + r) >> 1;
	push_down(p, mid - l + 1, r - mid);

	update(p << 1, l, mid, i, j, val, set_all);
	update(p << 1 | 1, mid + 1, r, i, j, val, set_all);

	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

ll get(int p, int l, int r, int i, int j) {
	if (r < i || j < l)
		return 0;

	if (i <= l && r <= j)
		return t[p].sum;

    int mid = (l + r) >> 1;
	push_down(p, mid - l + 1, r - mid);

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
		if (type != 3) {
			int x;
			scanf("%d", &x);
			update(1, 1, n, l, r, x, type == 2);
		}
		else
			printf("%lld\n", get(1, 1, n, l, r));
	}
}

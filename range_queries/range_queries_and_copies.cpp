// cses: Range Queries and Copies
// tags: segmentree, persistent data structures
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct Node {
	Node *lchild, *rchild;
	ll sum;
} * node;

const int N = 2e5 + 5;
node ver[N];
int a[N];

void build(node &root, int l, int r) {
	root = new Node();
	if (l == r) {
		root->sum = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(root->lchild, l, mid);
	build(root->rchild, mid + 1, r);

	root->sum = root->lchild->sum + root->rchild->sum;
}

void update(node &root, node old_root, int l, int r, int pos, int val) {
	if (r < pos || pos < l)
		return;

	root = new Node;

	if (l == r) {
		root->sum = val;
		return;
	}

	int mid = (l + r) >> 1;
	if (pos <= mid) {
		root->rchild = old_root->rchild;
		update(root->lchild, old_root->lchild, l, mid, pos, val);
	}
	else {
		root->lchild = old_root->lchild;
		update(root->rchild, old_root->rchild, mid + 1, r, pos, val);
	}

	root->sum = root->lchild->sum + root->rchild->sum;
}

ll get(node root, int l, int r, int i, int j) {
	if (j < l || r < i)
		return 0;

	if (i <= l && r <= j)
		return root->sum;

	int mid = (l + r) >> 1;
	return get(root->lchild, l, mid, i, j) + get(root->rchild, mid + 1, r, i, j);
}

int main() {
    freopen("in", "r", stdin);

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	int cur_ver = 0;
	build(ver[++cur_ver], 1, n);

	while (q--) {
		int type, k;
		scanf("%d%d", &type, &k);
		if (type == 1) {
			int pos, val;
			scanf("%d%d", &pos, &val);
			node new_root;
			update(new_root, ver[k], 1, n, pos, val);
			ver[k] = new_root;
		}
		else if (type == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", get(ver[k], 1, n, l, r));
		}
		else 
			ver[++cur_ver] = ver[k];
	}
}

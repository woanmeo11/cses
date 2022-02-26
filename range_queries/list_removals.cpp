// cses: List Removals
// tags: binary search, bit
// huycon

#include <bits/stdc++.h>

const int N = 2e5 + 5;
int n, bit[N], a[N];

void update(int i, int v) {
	while (i <= n) {
		bit[i] += v;
		i += i & -i;
	}	
}

int get(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i &= i - 1;
	}
	return res;
}

int main() {
	freopen("in", "r", stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		update(i, 1);
	}

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		
		int low = 0, high = n;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (get(mid) >= x)
				high = mid;
			else
				low = mid;
		}

		update(high, -1);
		printf("%d ", a[high]);	
	}
}

// cses: Maximum Subarray Sum II
// tags: deque
// top 1 fastest c++ code
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 2e5 + 5;

ll sum[MAX_N];
int d[MAX_N], l, r;

inline int read_int() {
    bool negative = false;
    register char c;
    while (!isdigit(c = getchar_unlocked()))
        negative |= c == '-';
    int x = c - 48;
    while (isdigit(c = getchar_unlocked()))
        x = (x << 1) + (x << 3) + c - 48;
    if (negative)
        return -x;
    return x;
}

int main() {
	int n = read_int(), a = read_int(), b = read_int();

	ll res = LLONG_MIN;
	for (int i = 1; i <= n; ++i) {
		sum[i] = read_int() + sum[i - 1];

		if (i - a >= 0) {
			while (r > l && sum[d[r - 1]] > sum[i - a])
				--r;
			d[r++] = i - a;
		}

		while (r > l && d[l] < i - b)
			++l;

		if (r > l)
			res = max(res, sum[i] - sum[d[l]]);
	}

	printf("%lld", res);
}

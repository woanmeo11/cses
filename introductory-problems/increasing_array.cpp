// cses: Increasing Array
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, pre = 0;
	long long res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		if (pre > x)
			res += pre - x;
		pre = max(pre, x);
	}
	printf("%lld", res);
}
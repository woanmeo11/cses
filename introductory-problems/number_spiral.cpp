// cses: Number Spiral
// tags: math
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
#define f(a, b) (1LL*a*a - b + 1)
#define g(a, b) (1LL*(a - 1)*(a - 1) + b)
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long res;
		if (x > y) {
			if (x & 1)
				res = g(x, y);
			else
				res = f(x, y);
		}
		else {
			if (y & 1)
				res = f(y, x);
			else
				res = g(y, x);
		}
		printf("%lld\n", res);
	}
}
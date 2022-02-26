// cses: Trailing Zeros
// tags: math
// author: huycon

#include <bits/stdc++.h>
 
int main() {
	int n, res = 0, p = 5;
	scanf("%d", &n);
	while (n / p) {
		res += n / p;
		p *= 5;
	}
	printf("%d", res);
}
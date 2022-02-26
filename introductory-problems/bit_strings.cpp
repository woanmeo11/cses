// cses: Bit Strings
// tags: dp
// author: huycon

#include <bits/stdc++.h>
 
const int MOD = 1e9 + 7;
 
int main() {
	int n, f = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		f = 2 * f % MOD;
	printf("%d", f);
}
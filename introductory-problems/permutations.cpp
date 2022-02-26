// cses: Permutations
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1)
		putchar('1');
	else if (n < 4)
		puts("NO SOLUTION");
	else if (n == 4)
		puts("2 4 1 3");
	else {
		for (int i = 1; i <= n; i += 2)
			printf("%d ", i);
		for (int i = 2; i <= n; i += 2)
			printf("%d ", i);
	}
}
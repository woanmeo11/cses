// cses: Distinct Numbers
// tags: sort
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int a[MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	int res = 1;
	for (int i = 1; i < n; ++i)
		if (a[i] != a[i - 1])
			++res;
	printf("%d", res);
}

// cses: Removing Digits
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;
int f[MAX_N];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		f[i] = 1e9;
		int num = i;
		while (num) {
			f[i] = min(f[i], 1 + f[i - num%10]);
			num /= 10;
		}
	}

	printf("%d", f[n]);
}

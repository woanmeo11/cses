// cses: Two Sets
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
vector <int> a, b;
 
int main() {
	long long n;
	scanf("%lld", &n);
 
	long long s = n * (n + 1) >> 1;
 
	if (s & 1) {
		puts("NO");
		return 0;
	}
 
    puts("YES");
    s >>= 1;
 
	for (int i = n; i > 0; --i)
		if (i <= s) {
			s -= i;
			a.emplace_back(i);
		}
		else
			b.emplace_back(i);
 
	printf("%d\n", a.size());
	for (int &x: a)
		printf("%d ", x);
 
	printf("\n%d\n", b.size());
	for (int &x: b)
		printf("%d ", x);
}
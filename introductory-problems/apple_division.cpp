// cses: Apple Division
// tags: backtracking
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int a[25], n;
bool used[25];
ll total_sum, res = LLONG_MAX;
 
void attempt(int i, int last, ll used_sum) {
	res = min(res, abs(total_sum - 2*used_sum));
	if (i == n)
        return;
    for (int j = last + 1; j < n; ++j)
        if (!used[j]) {
            used[j] = true;
            attempt(i + 1, j, used_sum + a[j]);
            used[j] = false;
        }
}
 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		total_sum += a[i];
	}
	attempt(0, -1, 0);
	printf("%lld", res);
}
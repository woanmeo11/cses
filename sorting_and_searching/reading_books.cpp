// cses: Reading Books
// tags: casual
// huycon

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    long long sum = 0, max_value = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        sum += x;
        max_value = max(max_value, 1LL * x);
    }
    printf("%lld", max(sum, 2 * max_value));
}

// cses: Restaurant Customers
// tags: sort
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 4e5 + 5;
pair <int, int> a[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i + n].first);
        a[i].second = 1;
        a[i + n].second = -1;
    }

    sort(a, a + 2*n);

    int sum = 0, res = 0;
    for (int i = 0; i < 2 * n; ++i) {
        sum += a[i].second;
        res = max(res, sum);
    }

    printf("%d", res);
}

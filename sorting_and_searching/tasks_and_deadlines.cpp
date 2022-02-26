// cses: Tasks and Deadlines
// tags: sorting, greedy

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
pair <long long, int> a[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%d", &a[i].first, &a[i].second);

    sort(a + 1, a + n + 1);

    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        a[i].first += a[i - 1].first;
        res += a[i].second - a[i].first;
    }

    printf("%lld", res);
}

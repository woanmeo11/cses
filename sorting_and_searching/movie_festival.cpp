// cses: Movie Festival
// tags: sort
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
pair <int, int> a[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);

    sort(a, a + n);

    int res = 1, cur = a[0].second;
    for (int i = 1; i < n; ++i) {
        cur = min(cur, a[i].second);
        if (cur <= a[i].first) {
            ++res;
            cur = a[i].second;
        }
    }

    printf("%d", res);
}

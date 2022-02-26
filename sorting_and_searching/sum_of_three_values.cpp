// cses: Sum of Three Values
// tags: sorting, pointer
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;
pair <int, int> a[MAX_N];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }

    sort(a, a + n);

    for (int i = 0; i < n - 2; ++i) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            if (a[j].first + a[k].first == x - a[i].first) {
                printf("%d %d %d", a[i].second, a[j].second, a[k].second);
                return 0;
            }
            if (a[j].first + a[k].first < x - a[i].first)
                ++j;
            if (a[j].first + a[k].first > x - a[i].first)
                --k;
        }
    }

    puts("IMPOSSIBLE");
}

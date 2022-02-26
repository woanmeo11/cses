// cses: Sum of Two Values
// tags: sort, pointer
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
pair <int, int> a[MAX_N];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }

    sort(a, a + n);
    
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i].first + a[j].first == x) {
            printf("%d %d", a[i].second, a[j].second);
            return 0;
        }
        if (a[i].first + a[j].first < x)
            ++i;
        else
            --j;
    }

    puts("IMPOSSIBLE");
}

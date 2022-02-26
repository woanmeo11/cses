// cses: Apartments
// tags: sort, pointer
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int a[MAX_N], b[MAX_N];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < m; ++i)
        scanf("%d", b + i);

    sort(a, a + n);
    sort(b, b + m);

    int res = 0;
    for (int i = 0, j = 0; i < n && j < m; ++i) {
        while (j < m && b[j] < a[i] - k)
            ++j;
        if (j < m && b[j] <= a[i] + k) {
            ++res;
            ++j;
        }
    }

    printf("%d", res);
}

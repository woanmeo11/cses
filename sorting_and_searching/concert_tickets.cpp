// cses: Concert Tickets
// tags: sort, compress path
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int a[MAX_N], t[MAX_N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        t[i] = i;
    }

    t[n] = n;
    sort(a, a + n);

    while (m--) {
        int x;
        scanf("%d", &x);
        int i = upper_bound(a, a + n, x) - a;

        // compress path
        while (t[i] != i)
            i = t[i] = t[t[i]];

        if (i == 0) {
            puts("-1");
            continue;
        }

        printf("%d\n", a[i - 1]);

        --t[i];
    }
}

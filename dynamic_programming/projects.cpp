// cses: Projects
// tags: dp, binary search
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 2e5 + 5;

struct pack {
    int s, t, p;
} a[MAX_N];

int n;
ll f[MAX_N];

ll get(int high, int x) {
    int low = -1;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (a[mid].t < x)
            low = mid;
        else
            high = mid;
    }
    return low >= 0 ? f[low] : 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &a[i].s, &a[i].t, &a[i].p);

    sort(a, a + n, [] (const pack &x, const pack &y) {
        return x.t < y.t;
    });

    f[0] = a[0].p;
    for (int i = 1; i < n; ++i)
        f[i] = max(f[i - 1], get(i, a[i].s) + a[i].p);

    printf("%lld", f[n - 1]);
}


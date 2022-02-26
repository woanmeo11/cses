// cses: Factory Machines
// tags: binary search
// huycon

#include <bits/stdc++.h>

typedef long long ll;

const int MAX_N = 2e5 + 5;
int n, t, k[MAX_N];

ll check(ll x) {
    ll product = 0;
    for (int i = 0; i < n; ++i) {
        product += x / k[i];
        if (product >= 1LL * t)
            return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i)
        scanf("%d", k + i);

    ll low = 0, high = 1e18;
    while (high - low > 1) {
        ll mid = (low + high) >> 1;
        if (check(mid))
            high = mid;
        else
            low = mid;
    }

    printf("%lld", high);
}

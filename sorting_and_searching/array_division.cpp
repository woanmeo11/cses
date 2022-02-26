// cses: Array Division
// tags: binary search
// huycon

#include <bits/stdc++.h>

typedef long long ll;

const int MAX_N = 2e5 + 5;
int a[MAX_N], n, k;

bool check(ll x) {
    int cnt = 1;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x)
            return false;
        sum += a[i];
        if (sum > x) {
            sum = a[i];
            if (++cnt > k)
                return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    ll low = 0, high = 1e15;
    while (high - low > 1) {
        ll mid = (low + high) >> 1;
        if (check(mid))
            high = mid;
        else
            low = mid;
    }

    printf("%lld", high);
}

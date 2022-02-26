// cses: Subarray Divisibility
// tags: math
// huycon

#include <bits/stdc++.h>

const int MAX_N = 2e5 + 5;
int r[MAX_N];

int main() {
    int n;
    scanf("%d", &n);

    r[0] = 1;
    int sum = 0;
    long long res = 0;

    for (int i = 0, x; i < n; ++i) {
        scanf("%d", &x);

        sum += x;
        if (sum < 0)
            sum += n * (-sum/n + 1);
        sum %= n;

        res += r[sum];
        ++r[sum];
    }

    printf("%lld", res);
}

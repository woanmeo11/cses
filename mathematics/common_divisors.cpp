// cses: Common Divisors
// tags: math
// huycon

#include <bits/stdc++.h>

int cnt[1000005];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    for (int i = 1e6; i >= 1; --i) {
        int divs = 0;
        for (int j = i; j <= 1e6; j += i)
            divs += cnt[j];
        if (divs > 1) {
            printf("%d", i);
            break;
        }
    }
}

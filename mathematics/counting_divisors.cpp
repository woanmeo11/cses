// cses: Counting Divisors
// math
// huycon

#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, res = 1, i = 2;
        scanf("%d", &x);
        while (i * i <= x) {
            int cnt = 1;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            res *= cnt;
            ++i;
        }
        if (x > 1)
            res *= 2;
        printf("%d\n", res);
    }
}

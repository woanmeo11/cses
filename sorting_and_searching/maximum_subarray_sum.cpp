// cses: Maximum Subarray Sum
// tags: dp
// huycon

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    scanf("%d", &n);
    long long min_value = 0, sum = 0, res = LLONG_MIN;
    while (n--) {
        scanf("%d", &x);
        sum += x;
        if (sum - min_value > res)
            res = sum - min_value;
        min_value = min(min_value, sum);
    }
    printf("%lld", res);
}

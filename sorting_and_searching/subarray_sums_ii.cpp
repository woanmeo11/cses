// cses: Subarray Sums II
// tags: bst
// huycon

#include <bits/stdc++.h>
using namespace std;

map <long long, int> m;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);

    m[0] = 1;
    long long sum = 0, res = 0;;

    for (int a, i = 0; i < n; ++i) {
        scanf("%d", &a);
        sum += a;
        res += m[sum - x];
        ++m[sum];
    }

    printf("%lld", res);
}

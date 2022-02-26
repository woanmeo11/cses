// cses: Range Sum Queries I
// tags: dp
// huycon

#include <bits/stdc++.h>
 
long long sum[200005];
 
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
 
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", sum + i);
        sum[i] += sum[i - 1];
    }
 
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", sum[b] - sum[a - 1]);
    }
}
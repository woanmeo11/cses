// cses: Subarray Sums I
// tags: pointer
// huycon

#include <bits/stdc++.h>

const int MAX_N = 2e5 + 5;
int a[MAX_N];

int main() {
    int n, x, res = 0;
    scanf("%d%d", &n, &x);
    for (int i = 0, j = 0, sum = 0; i < n; ++i) {
        scanf("%d", a + i);
        sum += a[i];

        while (sum > x && j <= i)
            sum -= a[j++];

        if (j <= i && sum == x)
            ++res;
    }

    printf("%d", res);
}

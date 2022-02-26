// cses: Stick Lengths
// tags: sort
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int a[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    sort(a, a + n);

    int x = a[n >> 1];
    long long res = 0;
    for (int i = 0; i < n; ++i)
        res += abs(a[i] - x);

    printf("%lld", res);
}

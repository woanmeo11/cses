// cses: Ferris Wheel
// tags: sort, pointer
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
int a[MAX_N];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    sort(a, a + n);

    int i = n - 1, j = 0;
    while (i >= j) {
        if (a[j] + a[i] <= x)
            ++j;
        --i;
    }

    printf("%d", n - i - 1);
}

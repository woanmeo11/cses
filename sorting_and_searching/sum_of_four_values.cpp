// cses: Sum of Four Values
// tags: sorting, pointer
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

struct Pair {
    int sum, i, j;
} b[MAX_N * MAX_N];

int a[MAX_N];

bool distinc(const Pair &a, const Pair &b) {
    return
        a.i != b.i && a.i != b.j &&
        a.j != b.i && a.j != b.j;
}

int main() {
    int n, m = 0, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        for (int j = 0; j < i; ++j)
            b[m++] = {a[i] + a[j], i + 1, j + 1};
    }

    sort(b, b + m, [] (const Pair &a, const Pair &b) {
        return a.sum < b.sum;
    });

    int i = 0, j = m - 1;
    while (i < j) {
        if (1LL*x - b[i].sum - b[j].sum == 0 && distinc(b[i], b[j])) {
            printf("%d %d %d %d", b[i].i, b[i].j, b[j].i, b[j].j);
            return 0;
        }
        else if (1LL*x - b[i].sum - b[j].sum > 0)
            ++i;
        else
            --j;
    }

    puts("IMPOSSIBLE");
}

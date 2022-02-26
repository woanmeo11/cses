// cses: Cycle Finding
// tags: bellman-ford
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 2505, M = 5005;

int p[N], cycle[N];
long long d[N];
tuple <int, int, int> e[M];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        e[i] = {u, v, c};
    }

    memset(p + 1, -1, n * sizeof(p[0]));

    int x = - 1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < m; ++j) {
            int u, v, w;
            tie(u, v, w) = e[j];
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                x = v;
            }
        }
        if (x == -1)
            break;
    }

    if (x == -1)
        puts("NO");
    else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        m = 0;
        for (int v = x; ; v = p[v]) {
            cycle[m++] = v;
            if (v == x && m > 1)
                break;
        }

        puts("YES");

        for (int i = m - 1; i >= 0; --i)
            printf("%d ", cycle[i]);
    }
}

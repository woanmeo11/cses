// cses: Investigation
// tags: dp, dijkstra
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5, MOD = 1e9 + 7;

ll d[N];
int c[3][N];
vector <pair <int, int>> g[N];
priority_queue <pair <ll, int>> heap;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
    }

    memset(d + 2, 0x3f, (n - 1) * sizeof(d[0]));
    c[0][1] = 1;

    heap.push({0, 1});
    while (!heap.empty()) {
        ll du;
        int u;
        tie(du, u) = heap.top();
        heap.pop();
        du = -du;

        if (d[u] != du)
            continue;

        for (auto pack: g[u]) {
            int v, w;
            tie(v, w) = pack;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                c[0][v] = c[0][u];
                c[1][v] = c[1][u] + 1;
                c[2][v] = c[2][u] + 1;
                heap.push({-d[v], v});
            }
            else if (d[v] == d[u] + w) {
                c[0][v] = (c[0][v] + c[0][u]) % MOD;
                c[1][v] = min(c[1][v], c[1][u] + 1);
                c[2][v] = max(c[2][v], c[2][u] + 1);
            }
        }
    }

    printf("%lld %d %d %d", d[n], c[0][n], c[1][n], c[2][n]);
}

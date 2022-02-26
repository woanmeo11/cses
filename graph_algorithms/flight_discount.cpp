// cses: Flight Discount
// tags: dijkstra
// top 2 fastest code
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

ll d[2][N];
vector <pair <int, int>> g[N];
priority_queue <tuple <ll, int, bool>> heap;

inline int read_int() {
    register char c;
    while (!isdigit(c = getchar_unlocked()));
    int x = c - 48;
    while (isdigit(c = getchar_unlocked()))
        x = (x << 1) + (x << 3) + c - 48;
    return x;
}

int main() {
    int n = read_int(), m = read_int();

    while (m--) {
        int u = read_int(), v = read_int(), c = read_int();
        g[u].push_back({v, c});
    }

    for (int i = 2; i <= n; ++i)
        d[0][i] = d[1][i] = 1e18;

    heap.push({0, 1, false});

    while (!heap.empty()) {
        auto state = heap.top();
        heap.pop();

        ll du;
        int u;
        bool used_discount;

        tie(du, u, used_discount) = state;
        du = -du;

        if (du != d[used_discount][u])
            continue;

        for (auto vertex: g[u]) {
            int v, w;
            tie(v, w) = vertex;

            if (d[used_discount][v] > du + w) {
                d[used_discount][v] = du + w;
                heap.push({-d[used_discount][v], v, used_discount});
            }

            if (!used_discount && du + w/2 < d[1][v]) {
                d[1][v] = du + w/2;
                heap.push({-d[1][v], v, true});
            }
        }
    }

    printf("%lld", d[1][n]);
}

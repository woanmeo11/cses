// cses: Flight Routes
// tags: dijkstra
// top 3 fastest code
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int c[N];
vector <pair <int, int>> g[N];
priority_queue <pair <long long, int>> heap;

inline int read_int() {
    register char c;
    while (!isdigit(c = getchar_unlocked()));
    int x = c - 48;
    while (isdigit(c = getchar_unlocked()))
        x = (x << 1) + (x << 3) + c - 48;
    return x;
}

int main() {
    int n = read_int(), m = read_int(), k = read_int();
    while (m--) {
        int u = read_int(), v = read_int(), w = read_int();
        g[u].push_back({v, w});
    }

    heap.push({0, 1});
    while (!heap.empty()) {
        long long d;
        int u;
        tie(d, u) = heap.top();
        heap.pop();

        if (++c[u] > k)
            continue;

        if (u == n) {
            printf("%lld ", -d);
            if (c[u] == k)
                break;
        }

        for (auto pack: g[u]) {
            int v, w;
            tie(v, w) = pack;
            if (c[v] < k)
                heap.push({d - w, v});
        }
    }
}


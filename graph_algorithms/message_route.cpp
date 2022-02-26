// cses: Message Route
// tags: bfs, graph
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> near[MAX_N];
int l, r, q[MAX_N];
int parent[MAX_N], path[MAX_N];
bool visited[MAX_N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        near[u].emplace_back(v);
        near[v].emplace_back(u);
    }

    q[r++] = 1;
    visited[1] = true;
    while (l < r) {
        int u = q[l++];
        if (u == n)
            break;

        for (int v: near[u])
            if (!visited[v]) {
                visited[v] = true;
                q[r++] = v;
                parent[v] = u;
            }
    }

    if (parent[n] == 0) {
        puts("IMPOSSIBLE");
        return 0;
    }

    m = 0;
    do {
        path[m++] = n;
        n = parent[n];
    }
    while (n);

    printf("%d\n", m);
    for (int i = m - 1; i >= 0; --i)
        printf("%d ", path[i]);
}


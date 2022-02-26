// cses: Building Teams
// tags: dfs, graph
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector <int> near[MAX_N];
int color[MAX_N];

void dfs(int u, int c) {
    color[u] = c;
    for (int v: near[u])
        if (color[v] == 0)
            dfs(v, 3 - c);
        else if (color[v] == c) {
            puts("IMPOSSIBLE");
            exit(0);
        }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        near[u].emplace_back(v);
        near[v].emplace_back(u);
    }

    for (int u = 1; u <= n; ++u)
        if (color[u] == 0)
            dfs(u, 1);

    for (int u = 1; u <= n; ++u)
        printf("%d ", color[u]);
}


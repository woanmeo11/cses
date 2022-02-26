// cses: Round Trip
// tags: dfs, graph
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector <int> near[MAX_N];
bool in_dfs[MAX_N], visited[MAX_N];
int st[MAX_N], top;

void dfs(int u, int p) {
    in_dfs[u] = visited[u] = true;
    st[top++] = u;

    for (int v: near[u]) {
        if (v == p)
            continue;
        if (!visited[v])
            dfs(v, u);
        else if (in_dfs[v] && top > 2) {
            st[top++] = v;

            int i = 0;
            while (st[i] != v)
                ++i;

            printf("%d\n", top - i);
            while (i < top)
                printf("%d ", st[i++]);

            exit(0);
        }
    }

    in_dfs[u] = false;
    --top;
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
        if (!visited[u])
            dfs(u, u);

    puts("IMPOSSIBLE");
}


// cses: Tree Matching
// tags: dp, tree
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int f[2][N];
vector <int> g[N];

void dfs(int u, int p) {
    bool add_f0 = false;
    int sum = 0;

    for (int v: g[u])
        if (v != p) {
            dfs(v, u);
            if (f[1][v] > f[0][v])
                sum += f[1][v];
            else {
                sum += f[0][v];
                add_f0 = true;
            }
        }

    f[0][u] = sum;
    if (add_f0)
        f[1][u] = 1 + sum;

    for (int v: g[u])
        if (f[1][v] > f[0][v])
            f[1][u] = max(f[1][u], 1 + sum - f[1][v] + f[0][v]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);

    printf("%d", max(f[0][1], f[1][1]));
}

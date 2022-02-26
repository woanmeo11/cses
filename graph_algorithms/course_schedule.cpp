// cses: Course Schedule
// tags: dfs, topo
// 1st fastest code
// huycon

#include <bits/stdc++.h>

const int N = 1e5 + 5, M = 2e5 + 5;
int m, topo[N], link[M], head[N], e[M];
bool visited[N], in_dfs[N];

inline int read_int() {
    register char c;
    while (!isdigit(c = getchar_unlocked()));
    int x = c - 48;
    while (isdigit(c = getchar_unlocked()))
        x = (x << 1) + (x << 3) + c - 48;
    return x;
}

inline void write_int(int x) {
    if (x > 9)
        write_int(x / 10);
    putchar_unlocked(x%10 + 48);
}

void dfs(int u) {
    visited[u] = in_dfs[u] = true;

    int i = head[u];
    while (i) {
        int v = e[i];
        if (!visited[v])
            dfs(v);
        else if (in_dfs[v]) {
            puts("IMPOSSIBLE");
            exit(0);
        }
        i = link[i];
    }

    in_dfs[u] = false;
    topo[m++] = u;
}

int main() {
    int n = read_int();
    m = read_int();

    for (int i = 1; i <= m; ++i) {
        int u = read_int();
        e[i] = read_int();
        link[i] = head[u];
        head[u] = i;
    }

    m = 0;
    for (int u = 1; u <= n; ++u)
        if (!visited[u])
            dfs(u);

    for (int i = m - 1; i >= 0; --i) {
        write_int(topo[i]);
        putchar_unlocked(32);
    }
}

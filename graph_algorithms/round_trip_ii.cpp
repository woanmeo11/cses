// cses: Round Trip II
// tags: dfs
// 2nd fastest code
// huycon

#include <bits/stdc++.h>

const int N = 1e5 + 5, M = 2e5 + 5;

int link[M], head[N], e[M], st[N], top, x[N];
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
    st[top++] = u;
    visited[u] = in_dfs[u] = true;

    int i = head[u];
    while (i) {
        int v = e[i];
        if (!in_dfs[v])
            dfs(v);
        else {
            int cnt = 0;
            x[cnt++] = v;
            do {
                x[cnt++] = st[--top];
            }
            while (v != x[cnt - 1]);

            write_int(cnt);
            putchar_unlocked(10);

            for (int i = cnt - 1; i >= 0; --i) {
                write_int(x[i]);
                putchar_unlocked(32);
            }

            exit(0);
        }
        i = link[i];
    }

    --top;
    in_dfs[u] = false;
}

int main() {
    int n = read_int(), m = read_int();

    for (int i = 1; i <= m; ++i) {
        int u = read_int();
        e[i] = read_int();
        link[i] = head[u];
        head[u] = i;
    }

    for (int u = 1; u <= n; ++u)
        if (!visited[u])
            dfs(u);

    puts("IMPOSSIBLE");
}

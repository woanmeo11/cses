// cses: Counting Rooms
// tags: graph
// huycon

#include <bits/stdc++.h>

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int n, m;
char s[1005][1005];
bool visited[1005][1005];

void dfs(int i, int j) {
    visited[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int u = i + dx[k], v = j + dy[k];
        if (u < 0 || u >= n || v < 0 || v >= m || s[u][v] == '#' || visited[u][v])
            continue;
        dfs(u, v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);

    int cnt = 0 ;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '.' && !visited[i][j]) {
                ++cnt;
                dfs(i, j);
            }

    printf("%lld", cnt);
}


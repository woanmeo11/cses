// cses: Labyrinth
// tags: bfs, graph
// huycon

#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};
const char dc[] = "0DRUL";

typedef pair <int, int> ii;
const int MAX_N = 1000;

int n, m, trace[MAX_N + 5][MAX_N + 5];
char s[MAX_N + 5][MAX_N + 5], path[MAX_N * MAX_N];

int l, r;
ii q[MAX_N * MAX_N];

void print(int i, int j) {
    int len = 0;
    do {
        int k = trace[i][j];
        path[len++]= dc[k];
        i -= dx[k];
        j -= dy[k];
    }
    while (trace[i][j] != -1);

    printf("YES\n%d\n", len);
    for (int i = len - 1; i >= 0; --i)
        putchar(path[i]);

    exit(0);
}

void bfs(int i, int j) {
    q[r++] = make_pair(i, j);
    trace[i][j] = -1;

    while (l < r) {
        int i, j;
        tie(i, j) = q[l++];

        if (s[i][j] == 'B')
            print(i, j);

        for (int k = 1; k <= 4; ++k) {
            int u = i + dx[k], v = j + dy[k];
            if (u < 0 || u >= n || v < 0 || v >= m || s[u][v] == '#' || trace[u][v])
                continue;

            q[r++] = make_pair(u, v);
            trace[u][v] = k;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == 'A') {
                bfs(i, j);
                puts("NO");
                return 0;
            }
}


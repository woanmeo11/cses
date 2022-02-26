// cses: Subordinates
// tags: dp, tree
// huycon

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector <int> g[N];
int res[N];

void dfs(int u) {
	for (int v: g[u]) {
		dfs(v);
		res[u] += 1 + res[v];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		int j;
		scanf("%d", &j);
		g[j].push_back(i);
	}

	dfs(1);

	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
}

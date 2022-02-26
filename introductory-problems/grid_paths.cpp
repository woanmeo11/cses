// cses: Grid Paths
// tags: backtracking
// huycon

#include <bits/stdc++.h>
using namespace std;

const int n = 7;
char s[50];
int d[50], res;
bool visited[8][8];

void dfs(int r, int c, int steps) {
	if (r == n - 1 && c == 0) {
		res += steps == n*n - 1;
		return;
	}

	// if hiting a wall or a path (can only go left or right) then return
	if (
		(
			(r + 1 == n || visited[r - 1][c] && visited[r + 1][c]) &&
			c - 1 >= 0 && c + 1 < n &&
			!visited[r][c - 1] && !visited[r][c + 1]
		) ||
		(
			(c + 1 == n || visited[r][c - 1] && visited[r][c + 1]) &&
			r - 1 >= 0 && r + 1 < n &&
			!visited[r - 1][c] && !visited[r + 1][c]
		) ||
		(
			(r == 0 || visited[r + 1][c] && visited[r - 1][c]) &&
			c - 1 >= 0 && c + 1 < n &&
			!visited[r][c - 1] && !visited[r][c + 1]
		) ||
		(
			(c == 0 || visited[r][c + 1] && visited[r][c - 1]) &&
			r - 1 >= 0 && r + 1 < n &&
			!visited[r - 1][c] && !visited[r + 1][c]
		)
	)
		return;

	visited[r][c] = true;

	if (d[steps] != -1) {
		switch (d[steps]) {
			case 0:
				if (r - 1 >= 0 && !visited[r - 1][c])
					dfs(r - 1, c, steps + 1);
				break;
			case 1:
				if (c + 1 < n && !visited[r][c + 1])
					dfs(r, c + 1, steps + 1);
				break;
			case 2:
				if (r + 1 < n && !visited[r + 1][c])
					dfs(r + 1, c, steps + 1);
				break;
			case 3:
				if (c - 1 >= 0 && !visited[r][c - 1])
					dfs(r, c - 1, steps + 1);
				break;
		}
	}
	else {
		// move down
		if (r - 1 >= 0 && !visited[r - 1][c])
			dfs(r - 1, c, steps + 1);
		// move right
		if (c + 1 < n && !visited[r][c + 1])
			dfs(r, c + 1, steps + 1);
		// move up
		if (r + 1 < n && !visited[r + 1][c])
			dfs(r + 1, c, steps + 1);
		// move left
		if (c - 1 >= 0 && !visited[r][c - 1])
			dfs(r, c - 1, steps + 1);
	}

	visited[r][c] = false;
}

int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; ++i) {
		if (s[i] == '?')
			d[i] = -1;
		else if (s[i] == 'U')
			d[i] = 0;
		else if (s[i] == 'R')
			d[i] = 1;
		else if (s[i] == 'D')
			d[i] = 2;
		else
			d[i] = 3;
	}
	dfs(0, 0, 0);
	printf("%d", res);
}

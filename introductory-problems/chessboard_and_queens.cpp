// cses: Chessboard and Queens
// tags: backtracking
// huycon

#include <bits/stdc++.h>
using namespace std;

bool r[8], d[16], d2[16];
char s[8][8];
int res;

void attempt(int j) {
	for (int i = 0; i < 8; ++i) 
		if (!r[i] && !d[i + j] && !d2[i - j + 7] && s[i][j] == '.') {
			r[i] = d[i + j] = d2[i - j + 7] = true;
			if (j == 7)
                ++res;
			else
                attempt(j + 1);
			r[i] = d[i + j] = d2[i - j + 7] = false;
		}
}

int main() {
	for (int i = 0; i < 8; ++i)
		scanf("%s", s[i]);
	attempt(0);
	printf("%d", res);
}

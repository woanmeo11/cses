// cses: Palindrome Reorder
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 1e6 + 5;
char s[MAX_N];
int c[26];
 
int main() {	
	scanf("%s", s);
	int n, i;
	for (i = 0; s[i]; ++i) 
		++c[s[i] - 65];
	n = i;
 
	bool odd_exist = false;
	int j = -1;
	for (int i = 0; i < 26; ++i) {
		if (c[i] & 1) {
			if (odd_exist) {
				puts("NO SOLUTION");
				return 0;
			}
			else {
				odd_exist = true;
				s[n >> 1] = i + 65;
				--c[i];
			}
		}
        while (c[i]) {
            ++j;
            s[j] = s[n - j - 1] = i + 65;
            c[i] -= 2;
        }
    }
 
	puts(s);
}
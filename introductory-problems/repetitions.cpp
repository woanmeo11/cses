// cses: Repetitions
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
const int MAX_LENGTH = 1e6 + 5;
char s[MAX_LENGTH];
 
int main() {
    scanf("%s", s);
    int res = 1, cur = 1;
    for (int i = 1; s[i]; ++i) {
        if (s[i] == s[i - 1])
            ++cur;
        else {
            res = max(res, cur);
            cur = 1;
        }
    }
    res = max(res, cur);
    printf("%d", res);
}
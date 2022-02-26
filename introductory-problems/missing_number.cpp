// cses: Missing Number
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 2e5 + 5;
bool marked[MAX_N];
 
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        marked[x] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!marked[i]) {
            printf("%d", i);
            break;
        }
}
// cses: Coin Piles
// tags: math
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        int x = b - a;
        a -= x;
        b -= 2*x;
        if (a >= 0 && a % 3 == 0)
            puts("YES");
        else
            puts("NO");
    }
}
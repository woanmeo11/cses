// cses: Weird Algorithm
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n;
    scanf("%lld", &n);
    while (n != 1) {
        printf("%lld ", n);
        if (n & 1)
            n = n*3 + 1;
        else
            n >>= 1;
    }
    putchar('1');
}
// cses: Sliding Median
// tags: heap
// huycon
// top 1 fastest c++ code

#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int MAX_N = 2e5 + 5;

int a[MAX_N];
priority_queue <ii> l;
priority_queue <ii, vector <ii>, greater <ii>> r;

inline int read_int() {
    register char c;
    while (!isdigit(c = getchar_unlocked()));
    int x = c - 48;
    while (isdigit(c = getchar_unlocked()))
        x = (x << 1) + (x << 3) + c - 48;
    return x;
}

inline void write_int(int x) {
    if (x >= 10)
        write_int(x / 10);
    putchar_unlocked(x%10 + 48);
}

int main() {
    int n = read_int();
    int k = read_int();

    int m = (k + 1) >> 1;
    int left_size = 0;

    for (int i = 1; i <= n; ++i) {
        a[i] = read_int();

        while (!l.empty() && l.top().second <= i - k)
            l.pop();
        while (!r.empty() && r.top().second <= i - k)
            r.pop();

        if (left_size < m) {
            r.emplace(make_pair(a[i], i));
            l.emplace(r.top());
            r.pop();
            ++left_size;
        }
        else {
            l.emplace(make_pair(a[i], i));
            r.emplace(l.top());
            l.pop();
        }

        while (!l.empty() && l.top().second <= i - k)
            l.pop();
        while (!r.empty() && r.top().second <= i - k)
            r.pop();

        if (i < k)
            continue;

        write_int(l.top().first);
        putchar_unlocked(32);

        if (a[i - k + 1] <= l.top().first)
            --left_size;
    }
}

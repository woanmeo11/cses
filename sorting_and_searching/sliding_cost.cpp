// cses: Sliding Cost
// tags: heap
// huycon

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
 
inline void write_int(long long x) {
    if (x >= 10)
        write_int(x / 10);
    putchar_unlocked(x%10 + 48);
}
 
int main() {
    int n = read_int();
    int k = read_int();
 
    int m = (k + 1) >> 1;
    int left_size = 0;
    long long left_sum = 0, right_sum = 0;
 
    for (int i = 1; i <= n; ++i) {
        a[i] = read_int();
 
        while (!l.empty() && l.top().second <= i - k)
            l.pop();
        while (!r.empty() && r.top().second <= i - k)
            r.pop();
 
        if (left_size < m) {
            r.emplace(make_pair(a[i], i));
            right_sum += a[i] - r.top().first;
            
            l.emplace(r.top());
            left_sum += r.top().first;
            
            r.pop();
            ++left_size;
        }
        else {
            l.emplace(make_pair(a[i], i));
            left_sum += a[i] - l.top().first;
 
            r.emplace(l.top());
            right_sum += l.top().first;
 
            l.pop();
        }
 
        while (!l.empty() && l.top().second <= i - k)
            l.pop();
        while (!r.empty() && r.top().second <= i - k)
            r.pop();
 
        if (i < k)
            continue;
 
        write_int((2LL*left_size - k)*l.top().first + 1LL*right_sum - left_sum);
        putchar_unlocked(32);
 
        if (a[i - k + 1] <= l.top().first) {
            left_sum -= a[i - k + 1];
            --left_size;
        }
        else 
            right_sum -= a[i - k + 1];
    }
}
// cses: Playlist
// tags: sort, pointer
// huycon

#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int MAX_N = 2e5 + 5;

pair <int, int> a[MAX_N];
bool exist[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a, a + n);

    int pre = a[0].first;
    a[0].first = 1;

    for (int i = 1; i < n; ++i)
        if (a[i].first != pre) {
            pre = a[i].first;
            a[i].first = a[i - 1].first + 1;
        }
        else
            a[i].first = a[i - 1].first;

    sort(a, a + n, [] (const ii &a, const ii &b) {
        return a.second < b.second;
    });

    int res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (exist[a[i].first])
            exist[a[j++].first] = false;
        exist[a[i].first] = true;
        res = max(res, i - j + 1);
    }

    printf("%d", res);
}

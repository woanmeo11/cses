// cses: Room Allocation
// tags: sorting, greedy
// huycon

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

pair <int, int> event[2 * MAX_N];
stack <int> free_room;
int room[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        event[i] = {s, -i};
        event[i + n] = {t, i};
    }

    sort(event + 1, event + 2*n + 1);

    int k = 0;
    for (int i = 1; i <= 2 * n; ++i)
        if (event[i].second < 0) {
            if (free_room.empty())
                free_room.emplace(++k);
            room[-event[i].second] = free_room.top();
            free_room.pop();
        }
        else
            free_room.emplace(room[event[i].second]);

    printf("%d\n", k);
    for (int i = 1; i <= n; ++i)
        printf("%d ", room[i]);
}

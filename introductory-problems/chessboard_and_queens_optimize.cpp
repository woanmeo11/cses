// sangpham2710

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ms(a, b) memset((a), (b), sizeof(a))
#define len(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
#define mine min_element
#define maxe max_element
#define fore(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <class T> void __f(const char* name, T&& a) {
    cerr << name << ": " << a << '\n';
}
template <class T, class... Ts> void __f(const char* names, T&& a, Ts&&... b) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << a << " /";
    __f(comma + 1, b...);
}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> bool mini(T& a, const T& b) { return a > b ? (a = b, 1) : 0; }
template <class T> bool maxi(T& a, const T& b) { return a < b ? (a = b, 1) : 0; }
 
typedef long long ll;
typedef double db;
typedef pair<int, int> pi;
typedef pair<int, pi> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ti> vti;
typedef vector<vpi> vvpi;
 
const int inf = (int)0x3f3f3f3f3f3f3f3f;
const int ninf = (int)0xc0c0c0c0c0c0c0c0;
const int M = (int)1e9 + 7;
const int N = 8;
 
int ans, ok = (1 << 8) - 1;
char a[N][N];
 
void backtrack(int rw, int ld, int rd) {
    if (rw == ok) { ans++; return; }
    int p = ok & (~(rw | ld | rd)), i = __builtin_popcountll(rw);
    while (p) {
        int t = p & -p;
        p -= t;
        int j = __lg(t);
        if (a[i][j] != '*') backtrack(rw | t, (ld | t) << 1, (rd | t) >> 1);
    }
}
 
signed main() {
//    freopen("CP.inp", "r", stdin);
//    freopen("CP.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    fore(i, 0, 8) fore(j, 0, 8) cin >> a[i][j];
    backtrack(0, 0, 0);
    cout << ans << '\n';
}
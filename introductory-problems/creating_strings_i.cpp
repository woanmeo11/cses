// cses: Creating Strings I
// tags: casual
// author: huycon

#include <bits/stdc++.h>
using namespace std;
 
string s;
vector <string> res;
 
int main() {
    cin >> s;
    sort(s.begin(), s.end());
    do {
        res.emplace_back(s);
    }
    while (next_permutation(s.begin(), s.end()));
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << '\n';
}
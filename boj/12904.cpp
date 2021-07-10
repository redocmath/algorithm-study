#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

void solve() {
    string s, t; cin >> t >> s;
    bool isgood = false;

    while (s.length()!=0) {
        if (s == t) {isgood = true; break;}
        if (s[s.length()-1] == 'A') s = s.substr(0, s.length()-1);
        else {
            s = s.substr(0, s.length()-1);
            reverse(s.begin(), s.end());
        }
    }
    cout << isgood;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

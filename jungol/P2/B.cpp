#include <bits/stdc++.h>
#include <string>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

bool solve() {
    int n; cin >> n;
    bool board[1000] = {0};
    while (true) {
        string s= to_string(n);
        int tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp += (s[i]-'0')*(s[i]-'0');
        }
        if (tmp == 1) return true;
        if (board[tmp]) return false;
        n = tmp;
        board[tmp] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cout << (solve() ? "GREAT" : "STUPID") << "\n";
    }
    return 0;
}

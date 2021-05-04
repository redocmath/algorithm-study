#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve(string a) {
    string ret = "";
    string tmp = "";
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'X') tmp += 'X';
        else {
            if (tmp == "") ret += ".";
            else {
                int cache = tmp.length();
                if (cache % 2) {cout << "-1"; return;}
                while (cache >= 4) {
                    cache -= 4;
                    ret += "AAAA";
                }
                if (cache == 2)
                    ret += "BB.";
                else ret += ".";
            }
            tmp = "";
        }
    }

    int cache = tmp.length();
    if (cache % 2) {cout << "-1"; return;}
    while (cache >= 4) {
        cache -= 4;
        ret += "AAAA";
    }
    if (cache == 2)
        ret += "BB";
    cout << ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    solve(s);
    return 0;
}

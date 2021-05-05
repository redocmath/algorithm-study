#include <bits/stdc++.h>
#include <functional>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n;
vector<string> a;

bool cmp(string s1, string s2) {
    if (s1 + s2 > s2 + s1) return true;
    return false;
}

void solve() {
    sort(a.begin(), a.end(), cmp);
    bool isZero = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != "0") isZero = 0;
    }
    if (isZero) {
        cout << "0";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; 
        a.push_back(s);
    }
    solve();
    return 0;
}

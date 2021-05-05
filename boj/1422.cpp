#include <bits/stdc++.h>
#include <functional>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int k, n;
string head = "";
vector<string> a;

bool cmp(string s1, string s2) {
    if (s1 + s2 > s2 + s1) return true;
    return false;
}

void solve() {
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i];
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        string s; cin >> s; 
        if (!(head.length() > s.length()) && (head.length() < s.length() || head < s)) head = s;
        a.push_back(s);
    }
    for (int i = 0; i < n-k; i++) a.push_back(head);
    solve();
    return 0;
}

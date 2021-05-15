#include <algorithm>
#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n, m;
vector<int> cards;

void solve(int k) {
    int a = upper_bound(cards.begin(), cards.end(), k) - cards.begin();
    int b = lower_bound(cards.begin(), cards.end(), k) - cards.begin();
    cout << a - b << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {int t; cin >> t; cards.push_back(t);}
    sort(cards.begin(), cards.end());
    cin >> m;
    while (m--) {
        int k; cin >> k;
        solve(k);
    }
    return 0;
}

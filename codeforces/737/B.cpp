#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> m;
    for (int i = 0; i < n; i++) m.insert({a[i],i});
    vector<int> arrangeda(n);

    map<int,int>::iterator iter; int cnt = 0;
    for (iter = m.begin(); iter != m.end(); iter++) {
        arrangeda[iter->second] = cnt;
        cnt++;
    }

    cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (arrangeda[i] + 1 == arrangeda[i+1]) {
            cnt++;
        }
    }
    if (k >= n - cnt) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cout << (solve()?"Yes":"No") << "\n";
    }
    return 0;
}

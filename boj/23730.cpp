#include <bits/stdc++.h>
#define DEBUG(i, val) "\e[33mDEBUG: idx = " << i << ", value = " << val << "\e[m\n"
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, m;
V ans, sequ;

void solve() {
    cin >> n >> m;
    ans.resize(n); sequ.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ans[i];

    for (int i = 0; i < m; i++) {
        int t; cin >> t; 
        sequ[t-1] = ans[t-1];
    }

    for (int i = 0; i < n; i++) {
        if (sequ[i]) continue;
        for (int j = 1; j <= 5; j++)
            if (j != ans[i] && (!i || sequ[i-1] != j) && (i == n-1 || sequ[i+1] != j)) {
                sequ[i] = j; break;
            }
    }

   for (int i = 0; i < n; i++)
        cout << sequ[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
 

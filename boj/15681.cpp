#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, r, q;
vector<vector<int>> a;
vector<vector<int>> tree;

int dp[100001];

int solve(int root) {
    int& ret = dp[root];
    if (ret != -1) return ret;

    ret = 1;
    for (int e: tree[root]) {
        ret += solve(e);
    }
    return ret;
}

void construct(int root, int parent) {
    for (int tmp: a[root]) {
        if (tmp == parent) continue;
        tree[root].push_back(tmp);
        construct(tmp, root);
    }
}

int main() {
    fill(dp, dp+100001, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> r >> q; r--;
    a.resize(n);
    tree.resize(n);

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; 
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    construct(r, -1);
    solve(r);

    while (q--) {
        int qu; cin >> qu; qu--;
        cout << dp[qu] << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
int dp[1000001][2];
vector<vector<int>> a;
vector<vector<int>> tree;

int solve(int node, bool early) {
    int &ret = dp[node][early];
    if (ret != -1) return ret;

    if (early) {
        ret = 1;
        for (int e: tree[node]) {
            ret += min(solve(e, 1), solve(e, 0));
        }
        return ret;
    } 
    
    ret = 0;
    for (int e: tree[node]) {
        ret += solve(e, 1);
    }
    return ret;
}

void construct(int root, int parent) {
    for (int child : a[root]) {
        if (child == parent) continue;
        tree[root].push_back(child);
        construct(child, root);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    a.resize(n);
    tree.resize(n);

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    construct(0, -1);
//    for (vector<int> tmp: tree) {
//        for (int tmp2: tmp) {
//            cout << tmp2 << " ";
//        }
//        cout << "\n";
//    }
    cout << min(solve(0, 0), solve(0, 1));
    return 0;
}

#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
int dp[10001][2];

vector<int> population;
vector<V> a;
vector<V> tree;

int solve(int node, bool isgood) {
    int& ret = dp[node][isgood];
    if (ret != -1) return ret;

    if (isgood) {
        ret = population[node];
        for (int child: tree[node]) {
            ret += solve(child, 0);
        }
        return ret;
    }
    ret = 0;
    for (int child: tree[node]) {
        ret += max(solve(child, 1), solve(child, 0));
    }
    return ret;
}

void construct(int root, int parent) {
    for (int e: a[root]) {
        if (e == parent) continue;
        tree[root].push_back(e);
        construct(e, root);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    tree.resize(n);

    for (int i = 0; i < n; i++) {int t; cin >> t; population.push_back(t);}
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    construct(0, -1);
    cout << max(solve(0, 0), solve(0, 1));
    return 0;
}

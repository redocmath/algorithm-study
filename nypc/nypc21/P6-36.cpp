#include <bits/stdc++.h>
#define DEBUG(i, val) "\e[33mDEBUG: " << i << " -> " << val << "\e[m\n"
#define INFO(i, val) "\e[32mINFO: " << i << ", " << val << "\e[m\n"
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, k;
vector<int> a;
vector<vector<int>> tree;
vector<vector<int>> C;

int dp[300001];

void construct(int root, int i, int dir) {
    if (dir && i != n-1) {
        if (a[root] <= a[i + 1] && a[i+1] <= a[root]+k) {
            tree[root].push_back(i+1);
            C[i+1].push_back(root);
            construct(root, i+1, dir);
        }
    }
    if (!dir && i != 0) {
        if (a[root] <= a[i - 1] && a[i-1] <= a[root]+k) {
            tree[root].push_back(i-1);
            C[i-1].push_back(root);
            construct(root, i-1, dir);
        }
    }
}

int solve(int l) {
    if (l >= n) return 0;
    int& ret = dp[l];
    if (ret != -1) return ret;
    ret = INT_MAX;
    for (int e: C[l]) {
        ret = min(ret, 1+solve(tree[e][0]+1));
    }
    return ret;
}

int main() {
    fill(dp, dp+300001, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    tree.resize(n);
    C.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        tree[i].push_back(i);
        C[i].push_back(i);
        if (i != 0)
            construct(i, i, 0);
        if (i != n-1)
            construct(i, i, 1);
        sort(tree[i].begin(), tree[i].end(), greater<int>());
    }

    cout << solve(0);
    return 0;
}

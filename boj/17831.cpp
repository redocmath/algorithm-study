// The first DS Platinum (and without any help :D)
#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
vector<int> a;

vector<int> tmptree;
vector<V> tree;

int dp[200001][2];

int solve(int node, bool isselected) {
    int& tmp = dp[node][isselected];
    if (tmp != -1) return tmp;

    tmp = 0;
    if (isselected) {
        if (tree[node].size() == 0) return tmp;

        int diff = -1987654321;
        int best = -1;
        for (int i = 0; i < tree[node].size(); i++) {
            int tmp2 = a[node]*a[tree[node][i]]+solve(tree[node][i], 0)
                - max(solve(tree[node][i], 1), solve(tree[node][i], 0));
            if (tmp2 > diff) {
                best = i;
                diff = tmp2;
            }
        }

        for (int i = 0; i < tree[node].size(); i++) {
            tmp += max(solve(tree[node][i], 1), solve(tree[node][i], 0));
        }
        tmp -= max(solve(tree[node][best], 0), solve(tree[node][best], 1));
        tmp += a[node]*a[tree[node][best]]+solve(tree[node][best], 0);
        return tmp;
    }
    for (int i = 0; i < tree[node].size(); i++) {
        tmp += max(solve(tree[node][i], 1), solve(tree[node][i], 0));
    }
    return tmp;
}

int main() {
    memset(dp, -1, sizeof(dp));
//    ios::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    tree.resize(n);
    a.resize(n);

    for (int i = 1; i < n; i++) {
        int t; scanf("%d", &t); t--;
        tree[t].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", max(solve(0, 0), solve(0, 1)));
    return 0;
}

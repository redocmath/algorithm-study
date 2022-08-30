#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, m;
int a[3001][3001];
int dp[3001][3001];

int solve(int i, int j) {
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    if (i == n-1 && j == m-1) return ret = 1;
    ret = 0;
    switch (a[i][j]) {
        case 'E'-'A':
            ret = ((ll)ret + (ll)solve(i, j+1)) % 1000000009;
            break;
        case 'S'-'A':
            ret = ((ll)ret + (ll)solve(i+1, j)) % 1000000009;
            break;
        case 'B'-'A':
            ret = ((ll)ret + (ll)solve(i, j+1) + (ll)solve(i+1, j)) % 1000000009;
            break;
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - 'A';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == -1) solve(i, j);
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = (res + dp[i][j]) % 1000000009;
    
    cout << res;
}
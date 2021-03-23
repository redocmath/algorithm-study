#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

enum COLOR {
    RED,
    GREEN,
    BLUE,
};

int n;
vector<vector<int>> a;
int dp[1000][4];

int solve(int i, int last=-1) {
    if (i == n) return 0;
    
    int& tmp = dp[i][last+1];
    if (tmp != -1) return tmp;

    int ret = 123456789;
    for (int j = 0; j < 3; j++) {
        if (last == j) continue;
        ret = min(ret, a[i][j] + solve(i+1, j));
    }
    return tmp = ret;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 1000; i++)
        memset(dp[i],-1, sizeof(dp[i]));
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> tmp(3);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        a.push_back(tmp);
    }

    cout << solve(0);
    return 0;
}

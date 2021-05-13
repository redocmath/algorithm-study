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
int dp[1000][4][4];

int solve(int i, int last=-1, int first=-1) {
    if (i == n) return 0;
    
    int& tmp = dp[i][last+1][first+1];
    if (tmp != -1) return tmp;

    int ret = 123456789;
    for (int j = 0; j < 3; j++) {
        if ((i == n-1 && first == j) || last == j) continue;
        if (i == 0)
            ret = min(ret, a[i][j] + solve(i+1, j, j));
        else
            ret = min(ret, a[i][j] + solve(i+1, j, first));
    }
    return tmp = ret;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 4; j++)
            fill(dp[i][j], dp[i][j]+4, -1);

    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> tmp(3);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        a.push_back(tmp);
    }

    cout << solve(0);
    return 0;
}

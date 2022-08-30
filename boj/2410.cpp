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
#define MOD 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
vector<int> power;
int dp[1000001][21];

int solve(int x, int idx) {
    // cout << x << "\n";
    int &ret = dp[x][idx];
    if (x == 0) return 1;
    if (ret != -1) return ret;
    ret = 0;
    for (int i = idx; i < power.size() && x - power[i] >= 0; i++)
        ret = (ret + solve(x-power[i], i) % MOD) % MOD;
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    int a = 1;
    while (a < 1000000) {
        power.push_back(a);
        a *= 2;
    }
    
    cout << solve(n, 0);
}
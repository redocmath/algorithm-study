// 11:04
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

int n;
vector<int> a;
int dp[1001][1001];
bool choice[1001][1001];

int solve(int idx, int size) {
    int &ret = dp[idx][size];
    if (ret != -1) return ret;
    if (idx == n) return 0;

    ret = solve(idx+1, size);
    choice[idx][size] = 0;
    if (a[idx] > size) {
        if (1+solve(idx+1, a[idx]) > ret) {
            ret = 1+solve(idx+1, a[idx]);
            choice[idx][size] = 1;
        }
    }
    return ret;
}

void construct(int idx, int size) {
    if (idx == n) return;
    if (choice[idx][size]) {
        cout << a[idx] << " ";
        construct(idx+1, a[idx]);
        return;
    }
    construct(idx+1, size);
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0, 0) << "\n";
    construct(0, 0);
}
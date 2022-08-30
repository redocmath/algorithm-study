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
int dp[10001]; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t, K; cin >> t >> K;
    vector<P> coin(K);
    for (int i = 0; i < K; i++) {
        cin >> coin[i].first >> coin[i].second;
    }

    dp[0] = 1;
    for (int i = 0; i < K; i++) {
        for (int j = t; j >= 0; j--)
            for (int k = 1; k <= coin[i].second && j-coin[i].first*k >= 0; k++)
                dp[j] += dp[j- coin[i].first * k];
    }

    cout << dp[t];
}
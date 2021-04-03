#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        queue<pair<int, int>> Q;
        for (int i=0; i<n;i++) {
            int tmp; cin >> tmp;
            Q.push(make_pair(i, tmp));
        }

        int cnt = 1;
        while (!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();
            queue<pair<int, int>> q;
            q = Q;

            bool isPrior = true;

            while (!q.empty()) {
                pair<int, int> now = q.front();
                if (now.second > cur.second) {
                    isPrior = false;
                    break;
                }
                q.pop();
            }

            if (!isPrior) Q.push(cur);
            else {
                if (cur.first == m) cout << cnt << "\n";
                cnt++;
            }
        }
    }
}
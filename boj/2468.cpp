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
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, a[100][100];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    int cnt = 0;
    for (int h = 0; h <= 100; h++) {
        int tmp = 0;
        queue<P> que;
        bool visited[100][100] = {0, };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && a[i][j] > h) {
                    tmp++;
                    que.push({i, j});
                    while (!que.empty()) {
                        P cur = que.front(); que.pop();
                        if (0 <= cur.first && cur.first <= n-1 &&
                            0 <= cur.second && cur.second <= n-1 &&
                            !visited[cur.first][cur.second] && a[cur.first][cur.second] > h) {
                            visited[cur.first][cur.second] = true;

                            que.push({cur.first + 1, cur.second});
                            que.push({cur.first - 1, cur.second});
                            que.push({cur.first, cur.second + 1});
                            que.push({cur.first, cur.second - 1});
                        }
                    }
                }
            }
        }
        cnt = max(cnt, tmp);
    }
    cout << cnt;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m, ret = -1; // ver hor
int board[10][10];
bool vis[10][10];
bool vis_forbfs[10][10];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs() {
    for (int i = 0; i < 10; i++)
        fill(vis_forbfs[i], vis_forbfs[i]+10, 0);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) {
                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis_forbfs[i][j] = 1;

                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nv = cur.first + dy[i];
                        int nh = cur.second + dx[i];

                        if (nv < 0 || nv >= n || nh < 0 || nh >= m) continue;
                        if (vis_forbfs[nv][nh] || board[nv][nh] != 0 || vis[nv][nh]) continue;

                        vis_forbfs[nv][nh] = 1;
                        Q.push({nv, nh});
                    }
                }
            }
        }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && !vis_forbfs[i][j] && !vis[i][j]) cnt++;
        }

    return cnt;
}

void solve(int k) {
    if (k == 3) {
        ret = max(ret, bfs());
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || board[i][j] != 0) continue;
            vis[i][j] = 1;
            solve(k+1);
            vis[i][j] = 0;
        }
}
int main() {
    for (int i = 0; i < 10; i++)
        fill(vis[i], vis[i] + 10, 0);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    solve(0);
    cout << ret;
    return 0;
}

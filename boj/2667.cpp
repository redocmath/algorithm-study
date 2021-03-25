#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int board[50][50];
        bool vis[50][50];

        int m, n, k; cin >> m >> n >> k;

        for (int i = 0; i < n; i++) 
            fill(board[i], board[i]+m, 0);

        for (int i = 0; i < n; i++) 
            fill(vis[i], vis[i]+m, false);

        for (int i = 0; i < k; i++) {
            int a, b; cin >> a >> b;
            board[b][a] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] && !vis[i][j]) {
                    queue<pair<int, int>> Q;
                    vis[i][j] = true;
                    Q.push({i, j});

                    while (!Q.empty()) {
                        pair<int, int> cur = Q.front(); Q.pop();
                        for (int k = 0; k < 4; k++) {
                            int ny = cur.first + dy[k];
                            int nx = cur.second + dx[k];

                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;  
                            if(vis[ny][nx] || board[ny][nx] != 1) continue; 

                            vis[ny][nx] = true;
                            Q.push({ny,nx});
                        }
                    }
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

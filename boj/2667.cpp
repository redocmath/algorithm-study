#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int board[25][25];
bool vis[25][25];

int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        for (int j = 0; j < n; j++) {
            board[i][j] = (a[j] == '0' ? 0 : 1);
        }
    }

    int cnt = 0; vector<int> tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] && !vis[i][j]) {
                queue<pair<int, int>> Q;
                vis[i][j] = true;
                Q.push({i, j});

                int tmpp = 0;
                while (!Q.empty()) {
                    tmpp++;
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;  
                        if(vis[nx][ny] || board[nx][ny] != 1) continue; 

                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
                cnt++;
                tmp.push_back(tmpp);
            }
        }
    }

    sort(tmp.begin(), tmp.end());
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << tmp[i] << "\n";
    }
    return 0;
}

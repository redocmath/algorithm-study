#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int board[100][100];
int nboard[100][100];

bool vis[100][100];
bool nvis[100][100];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i]+n, false);
        fill(nvis[i], nvis[i]+n, false);
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'R') {
                board[i][j] = 0;
                nboard[i][j] = 0;
            } else if (s[j] == 'G') {
                board[i][j] = 1;
                nboard[i][j] = 0;
            } else {
                board[i][j] = 2;
                nboard[i][j] = 1;
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            cnt++;
            const int color = board[i][j];

            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int k = 0; k < 4; k++) {
                    int ny = cur.first + dy[k];
                    int nx = cur.second + dx[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[ny][nx] || board[ny][nx] != color) continue;
                    vis[ny][nx] = 1;
                    Q.push({ny, nx});
                }
            }
        }
    }

    cout << cnt << " ";
    cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nvis[i][j]) continue;
            cnt++;
            const int color = nboard[i][j];

            queue<pair<int, int>> Q;
            nvis[i][j] = 1;
            Q.push({i, j});

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int k = 0; k < 4; k++) {
                    int ny = cur.first + dy[k];
                    int nx = cur.second + dx[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (nvis[ny][nx] || nboard[ny][nx] != color) continue;
                    nvis[ny][nx] = 1;
                    Q.push({ny, nx});
                }
            }
        }
    }

    cout << cnt;
    return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int board[100][100];
bool vis[100][100];

int n, m; // m: ver, n: hor

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    for (int i = 0; i < 100; i++) fill(board[i], board[i]+100, 1);
    for (int i = 0; i < 100; i++) fill(vis[i], vis[i]+100, false);

    ios::sync_with_stdio(false);
    cin >> m >> n;

    int k; cin >> k;

    for (int i = 0; i < k; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        for (int j = (m-d); j < (m-b); j++) fill(board[j]+a, board[j]+c, 0);
    }

    vector<int> A; int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || !board[i][j]) continue;
            cnt++;
            queue<pair<int, int>> Q;

            vis[i][j] = true;
            Q.push({i, j});

            int tmp = 1;
            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.second + dx[i];
                    int ny = cur.first + dy[i];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[ny][nx] || !board[ny][nx]) continue;

                    vis[ny][nx] = true;
                    Q.push({ny, nx});
                    tmp++;
                }
            }
            A.push_back(tmp);
        }
    }

    sort(A.begin(), A.end());
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
        cout << A[i] << " ";

    return 0;
}

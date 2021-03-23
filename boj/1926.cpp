#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <queue>
typedef long long ll;
using namespace std;

int n, m;
int board[500][500];
bool vis[500][500];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && board[i][j]) {
                queue<pair<int,int> > Q;
                vis[i][j] = 1; 
                Q.push({i,j});
                int tmp = 1;
                while (!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){ 
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir]; 
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                        if(vis[nx][ny] || board[nx][ny] != 1) continue; 
                        vis[nx][ny] = 1; 
                        Q.push({nx,ny});
                        tmp++;
                    }
                }
                mx = max(mx, tmp);
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << mx;
    return 0;
}

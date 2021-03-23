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
int board[100][100];
int dist[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        for (int j = 0; j < m; j++) {
            board[i][j] = (a[j] == '1' ? 1 : 0);
        }
    }
    for (int i = 0; i < n; i++) fill(dist[i], dist[i]+m, -1);
    queue<pair<int,int> > Q;
    Q.push({0,0});
    dist[0][0] = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1]+1;
    return 0;
}

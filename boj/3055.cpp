#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int r, c; // ver, hor
int board[50][50];
int dist_w[50][50];
int dist_s[50][50];
bool available[50][50];
int dist_a[50][50];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<P> waterpos;
P cave, poss;

void solve() {
    // bfs 1: water
    queue<P> Q;
    for (int i = 0; i < waterpos.size(); i++) {
        P water = waterpos[i];
        dist_w[water.first][water.second] = 0;
        Q.push(P(water.first, water.second));
    }

    while(!Q.empty()) {
        P cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nver = cur.first + dy[i];
            int nhor = cur.second + dx[i];

            if (nver < 0 || nver >= r || nhor < 0 || nhor >= c) continue;
            if (board[nver][nhor] == 1 || board[nver][nhor] == 2) continue;
            if (dist_w[nver][nhor] >= 0) continue;

            dist_w[nver][nhor] = dist_w[cur.first][cur.second]+1;
            Q.push({nver, nhor});
        }
    }

    queue<P> QQ;
    dist_s[poss.first][poss.second] = 0;
    QQ.push(P(poss.first, poss.second));
    while(!QQ.empty()) {
        P cur = QQ.front(); QQ.pop();
        for (int i = 0; i < 4; i++) {
            int nver = cur.first + dy[i];
            int nhor = cur.second + dx[i];

            if (nver < 0 || nver >= r || nhor < 0 || nhor >= c) continue;
            if (board[nver][nhor] == 1) continue;
            if (dist_s[nver][nhor] >= 0) continue;

            dist_s[nver][nhor] = dist_s[cur.first][cur.second]+1;
            QQ.push({nver, nhor});
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dist_s[i][j] < dist_w[i][j]) available[i][j] = true;
            else available[i][j] = false;
        }
    }

    available[cave.first][cave.second] = true;

    queue<P> FQ;
    dist_a[poss.first][poss.second] = 0;
    FQ.push(P(poss.first, poss.second));
    while(!FQ.empty()) {
        P cur = FQ.front(); FQ.pop();
        for (int i = 0; i < 4; i++) {
            int nver = cur.first + dy[i];
            int nhor = cur.second + dx[i];

            if (nver < 0 || nver >= r || nhor < 0 || nhor >= c) continue;
            if (!available[nver][nhor]) continue;
            if (dist_a[nver][nhor] >= 0) continue;

            dist_a[nver][nhor] = dist_a[cur.first][cur.second]+1;
            FQ.push({nver, nhor});
        }
    }
}

int main() {
    for (int i = 0; i < 50; i++) {
        fill(dist_a[i], dist_a[i]+50, -1);
        fill(dist_w[i], dist_w[i]+50, -1);
        fill(dist_s[i], dist_s[i]+50, -1);
    }
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '.') board[i][j] = 0;
            if (s[j] == 'X') board[i][j] = 1;
            if (s[j] == 'D') {
                cave = P(i, j);
                board[i][j] = 2;
            }
            if (s[j] == 'S') {
                poss = P(i, j);
                board[i][j] = 3;
            }
            if (s[j] == '*') {
                board[i][j] = 4;
                waterpos.push_back(P(i, j));
            }
        }
    }
    solve();
    if (dist_a[cave.first][cave.second] == -1) cout << "KAKTUS";
    else cout << dist_a[cave.first][cave.second]; 
    return 0;
}

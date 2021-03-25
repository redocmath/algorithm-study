#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int board[1000][1000];
int vis[1000][1000];

int r, c;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin >> r >> c;

    pair<int, int> J, F;

    for (int i = 0; i < r; i++) {
        string a; cin >> a;
        for (int j = 0; j < c; j++) {
            if (a[j] == '#') board[i][j] = 0;
            else if (a[j] == '.') board[i][j] = 1;
            else if (a[j] == 'j') {
                board[i][j] = 1;
                J = {i, j};
            } else {
                board[i][j] = 1;
                F = {i, j};
            }
        }
    }
    return 0;
}

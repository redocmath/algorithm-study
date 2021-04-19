#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int m, n;
int dp[500][500];
int board[500][500];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solve(int a, int b) {
    int& tmp = dp[a][b];
    if (tmp != -1) return tmp;
    if (a == m-1 && b == n-1) return 1;

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int na = a + dy[i];
        int nb = b + dx[i];

        if (na < 0 || na >= m || nb < 0 || nb >= n) continue;
        if (board[na][nb] >= board[a][b]) continue;
        ret += solve(na, nb);
    }

    return tmp = ret;
}

int main() {
    for (int i = 0; i < 500; i++)
        fill(dp[i], dp[i]+500, -1);

    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    cout << solve(0, 0);
    return 0;
}

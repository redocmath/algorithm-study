#include <bits/stdc++.h>
#define ODD 1
#define EVEN 0
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n, m;
bool board[1000][1000];
bool oddityv[1000], oddityh[1000];

int solve() {
    int odd_h = 0, even_h = 0, odd_v = 0, even_v = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) cnt += board[i][j];
        oddityh[i] = (cnt % 2 ? ODD : EVEN);
        if (cnt % 2) odd_h++;
        else even_h++;
    }

    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) cnt += board[j][i];
        oddityv[i] = (cnt % 2 ? ODD : EVEN);
        if (cnt % 2) odd_v++;
        else even_v++;
    }

    if (odd_h > even_h) {
        ret += even_h;
        if (even_h % 2) {
            if (even_v % 2) return ret + even_v;
            else return -1;
        }
        else {
            if (odd_v % 2) return ret + odd_v;
            else return -1;
        }
    }
    else {
        ret += odd_h;
        if (odd_h % 2) {
            if (even_v % 2 == 0) return ret + even_v;
            else return -1;
        }
        else {
            if (odd_v % 2 == 0) return ret + odd_v;
            else return -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            board[i][j] = s[j] - '0';
    }
    if (n == m && n == 1) cout << 1 - board[0][0];
    else if (n == 1) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += board[0][i];
        }
        cout << (cnt % 2);
    }
    else cout << solve();
    return 0;
}

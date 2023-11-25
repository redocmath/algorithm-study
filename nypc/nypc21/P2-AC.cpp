#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, m;
vector<vector<pair<int, int>>> rec;

bool solve() {
    for (vector<pair<int, int>> e: rec) {
        bool isPlaying = false; int playedT = -1;
        for (int i = 0; i < e.size(); i++) {
            if (e[i].second == 0) {
                if (isPlaying) return 0;
                isPlaying = true; playedT = e[i].first;
            }
            else {
                if (isPlaying == 0) return 0;
                if (e[i].first-playedT < 60) return 0;
                isPlaying = false; playedT = -1;
            }
        }
        if (isPlaying) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rec.resize(n);
    while (m--) {
        int t, i, s; cin >> t >> i >> s; i--;
        rec[i].push_back({t, s});
    }
    cout << (solve() ? "YES" : "NO");
    return 0;
}

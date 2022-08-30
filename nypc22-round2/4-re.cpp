#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m, k, q;

vector<bool> isfishin;
vector<pair<P, P>> fisharea; // r1 c1 r2 c2
vector<ll> fish;
vector<vector<ll>> segtree;
ll A[5001][5001];

int main() {
    // memset(psum, 0ll, sizeof(psum));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k >> q;
    fish.resize(k+1);
    isfishin.resize(k+1);
    fisharea.resize(k+1);
    
    while (q--) {
        int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        if (a == 1) {
            isfishin[b] = true;
            fisharea[b] = {{c, d}, {e, f}};
            for (int i = c; i <= e; i++) {
                for (int j = d; j <= f; j++) {
                    A[i][j]++;
                }
            }
        } else if (a == 2) {
            isfishin[b] = false;
            for (int i = c; i <= e; i++) {
                for (int j = d; j <= f; j++) {
                    A[i][j]--;
                }
            }
        }
        for (int i = 1; i <= k; i++) {
            if (!isfishin[i]) continue;
            for (int j = fisharea[i].first.first; j <= fisharea[i].second.first; j++) {
                for (int l = fisharea[i].first.second; l <= fisharea[i].second.second ; l++)
                    fish[i] += A[j][l]-1;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout << A[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // for (int i = 0; i < k; i++) cout << fish[i] << " ";
        // cout << "\n";
    }
    for (int i = 1; i <= k; i++) cout << fish[i] << "\n";
}
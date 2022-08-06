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

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<int> V = {0, 1};
vector<int> Q;

void solve(int n) {
    if (n == 0) return;
    for (int i = 0; i < V.size(); i++) {
        if (V[i] <= n) {
            Q.push_back(V[i]);
            solve(n-V[i]);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true) {
        if ((ll)(V[V.size()-1] + V[V.size()-2]) > 1000000000) break;
        V.push_back(V[V.size()-1] + V[V.size()-2]);
    }

    sort(V.begin(), V.end(), greater<int>());
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(n);
        for (int i = Q.size()-1; i >= 0; i--)
            cout << Q[i] << " ";
        cout << "\n";
        Q.clear();
    }
}
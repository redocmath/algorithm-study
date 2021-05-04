#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

vector<P> ord;
vector<int> Y;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ord.push_back(P(x, y));
    }

    sort(ord.begin(), ord.end());

    for (int i = 0; i < N; i++) {
        P pos = ord[i]; int x = pos.first, y = pos.second;
        auto iter = upper_bound(Y.begin(), Y.end(), y);
        if (iter == Y.begin()) {
            Y.insert(iter, y);
        } else {
            Y.erase(Y.begin() + 1, iter);
        }
    }

    cout << Y.size();
    return 0;
}

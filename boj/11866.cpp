#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k; cin >> n >> k;
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        Q.push(i);
    }

    vector<int> a;

    while (!Q.empty()) {
        for (int i = 0; i < k-1; i++) {
            Q.push(Q.front());
            Q.pop();
        }

        a.push_back(Q.front());
        Q.pop();
    }

    cout << "<";
    for (int i = 0; i < n-1; i++) {
        cout << a[i] << ", ";
    }
    cout << a[n-1] << ">";
}
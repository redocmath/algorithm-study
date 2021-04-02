#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;

    queue<int> Q;
    for (int i = 0; i < n; i++) Q.push(i+1);

    while (Q.size() != 1) {
        Q.pop();
        int tmp = Q.front();
        Q.pop();
        Q.push(tmp);
    }

    cout << Q.front();
    return 0;
}

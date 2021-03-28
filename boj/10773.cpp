#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int k; cin >> k;
    stack<int> S;

    while (k--) {
        int tmp; cin >> tmp;
        if (tmp == 0) S.pop();
        else S.push(tmp);
    }

    int cnt = 0;
    while (!S.empty()) {
        cnt += S.top();
        S.pop();
    }
    cout << cnt;
    return 0;
}

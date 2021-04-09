#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') a[i] = 0;
        else a[i] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) continue;
        for (int j = (i < k ? 0: i-k); j <= (i + k >= n ? n : i+k); j++) {
            if (a[j] == 1) {
                a[j] = -1;
                cnt++;
                break;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}

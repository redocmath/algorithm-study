#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    // all triangle := nC3 = n*(n-1)*(n-2)/6
    // exclude: Cases two edges of different colors are connected /2
    // store at variable(cnt) and calculate sum.

    int t; cin >> t;
    while(t--) {
        int cnt[1005];
        cin >> n;
        ll colorful = 0;

        for (int i = 0; i < n; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int tmp; cin >> tmp;
                cnt[i] += tmp;
                cnt[j] += tmp;
            }
        }

        for(int i = 0; i < n; i++) colorful += cnt[i] * (n - 1 - cnt[i]);
        cout << n*(n-1)*(n-2)/6-colorful/2 << "\n";
    }
    return 0;
}

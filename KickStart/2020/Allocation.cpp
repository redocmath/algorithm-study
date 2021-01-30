#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, b;

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> b;
        vector<int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        sort(a.begin(), a.end());

        int ans = 0; int idx = 0;
        while(true) {
            ans += a[idx];
            b -= a[idx];

            if (b < 0) break;
            idx++;
        }

        cout << "Case #" << i+1 << ": " << idx << endl;
    }
    return 0;
}

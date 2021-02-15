#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        for (int i = 1; i < n+1; i++) {
            if (i == n) 
                cout << "0\n";

            else if (a[i] > a[i - 1]) {
                cout << n - i << "\n";
                break;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    while (true) {
        int n; cin >> n;
        if (n == -1) break;
    
        vector<int> factor;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                factor.push_back(i);
            }
        }
        if (accumulate(factor.begin(), factor.end(), 0) == n) {
            cout << n << " = " << factor[0] << " ";
            for (int i = 1; i < factor.size(); i++) {
                cout << "+ " << factor[i] << " ";
            }
            cout << "\n";
            continue;
        }
        cout << n << " is NOT perfect.\n";
    }
    return 0;
}

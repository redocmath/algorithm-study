#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    if (n == 0 || n == 1) cout << n;
    else {
        int p1 = 0, p2 = 1;
        for (int i = 1; i < n; i++) {
            int tmp = (p1 + p2) % MOD;
            p1 = p2;
            p2 = tmp;
        }
        cout << p2;
    }
    return 0;
}

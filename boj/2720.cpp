#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int c; cin >> c;
        int qu = c / 25;
        c %= 25;
        int dm = c / 10;
        c %= 10;
        int nc = c / 5;
        c %= 5;
        int pn = c / 1;

        cout << qu << " " << dm << " " << nc << " " << pn << "\n";
    }
}
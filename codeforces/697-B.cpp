#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, end) for (int i = 0; i < (end); i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    FOR(i, T) {
        int n; cin >> n;
        if (n < 2020) {
            cout << "NO" << endl;
            continue;
        }
        if (n % 2020 == 0 || n % 2021 == 0) {
            cout << "YES" << endl;
            continue;
        }
        if (n < 4041) {
            cout << "NO" << endl;
            continue;
        }
        bool isRight = false;
        while (true) {
            n -= 4041;
            if (n < 0) break;
            if (n == 0 || n % 2020 == 0 || n % 2021 == 0) {
                isRight = true;
                break;
            }
        }

        if (isRight) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

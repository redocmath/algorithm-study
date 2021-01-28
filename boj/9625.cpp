#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int k; cin >> k;

    long long a[46], b[46];
    a[0] = 1; b[0] = 0;
    a[1] = 0; b[1] = 1;

    for (int i = 2; i <= k; i++) {
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
    }

    cout << a[k] << " " << b[k] << endl;

    return 0;
}

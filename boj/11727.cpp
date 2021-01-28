#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int cache[1001] = {0, };

    cache[1] = 1;
    cache[2] = 3;

    for (int i = 3; i <= n; i++) {
        cache[i] = (cache[i - 1] + 2 * cache[i - 2]) % 10007;
    }

    cout << cache[n] << endl;
    return 0;
}

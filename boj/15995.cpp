#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 10000000

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int a, m; cin >> a >> m;
    int i;
    for (i = 1; i <= MAX; i++) {
        if ((a * i - 1) % m == 0) break;
    }

    cout << i;
    return 0;
}

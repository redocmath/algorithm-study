#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    ll ret = 0;

    while(n--) {
        int tmp, tmp2; cin >> tmp >> tmp2;
        ret += tmp*tmp2;
    }

    cout << ret;
    return 0;
}

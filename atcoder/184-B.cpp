#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, x; cin >> n >> x;
    string a; cin >> a;

    ll ret = x;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'o') ret++;
        else ret = (ret == 0 ? 0 : ret-1);
    }
    cout << ret;
    return 0;
}

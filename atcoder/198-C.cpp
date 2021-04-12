#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int r, x, y; cin >> r >> x >> y;
    ll ret = x*x+y*y;
    long double dist = sqrt(ret);
    if (dist < r) {
        cout << 2;
        return 0;
    }
    int tmp = ceil(dist/r);

    cout << tmp;
    return 0;
}

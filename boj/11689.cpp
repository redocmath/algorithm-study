#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

ll n, ret, k = 2;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ret = n;
    while (k * k <= n) {
        if (!(n % k)) 
            ret = ret * (k - 1) / k;
        while (!(n % k))
            n /= k;
        k++;
    }

    // if n is prime.
    if (n != 1) {
        ret = ret * (n - 1) / n;
    }

    cout << ret;
    return 0;
}

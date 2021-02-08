#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a%b));
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) 
        cout << a[0] / gcd(a[0], a[i]) << "/" << a[i] / gcd(a[0], a[i]) << endl;
    return 0;
}

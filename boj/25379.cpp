#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // even - odd
    ll cnta = 0, biasa = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cnta += i-biasa;
            biasa++;
        }
    }

    // odd - even
    ll cntb = 0, biasb = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
            cntb += i-biasb;
            biasb++;
        }
    }

    cout << min(cnta, cntb);
}
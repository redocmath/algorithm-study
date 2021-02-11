// unsuccessful
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

bool find(ll a, vector<ll>& arr) {
    int beg, end; beg = 0; end = arr.size() - 1;
    while (end >= beg) {
        if (end == beg) break;
        int mid = (end + beg) / 2
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> A(n);

    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {

    }
    return 0;
}

#include <bits/stdc++.h>
#include <numeric>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

double solve(vector<int>& v) {
    long double mx = -987654321;
    vector<long double> pdx(v.size());
    pdx[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
        pdx[i] = pdx[i-1]+v[i];
    }
    for (int i = 0; i < v.size()-1; i++) {
        long double var = 0;
        var += pdx[i] / (i+1);
        var += (pdx[v.size()-1]-pdx[i]) / (v.size()-i-1);
        mx = max(mx, var);
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(9);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a) << "\n";
    }
    return 0;
}

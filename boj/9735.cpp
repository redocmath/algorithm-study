#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    cout << fixed;
    cout.precision(4);

    while (t--) {
        ll a,b,c,d; cin >> a >> b >> c >> d;
        long double x1; 

        for (int i = -1000000; i <= 1000000; i++) {
            ll tmpa = a, tmpb = b, tmpc = c, tmpd = d;
            __int128 tmp = a * i;
            b = b + tmp;
            tmp = b * i;
            c = c + tmp;
            tmp = (__int128)c * i;
            if (d+tmp == 0) {
                x1 = (long double)i;
                break;
            } else {
                a = tmpa;
                b = tmpb;
                c = tmpc;
                d = tmpd;
            }
        } 
        __int128 D = (__int128)b*b - (__int128)4*a*c;
        vector<long double> x;

        if (D < 0) cout << x1 << "\n";
        else if (D == 0) {
            long double x2;
            x2 = (long double)(-1 * b)/(long double)(2*a);
            x.push_back(x1);
            if (abs(x1-x2) >= 0.00005) x.push_back(x2);
            sort(x.begin(), x.end());
            for (int i = 0; i < x.size(); i++) {
                cout << x[i] << " ";
            }
        } else {
            long double x2, x3;
            x2 = (long double)(-1 * b + sqrt(D)) / (long double)(2*a);
            x3 = (long double)(-1 * b - sqrt(D)) / (long double)(2*a);
            x.push_back(x1);
            if (abs(x1-x2) >= 0.00005) x.push_back(x2);
            if (abs(x2-x3) >= 0.00005 && abs(x1-x3) >= 0.00005) x.push_back(x3);
            sort(x.begin(), x.end());
            for (int i = 0; i < x.size(); i++) {
                cout << x[i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

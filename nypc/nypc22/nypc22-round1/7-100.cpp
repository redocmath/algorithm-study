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
#include <deque>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<vector<ll>> f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        ll n, a, b; cin >> n >> a >> b;
        ll _layera = floor(sqrt(n*n-a)), _layerb = floor(sqrt(n*n-b));

        if (n % 2 == 0) { // even
            ll layera = n/2-1-floor(_layera/2), sta = 4*layera*(n-layera)+1;
            ll layerb = n/2-1-floor(_layerb/2), stb = 4*layerb*(n-layerb)+1;

            ll xa, ya, xb, yb;
            if (a >= sta+(n-2*layera-1)*3) xa = layera, ya = n-1-layera - (a - (sta+(n-2*layera-1)*3));
            else if (a >= sta+(n-2*layera-1)*2) xa = n-1-layera - (a - (sta+(n-2*layera-1)*2)), ya = n-1-layera;
            else if (a >= sta+(n-2*layera-1)) xa = n-1-layera, ya = layera + (a - (sta+(n-2*layera-1)));
            else xa = layera + a - sta, ya = layera;

            if (b >= stb+(n-2*layerb-1)*3) xb = layerb, yb = n-1-layerb - (b - (stb+(n-2*layerb-1)*3));
            else if (b >= stb+(n-2*layerb-1)*2) xb = n-1-layerb - (b - (stb+(n-2*layerb-1)*2)), yb = n-1-layerb;
            else if (b >= stb+(n-2*layerb-1)) xb = n-1-layerb, yb = layerb + (b - (stb+(n-2*layerb-1)));
            else xb = layerb + b - stb, yb = layerb;

            // cout << "(" << xa << "," << ya << "), " << "(" << xb << "," << yb << ")\n";
            if (abs(xa-xb) == abs(ya-yb)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            ll layera = (n-1)/2-ceil((long double)_layera/(long double)2), sta = 4*layera*(n-layera)+1;
            ll layerb = (n-1)/2-ceil((long double)_layerb/(long double)2), stb = 4*layerb*(n-layerb)+1;

            ll xa, ya, xb, yb;
            if (a >= sta+(n-2*layera-1)*3) xa = layera, ya = n-1-layera - (a - (sta+(n-2*layera-1)*3));
            else if (a >= sta+(n-2*layera-1)*2) xa = n-1-layera - (a - (sta+(n-2*layera-1)*2)), ya = n-1-layera;
            else if (a >= sta+(n-2*layera-1)) xa = n-1-layera, ya = layera + (a - (sta+(n-2*layera-1)));
            else xa = layera + a - sta, ya = layera;

            if (b >= stb+(n-2*layerb-1)*3) xb = layerb, yb = n-1-layerb - (b - (stb+(n-2*layerb-1)*3));
            else if (b >= stb+(n-2*layerb-1)*2) xb = n-1-layerb - (b - (stb+(n-2*layerb-1)*2)), yb = n-1-layerb;
            else if (b >= stb+(n-2*layerb-1)) xb = n-1-layerb, yb = layerb + (b - (stb+(n-2*layerb-1)));
            else xb = layerb + b - stb, yb = layerb;

            // cout << _layera/2 << " " << _layerb/2 << " " << layera << " " << layerb << " " << sta << " " << stb << "\n";
            // cout << "(" << xa << "," << ya << "), " << "(" << xb << "," << yb << ")\n";
            if (abs(xa-xb) == abs(ya-yb)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
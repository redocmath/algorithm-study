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
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, m; ll s;
vector<pair<string, ll>> body;
vector<pair<string, ll>> handle;
vector<pair<string, ll>> wheel;
vector<pair<string, ll>> engine;
vector<pair<string, ll>> booster;
vector<pair<pair<string, string>, ll>> synergy;

pair<ll, vector<string>> solve() {
    ll mindiff = 2000000000000000000, sum = 0;
    vector<string> mind;
    for (int _body = 0; _body < body.size(); _body++) {
        if (_body-s >= mindiff) continue;
        for (int _handle = 0; _handle < handle.size(); _handle++) {
            if (_body+_handle-s >= mindiff) continue;
            for (int _wheel = 0; _wheel < wheel.size(); _wheel++) {
                if (_body+_handle+_wheel-s >= mindiff) continue;
                for (int _engine = 0; _engine < engine.size(); _engine++) {
                    if (_body+_handle+_wheel+_engine-s >= mindiff) continue;
                    for (int _booster = 0; _booster < booster.size(); _booster++) {
                        ll _sum = body[_body].second + handle[_handle].second + wheel[_wheel].second + engine[_engine].second + booster[_booster].second;
                        vector<string> _mind = {body[_body].first, handle[_handle].first, wheel[_wheel].first, engine[_engine].first, booster[_booster].first};
                        for (int i = 0; i < m; i++) {
                            if (find(_mind.begin(), _mind.end(), synergy[i].first.first) != _mind.end()
                            && find(_mind.begin(), _mind.end(), synergy[i].first.second) != _mind.end()) {
                                _sum += synergy[i].second;
                            }
                        }
                        if (abs(_sum-s) < mindiff) {
                            mind = _mind;
                            mindiff = abs(_sum-s);
                            sum = _sum;
                        }
                    }
                }
            }
        }
    }

    return {sum, mind};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b; ll s;
        cin >> a >> b >> s;
        if (a == "Body") body.push_back({b, s});
        if (a == "Handle") handle.push_back({b, s});
        if (a == "Wheel") wheel.push_back({b, s});
        if (a == "Engine") engine.push_back({b, s});
        if (a == "Booster") booster.push_back({b, s});
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string a, b; ll s;
        cin >> a >> b >> s;
        synergy.push_back({{a, b}, s});
    }
    cin >> s;
    pair<ll, vector<string>> res = solve();
    // cout << res.first << "\n";
    for (int i = 0; i < 5; i++) cout << res.second[i] << "\n";
}
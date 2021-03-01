#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

ll ret[21] = {-1, 1, 9, 89, 89, 589, 3089, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

ll mod_(ll a, ll b, ll mod) {
    ll ret = 1;
    a %= mod;
    while(b != 0){
        if(b & 1) 
            ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod; 
    }
    return ret;
}

void getRet(ll R) {
    int a = 1;
    while (true) {
        string now = to_string(mod_(2, a, mod_(10, R+1, pow(10, 21))));
        bool isCorrect = true;
        if (now.length() > R) {
            for (int i = now.length()-1; i >= now.length()-R; i--) {
                if (now[i] != '1' && now[i] != '2') {
                    isCorrect = false;
                    break;
                }
            }
            if (isCorrect) {
                ret[R] = a;
                return;
            }
            else a++;
        } else {
            a++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    getRet(15);
    cout << ret[15];
    return 0;
}

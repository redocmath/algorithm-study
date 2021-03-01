#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MOD 1000000007
typedef long long ll;
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    int a, b; cin >> a >> b;

    ll ret = 1;
    a %= MOD;
    while(b != 0){
        if(b & 1) 
            ret = (ret * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD; 
    }
    cout << ret;
    return 0;
}

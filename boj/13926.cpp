// not solve
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> factors;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

ll modpow(ll a, ll e, ll m) {
    __int128_t r = 1, b = a % m;
    while (e > 0) {
        if (e & 1)
            r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

bool check_composite(ll n, ll a, ll d, int s) {
    auto x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128_t)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool isPrime_MillerRabin(ll x) {
    if (x < 2)
        return false;
    int r = 0;
    ll d = x - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (x == a)
            return true;
        if (check_composite(x, a, d, r))
            return false;
    }
    return true;
}

ll f(ll x, ll c, ll mod) {
    return ((__int128_t)x * x % mod + c) % mod;
}

ll rho(ll n, ll x0 = 2, ll c = 1) {
    ll x = x0;
    ll y = x0;
    ll g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(abs(x - y), n);
    }
    return g;
}

void factorize(ll n) {
    if (n == 1) return;
    if (isPrime_MillerRabin(n)) {
        factors.push_back(n);
        cout << n << endl;
        return;
    }
    
    ll x, y, c, g = n;
    
    auto f = [=](ll x) {
        return ((__int128_t)x * x % n + c) % n;
    };
    do {
        if (g == n) {
            x = y = rand() % (n - 2);
            c = rand() % 10 + 1;
            g = 1;
        }
        x = f(x);
        y = f(f(y));
        g = gcd(abs(x - y), n);
    } while (g == 1);
    factorize(g);
    factorize(n / g);
}

int main() {
	ll n;
	cin >> n;
	ll pi = n;
	ll k = 2;

	while (n != 1) {
	    k = rho(n);
	    factorize(k);

	    for (int i = 0; i < factors.size(); i++) {
	        ll prime = factors[i];
            if (n % prime == 0)
                pi = pi / prime * (prime - 1);
            while (n % prime == 0) 
                n = n / prime;
            prime++;
	    }
	}

	if (n != 1) { 
		pi = pi / n * (n - 1);
	}
	cout << pi;
}

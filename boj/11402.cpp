#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, R, P; 
    cin >> N >> R >> P;
    vector<long long> f(P, 1);

    // Use Lucas Theorem
    for(int i = 1; i <= P-1; i++)
        f[i] = f[i-1] * i % P;

    int res = 1;
    while(N && R) {
        int n = N % P;
        int r = R % P;
        if(n < r) {
            res = 0;
            break;
        }
        res = (res * f[n]) % P;
        for(int i = 0; i < P - 2; i++)
            res = ((res * f[r]) % P * f[n-r]) % P;
        N /= P, R /= P;
    }
    cout << res;
    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool sieve_isPrime[1000];

int main() {
    int N, count = 0;
    cin >> N;

    for (int i = 0; i < 1000; i++) {
        sieve_isPrime[i] = false;
    }

    sieve_isPrime[1] = true;

    for (int i = 2; i < 1000; i++) {
        bool isPrime = true;
        for (int j = 1; j < 1000; j++) {
            if (sieve_isPrime[j] && (i + 1) % (j + 1) == 0) {
                sieve_isPrime[i] = false;
                isPrime = false;
                break;
            }
        }

        if (isPrime) sieve_isPrime[i] = true;
    }
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (n != 1 && sieve_isPrime[n - 1]) count++;
    } 

    cout << count;
    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool sieve_isPrime[10000];

int main() {
    int M, N, min = -1, sum = 0;
    cin >> M >> N;

    for (int i = 0; i < 10000; i++) {
        sieve_isPrime[i] = false;
    }

    sieve_isPrime[1] = true;

    for (int i = 2; i < 10000; i++) {
        bool isPrime = true;
        for (int j = 1; j < 10000; j++) {
            if (sieve_isPrime[j] && (i + 1) % (j + 1) == 0) {
                sieve_isPrime[i] = false;
                isPrime = false;
                break;
            }
        }

        if (isPrime) sieve_isPrime[i] = true;
    }

    for (int i = M - 1; i < N; i++) {
        if (sieve_isPrime[i]) {
            if (min == -1) min = i + 1;
            sum += i + 1;
        }
    } 
    min == -1 ? cout << "-1" : cout << sum << endl << min;
    return 0;
}

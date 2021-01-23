#include <iostream>
using namespace std;

bool isPrime(int num){
    for (int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int d; cin >> d;
        int divsor[4] = {1, 1 + d, 1 + 2 * d, 0};

        for (int j = 1; j < 3; j++) {
            while (true) {
                if (isPrime(divsor[j])) break;
                divsor[j]++; divsor[j + 1]++;
            }
        }

        divsor[3] = divsor[1] * divsor[2];
        cout << divsor[3] << endl;
    }
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char isPrime[123456 * 2 + 1];
    memset(isPrime, 1, sizeof(isPrime));

    isPrime[1] = 0; 

    for(int i = 2; i <= 123456 * 2; i++){
        if (isPrime[i]){
            for(int j = 2 * i; j <= 123457 * 2; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        int count = 0;
        for (int i = n+1; i <= 2 * n; i++) {
            if (isPrime[i] == 1) count++;
        }

        cout << count << "\n";
    }
	return 0;
}


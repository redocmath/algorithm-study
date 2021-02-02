#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m; cin >> m >> n;

	char isPrime[1000001];
	memset(isPrime, 1, sizeof(isPrime));

	isPrime[1] = 0; 

	for(int i = 2; i <= n; i++){
        if (isPrime[i]){
            for(int j = 2 * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
	}

	for (int i = m; i <= n; i++) {
	    if (isPrime[i] == 1) cout << i << "\n";
	}
	
	return 0;
}


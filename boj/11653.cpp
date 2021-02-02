#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n; cin >> n;
	int isPrime[10000001];
	memset(isPrime, 1, n+1);
	
	for(int i = 2;i<=n;i++){
			if (isPrime[i] || n % i == 0){
				for(int j = 2 * i; j < n; j += i) {
					isPrime[j] = 0;
				}
				
				while(n % i == 0) {
					cout << i << endl;
					n /= i;
				}
			}
	}
	
	return 0;
}


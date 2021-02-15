#include <iostream>
using namespace std;
int main(void) {
    while (1) {
        long long n;
	    cin >> n;
        if (n == 0) break;
	    long long pi = n;
	    long long prime = 2;
    
        // Euler-Phi
	    while (prime * prime <= n) {
		    if (n % prime == 0)
			    pi = pi / prime * (prime - 1);
		    while (n % prime == 0)
			    n = n / prime;
		    prime++;
	     }
	    if (n != 1) {
		    pi = pi / n * (n - 1);
	    }
	    cout << pi << "\n";
   }
}

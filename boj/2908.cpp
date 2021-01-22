#include <iostream>
#include <string>
using namespace std;

int SWAP(int n) {
    int hund = n / 100;
    int ten = (n % 100) / 10;
    int one = n % 10;
    
    return one * 100 + ten * 10 + hund;
}
int main() {
    int A, B;
    cin >> A >> B;
    
    A = SWAP(A);
    B = SWAP(B);
    
    if (A > B) cout << A;
    else cout << B;
    
    return 0;
}
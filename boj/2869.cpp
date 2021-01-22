#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    long long A, B, V, nowHeight = 0, date = 1;
    cin >> A >> B >> V;

    cout << (int)ceil((long double)(V - B) / (long double)(A - B));
    return 0;
}

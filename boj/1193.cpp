#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    long long X = 1, N = 2, numer = 1, demo = 2;
    cin >> X;
    bool isGoingUP = false;

    if (X == 1) {
        cout << "1/1";
        return 0;
    }

    while (true) {
        if (N >= X) break;
        if (isGoingUP) {
            numer--; demo++;
        } else {
            numer++; demo--;
        }

        N++;

        if (N >= X) break;

        if (numer == 1) {
            isGoingUP = false;
            demo++;
            N++;
        } else if (demo == 1) {
            isGoingUP = true;
            numer++;
            N++;
        }
        
        if (N >= X) break;
    }
    
    cout << numer << "/" << demo;

    return 0;
}

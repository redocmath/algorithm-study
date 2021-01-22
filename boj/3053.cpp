/*
 * Merry Christmas!
 * 메리 크리스마스!
 *
 * */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() { 
    int r;
    cin >> r;
    
    double uclid = r * r * M_PI;
    double manht = r * r * 2;
    cout << fixed;
    cout.precision(6);
    cout << uclid << endl << manht;
    return 0;
}

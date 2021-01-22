#include <iostream>
#include <string>
using namespace std;

int main() {
    string callns;
    int time_ = 0;
    cin >> callns;
    
    for (int i = 0; i < callns.size(); i++) {
        if (int(callns[i]) >= int('A') && int(callns[i]) <= int('C')) time_ += 3;
        if (int(callns[i]) >= int('D') && int(callns[i]) <= int('F')) time_ += 4;
        if (int(callns[i]) >= int('G') && int(callns[i]) <= int('I')) time_ += 5;
        if (int(callns[i]) >= int('J') && int(callns[i]) <= int('L')) time_ += 6;
        if (int(callns[i]) >= int('M') && int(callns[i]) <= int('O')) time_ += 7;
        if (int(callns[i]) >= int('P') && int(callns[i]) <= int('S')) time_ += 8;
        if (int(callns[i]) >= int('T') && int(callns[i]) <= int('V')) time_ += 9;
        if (int(callns[i]) >= int('W') && int(callns[i]) <= int('Z')) time_ += 10;
    }
    
    cout << time_;
    
    return 0;
}
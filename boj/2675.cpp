#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, R;
    string S;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<char> Sarr;
        cin >> R >> S;
        for (int j = 0; j < S.size(); j++) {
            for (int k = 0; k < R; k++)
                Sarr.push_back(S[j]);
        }
        for (int j = 0; j < Sarr.size(); j++) {
            cout << Sarr[j];
        }
        
        cout << endl;
    }
    
    return 0;
}
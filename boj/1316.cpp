#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int T, count = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int alphabet[26] = {0, };
        string code = "";
        int nowCharAscii = 0;
        bool isValid = true;
        cin >> code;

        for (int j = 0; j < code.size(); j++) {
            if (alphabet[int(code[j]) - 97] == 1 && 
                    nowCharAscii != int(code[j]) - 97) {
                isValid = false;
                break;
            } else {
                nowCharAscii = int(code[j]) - 97;
                alphabet[int(code[j]) - 97] = 1;
            }
        }

        if (isValid) count++;
    }

    cout << count;
}

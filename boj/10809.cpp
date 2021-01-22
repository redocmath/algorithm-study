#include <iostream>
#include <string>
using namespace std;
int arr[26];

int main() {
    for (int i = 0; i < 26; i++) {
        arr[i] = -1;
    }
    string str = "";
    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        int idx = int(str[i]) - 97;
        if (arr[idx] == -1) arr[idx] = i;
    }
    
    for (int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }
}
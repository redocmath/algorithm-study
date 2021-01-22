#include <iostream>
#include <string>
using namespace std;
int arr[26];

int main() {
    for (int i = 0; i < 26; i++) {
        arr[i] = 0;
    }
    string str = "";
    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        int idx = int(str[i]) < 97 ? int(str[i]) - 65 : int(str[i]) - 97;
        arr[idx] += 1;
    }
    
    int maxidx = -1;
    for (int i = 0; i < 26; i++) {
        if (arr[maxidx] < arr[i]) maxidx = i;
    }
    
    int temp = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[maxidx] == arr[i]) temp++;
        if (temp == 2) {
            cout << "?";
            return 0;
        }
    }
    
    cout << char(65 + maxidx);
    return 0;
}
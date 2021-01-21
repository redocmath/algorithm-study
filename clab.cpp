#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    int i = 1, count = 0;

    while (count != n) {
        if (to_string(i).find("666") != string::npos) {
            count++;
        }
        i++;
    }

    cout << i - 1;
    return 0;
}

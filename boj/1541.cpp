#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string a; cin >> a;
    int ret = 0, inbrace; string mem;
    for (int i = 0; i < a.length(); i++) {
        if (isdigit(a[i])) mem += a[i];
        else if (a[i] == "+") inbrace 
    }
}
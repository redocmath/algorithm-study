#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

string add(string s1, string s2) {
	string result(max(s1.size(), s2.size()), '0');
	bool carry = false;
	for (int i = 0; i < result.size(); i++) {
		int temp = carry;
		carry = false;

		if (i < s1.size())
			temp += s1[s1.size() - i - 1] - '0';
		if (i < s2.size())
			temp += s2[s2.size() - i - 1] - '0';
		if (temp >= 10)
		{
			carry = true;
			temp -= 10;
		}

		result[result.size() - i - 1] = temp + '0';
	}

	if (carry) result.insert(result.begin(), '1');
	return result;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;

    string dp[10001];
    dp[0] = "0";
    dp[1] = "1";
    for (int i = 2; i <= n; i++) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }

    cout << dp[n];
    return 0;
}

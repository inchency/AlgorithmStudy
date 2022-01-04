#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int>dp(n + 1, -1);
	dp[2] = 1; dp[4] = 2;
	for (int i = 5; i <= n; i++) {
		if (i % 5 == 0) dp[i] = i / 5;
		else dp[i] = dp[i - 2] + 1;
	}
	cout << dp[n];
	return 0;
}
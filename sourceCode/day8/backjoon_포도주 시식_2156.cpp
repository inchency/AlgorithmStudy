#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void solve(vector<int>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> v[i];
	solve(v);

	return 0;
}

void solve(vector<int>& v) {
	vector<int>dp(n + 1);
	dp[1] = v[1]; dp[2] = v[1] + v[2];
	int answer = 0;
	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(max(v[i] + v[i - 1] + dp[i - 3], v[i] + dp[i - 2]), dp[i - 1]), dp[i - 2]);
		answer = max(dp[i], answer);
	}
	cout << answer;
}
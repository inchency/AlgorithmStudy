#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

void solve(vector<pair<int, int>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<pair<int, int>>v(N+1);
	for (int i = 1; i <= N; i++) 
		cin >> v[i].first >> v[i].second;
	solve(v);
	return 0;
}

void solve(vector<pair<int, int>>& v) {
	vector<int>dp(N + 51, 0);
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		int next = i + v[i].first;
		dp[next] = max(dp[next], dp[i] + v[i].second);
	}
	for (int i = N + 1; i < N + 51; i++) dp[i] = max(dp[i], dp[i - 1]);
	cout << dp[N + 1];
}
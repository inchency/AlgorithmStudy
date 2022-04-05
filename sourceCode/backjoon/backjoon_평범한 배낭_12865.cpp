// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, W, V;

void solve(vector<pair<int, int>>& p_v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	vector<pair<int, int>>p_v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> W >> V;
		p_v[i] = make_pair(W, V);
	}
	solve(p_v);
	return 0;
}

void solve(vector<pair<int, int>>& p_v) {
	vector<vector<int>>dp(N + 1, vector<int>(K + 1));
	for (int i = 1; i <= N; i++) {
		int cur_num = p_v[i].first;
		int cur_weight = p_v[i].second;
		for (int j = 1; j <= K; j++) {
			if (cur_num > j) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cur_num] + cur_weight);
			}
		}
	}
	/*for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[N][K];
}

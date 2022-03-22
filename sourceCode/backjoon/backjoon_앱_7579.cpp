#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int s = 0;

void solve(vector<int>& v1, vector<int>& v2);


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<int>v1(N + 1, 0);
	vector<int>v2(N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> v1[i];
	for (int i = 1; i <= N; i++) {
		cin >> v2[i];
		s += v2[i];
	}
	solve(v1, v2);
	return 0;
}

void solve(vector<int>& v1, vector<int>& v2) {
	// √ ±‚»≠
	vector<vector<int>>dp(N + 1, vector<int>(s+1));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= s; j++) {
			if(j - v2[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v2[i]] + v1[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	int answer = -1;
	for (int i = 0; i <= s; i++) {
		if (dp[N][i] >= M) {
			answer = i;
			break;
		}
	}
	cout << answer;
}
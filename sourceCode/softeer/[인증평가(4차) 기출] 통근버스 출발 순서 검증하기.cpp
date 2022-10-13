// https://softeer.ai/practice/info.do?idx=1&eid=654&sw_prbl_sbms_sn=86029

#include <iostream>
#include <vector>

using namespace std;

int N;

void solve(vector<int>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	solve(v);
	return 0;
}

void solve(vector<int>& v) {
	long long answer = 0;
	// ai < aj, ai > ak를 만족해야 한다.
	// ai < aj 인 경우
	for (int i = 0; i < N; i++) {
		int ai = v[i];
		vector<int>dp(N, 0);
		for (int j = i + 1; j < N; j++) {
			int aj = v[j];
			if (ai < aj)
				dp[j] = dp[j - 1] + 1;
			else
				dp[j] = dp[j - 1];
		}
		for (int k = i + 2; k < N; k++) {
			int ak = v[k];
			if (ai > ak)
				answer += dp[k - 1];
		}
	}
	cout << answer;
}

// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string a, b;

void solve(string a, string b);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	solve(a, b);
	return 0;
}
void solve(string a, string b) {
	int a_size = a.size();
	int b_size = b.size();
	vector<vector<int>>dp(a_size, vector<int>(b_size, 0));
	bool flag = false;
	for (int i = 0; i < a_size; i++) {
		if (a[i] == b[0]) {
			dp[i][0] = 1;
			flag = true;
		}
		if (flag)
			dp[i][0] = 1;
	}
	// 첫번째 가로줄 세로줄 채우기
	flag = false;
	for (int j = 0; j < b_size; j++) {
		if (b[j] == a[0]) {
			dp[0][j] = 1;
			flag = true;
		}
		if (flag)
			dp[0][j] = 1;
	}

	for (int i = 1; i < a_size; i++) {
		for (int j = 1; j < b_size; j++) {
			if (a[i] != b[j])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			else
				dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	int answer = dp[a_size - 1][b_size - 1];
	cout << answer;
//	cout << endl;
//	for (int i = 0; i < a_size; i++) {
//		for (int j = 0; j < b_size; j++) {
//			cout << dp[i][j] << " ";
//	}
//	cout << endl;
//}
//	cout << endl;
//	// 최장 공통 부분 수열 찾기
//	int cur_i = a_size - 1;
//	int cur_j = b_size - 1;
//	string lcs = "";
//	while (cur_i - 1 >= 0 && cur_j - 1 >= 0) {
//		if (dp[cur_i][cur_j] == dp[cur_i - 1][cur_j]) 
//			cur_i--;
//		else if (dp[cur_i][cur_j] == dp[cur_i][cur_j - 1]) 
//			cur_j--;
//		// 대각
//		else {
//			lcs.push_back(a[cur_i]);
//			cur_i--;
//			cur_j--;
//		}
//	}
//	reverse(lcs.begin(), lcs.end());
//	cout << lcs;
}

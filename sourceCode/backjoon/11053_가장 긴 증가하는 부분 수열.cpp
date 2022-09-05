// https://www.acmicpc.net/problem/11053
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

void solve(vector<int>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> v[i];
	solve(v);
	return 0;
}

void solve(vector<int>& v) {
	vector<int>dp(N + 1);
	vector<int>new_v(1, 0);

	for (int i = 1; i <= N; i++) {
		if (v[i] > *(new_v.end() - 1)) {
			dp[i] = new_v.size();
			new_v.push_back(v[i]);
		}
		else {
			auto it = lower_bound(new_v.begin(), new_v.end(), v[i]);
			int ind = it - new_v.begin();
			dp[i] = ind;
			new_v[ind] = v[i];
		}
	}
	//for (auto e : dp) cout << e << " ";
	cout << *max_element(dp.begin(), dp.end());
}

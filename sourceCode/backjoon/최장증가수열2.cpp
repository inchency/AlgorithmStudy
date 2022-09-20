#include <vector>
#include <iostream>
// https://www.acmicpc.net/problem/12015

#include <algorithm>

using namespace std;

int N;

void solve(vector<int>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N + 1, 0);
	for (int i = 1; i <= N; i++) 
		cin >> v[i];
	
	solve(v);
	return 0;
}


void solve(vector<int>& v) {
	vector<int>dp(N + 1);
	vector<int>a_v(1, 0);
	for (int i = 1; i <= N; i++) {
		int cur = v[i];
		int ind = lower_bound(a_v.begin(), a_v.end(), cur) - a_v.begin();
		if (ind == a_v.size())
			a_v.push_back(cur);
		else
			a_v[ind] = cur;
		dp[i] = ind;
	}
	int answer = *max_element(dp.begin(), dp.end());
	cout << answer;
}

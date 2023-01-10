// https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

void solve(vector<pair<int, int>>v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<pair<int, int>>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	solve(v);
	return 0;
}

void solve(vector<pair<int, int>>v) {
	sort(v.begin(), v.end(), comp);
	vector<int>dp(N);
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		int cur_second = v[i].second;
		bool flag = false;
		int max_num = 0;
		for (int j = 0; j < i; j++) {
			int before_second = v[j].second;
			int cur_dp = dp[j];
			if (cur_second > before_second) {
				max_num = max(max_num, cur_dp + 1);
				flag = true;
			}
		}
		if (!flag) 
			max_num = 1;
		dp[i] = max_num;
	}
	int max_answer = 0;
	for (int e : dp) 
		max_answer = max_answer < e ? e : max_answer;
	cout << N - max_answer;
}

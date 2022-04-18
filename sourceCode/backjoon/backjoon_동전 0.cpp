// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

void solve(vector<int>& coins_v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	vector<int>coins_v(N);
	for (int i = 0; i < N; i++) 
		cin >> coins_v[i];
	reverse(coins_v.begin(), coins_v.end());
	solve(coins_v);
	return 0;
}

void solve(vector<int>& coins_v) {
	int answer = 0;
	int cur_num = K;
	for (int i = 0; i < N; i++) {
		if (coins_v[i] <= cur_num) {
			int cur_coin = coins_v[i];
			answer += cur_num / cur_coin;
			cur_num = cur_num - ((cur_num / cur_coin) * cur_coin);
		}
	}
	cout << answer;
}

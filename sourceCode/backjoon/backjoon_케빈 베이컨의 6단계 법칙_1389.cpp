#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;

void solve(vector<vector<int>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	solve(v);
	return 0;
}

void solve(vector<vector<int>>& v) {
	vector<vector<int>>connect_num(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		queue<pair<int ,int>>q; // cur_node, cur_cnt
		q.push(make_pair(i, 0));
		while (!q.empty()) {
			int cur_node = q.front().first;
			int cur_cnt = q.front().second;
			q.pop();
			cur_cnt++;
			for (auto next_node : v[cur_node]) {
				if (connect_num[i][next_node] == 0) {
					connect_num[i][next_node] = cur_cnt;
					q.push(make_pair(next_node, cur_cnt));
				}
			}
		}
		
	}
	for (int i = 1; i <= N; i++) 
		connect_num[i][i] = 0;

	int answer, temp_sum = INT_MAX;
	for (int i = 1; i <= N; i++) {
		int s = 0;
		for (int j = 1; j <= N; j++) {
			s += connect_num[i][j];
		}
		if (temp_sum > s) {
			temp_sum = s;
			answer = i;
		}
	}
	cout << answer;
}
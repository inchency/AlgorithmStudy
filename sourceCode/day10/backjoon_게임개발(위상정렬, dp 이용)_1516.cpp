#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

// 위상정렬, DP 개념 이용
void t_sort(vector<vector<int>>& v, vector<int>& in_degree, vector<int>& time_v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<vector<int>>v(N + 1);
	vector<int>in_degree(N + 1, 0);
	vector<int>time_v(N + 1);
	for (int i = 1; i <= N; i++) {
		int time;
		cin >> time;
		int next;
		cin >> next;
		time_v[i] = time;
		while (1) {
			if (next == -1) break;
			v[next].push_back(i);
			in_degree[i]++;
			cin >> next;
		}
	}
	t_sort(v, in_degree, time_v);
	return 0;
}

void t_sort(vector<vector<int>>& v, vector<int>& in_degree, vector<int>& time_v) {
	queue<int>q;
	vector<int>answer_n_v;
	vector<int>answer_time_v;
	for (auto e : time_v) answer_time_v.push_back(e);
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			answer_n_v.push_back(i);
			answer_time_v.push_back(time_v[i]);
		}
	}
	while (!q.empty()) {
		int cur_n = q.front();
		q.pop();
		// cur_n에 이어져 있는 간선 지우기
		for (int next_n : v[cur_n]) {
			answer_time_v[next_n] = max(answer_time_v[next_n], answer_time_v[cur_n] + time_v[next_n]);
			in_degree[next_n]--;
			if (in_degree[next_n] == 0) {
				q.push(next_n);
				answer_n_v.push_back(next_n);
			}
		}
	}
	/*if (answer_n_v.size() < N) cout << "Error!\n";
	else {
		for (auto e : answer_n_v) cout << e << " ";
	}*/
	for (int i = 1; i <= N; i++) cout << answer_time_v[i] << "\n";
}

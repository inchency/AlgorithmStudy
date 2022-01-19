#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

// 위상정렬
void t_sort(vector<vector<int>>& v, vector<int>& in_degree);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>>v(N + 1);
	vector<int>in_degree(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		in_degree[B]++;
	}
	t_sort(v, in_degree);
	return 0;
}

void t_sort(vector<vector<int>>& v, vector<int>& in_degree) {
	queue<int>q;
	vector<int>answer;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			answer.push_back(i);
		}
	}
	while (!q.empty()) {
		int cur_n = q.front();
		q.pop();
		// cur_n에 이어져 있는 간선 모두 지우기
		for (int target_n : v[cur_n]) {
			in_degree[target_n]--;
			if (in_degree[target_n] == 0) {
				q.push(target_n);
				answer.push_back(target_n);
			}
		}
	}
	if (answer.size() < N) cout << "Error!!\n";
	else {
		for (auto e : answer)
			cout << e << " ";
	}
}

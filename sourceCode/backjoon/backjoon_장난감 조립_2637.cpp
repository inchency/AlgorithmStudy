#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
set<int>s; // s에 들어가면 중간부품

// 위상정렬
void solve(vector<vector<pair<int, int>>>& v, vector<int>& in_degree);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	vector<int>in_degree(N + 1);
	for (int i = 0; i < M; i++) {
		int X, Y, K;
		cin >> X >> Y >> K;
		v[X].push_back(make_pair(Y, K)); // X 만드는데 Y가 K개 필요
		in_degree[Y]++;
		s.insert(X);
	}
	solve(v, in_degree);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v, vector<int>& in_degree) {
	queue<int>q;
	vector<int>answer;
	vector<int>answer_cnt(N + 1);
	q.push(N);
	answer_cnt[N] = 1;
	answer.push_back(N);
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cnt = e.second;
			answer_cnt[next_node] += answer_cnt[cur_node] * next_cnt;
			in_degree[next_node]--;
			if (in_degree[next_node] == 0) {
				q.push(next_node);
				answer.push_back(next_node);
			}
		}
	}
	/*for (auto e : answer) cout << e << " ";
	cout << endl;
	for (auto e : answer_cnt) cout << e << " ";*/
	for (size_t i = 1; i < answer_cnt.size(); i++) {
		if (s.find(i) == s.end()) {
			cout << i << " " << answer_cnt[i] << "\n";
		}
	}
}


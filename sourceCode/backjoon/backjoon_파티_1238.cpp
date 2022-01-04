#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M, X;

void solve(vector<vector<pair<int, int>>>& v);

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> X;
	vector<vector<pair<int, int>>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	vector<int>answer(N + 1, 0);
	// X에서 다시 원래 동래로 오는 다익스트라
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq2;
	vector<int>dist2(N + 1, INT_MAX);
	dist2[X] = 0;
	pq2.push(make_pair(X, 0));
	while (!pq2.empty()) {
		int cur_node = pq2.top().first;
		int cur_cost = pq2.top().second;
		pq2.pop();
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cost = cur_cost + e.second;
			if (dist2[next_node] > next_cost) {
				dist2[next_node] = next_cost;
				pq2.push(make_pair(next_node, next_cost));
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		// X까지 가는 최소경로 다익스트라
		priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
		vector<int>dist(N + 1, INT_MAX);
		dist[i] = 0;
		pq.push(make_pair(i, 0));
		while (!pq.empty()) {
			int cur_node = pq.top().first;
			int cur_cost = pq.top().second;
			pq.pop();
			for (auto e : v[cur_node]) {
				int next_node = e.first;
				int next_cost = cur_cost + e.second;
				if (dist[next_node] > next_cost) {
					dist[next_node] = next_cost;
					pq.push(make_pair(next_node, next_cost));
				}
			}
		}
		answer[i] = dist[X] + dist2[i];
	}
	int real_answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer[i] > real_answer) real_answer = answer[i];
	}
	cout << real_answer;
}

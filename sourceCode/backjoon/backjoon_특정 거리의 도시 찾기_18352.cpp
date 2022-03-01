#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M, K, X;

void solve(vector<vector<int>>& v);
struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K >> X;
	vector<vector<int>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int start, dest;
		cin >> start >> dest;
		v[start].push_back(dest);
	}
	solve(v);
	return 0;
}

void solve(vector<vector<int>>& v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
	vector<int>dist(N + 1, INT_MAX);
	dist[X] = 0;
	pq.push({X, 0});
	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		for (int next_node : v[cur_node]) {
			int next_cost = cur_cost + 1;
			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				pq.push({ next_node, next_cost });
			}
		}
	}
	vector<int>answer;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			answer.push_back(i);
		}
	}
	if (answer.size() == 0) cout << -1;
	else {
		for (auto e : answer) cout << e << "\n";
	}
}
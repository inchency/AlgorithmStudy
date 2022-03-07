#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

void solve(vector<vector<pair<int, int>>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back(make_pair(b, cost));
		v[b].push_back({ a, cost });
	}
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
	pq.push({ 1, 0 });
	vector<int>dist(N + 1, INT_MAX);
	dist[1] = 0;
	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		if (cur_cost > dist[cur_node]) continue;
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cost = e.second;
			int candidate_cost = cur_cost + next_cost;
			if (dist[next_node] > candidate_cost) {
				dist[next_node] = candidate_cost;
				pq.push({ next_node, candidate_cost });
			}
		}
	}
	cout << dist[N];
}
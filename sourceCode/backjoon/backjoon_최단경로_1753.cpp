#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V, E, K;

void solve(vector<vector<pair<int, int>>>& v);
struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> V >> E;
	cin >> K;
	vector<vector<pair<int, int>>>v(V + 1);
	for (int i = 0; i < E; i++) {
		int start, dest, cost;
		cin >> start >> dest >> cost;
		v[start].push_back(make_pair(dest, cost));
	}
	solve(v);
	return 0;
}

// 다익스트라 풀이
void solve(vector<vector<pair<int, int>>>& v) {
	vector<int>dist(V + 1, INT_MAX);
	dist[K] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; // 노드, 비용
	pq.push(make_pair(K, 0));
	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cost = e.second;
			if (cur_cost + next_cost < dist[next_node]) {
				dist[next_node] = cur_cost + next_cost;
				pq.push(make_pair(next_node, cur_cost + next_cost));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX) cout << "INF\n";
		else {
			cout << dist[i] << "\n";
		}
	}
}

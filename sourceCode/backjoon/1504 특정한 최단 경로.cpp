// https://www.acmicpc.net/problem/1504

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int N, E;
int V1, V2;

struct Info {
	int node, cost;
};

struct comp {
	bool operator()(const Info& a, const Info& b) {
		return a.cost > b.cost;
	}
};

void solve(vector<vector<pair<int, int>>>& v);
vector<int> dij(vector<vector<pair<int, int>>>& v, int start_node);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> E;
	vector<vector<pair<int, int>>>v(N + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cin >> V1 >> V2;
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	// 1 -> 다익스트라로 구하기
	vector<int>start_to_v = dij(v, 1);
	// V1 ->  다익스트라로 구하기
	vector<int>v1_to_v = dij(v, V1);
	// V2 -> 다익스트라로 구하기
	vector<int>v2_to_v = dij(v, V2);

	if ((start_to_v[V1] == INT_MAX || v1_to_v[V2] == INT_MAX || v2_to_v[N] == INT_MAX) && (start_to_v[V2] == INT_MAX || v1_to_v[V1] == INT_MAX || v1_to_v[N] == INT_MAX))
		cout << -1;
	// start -> V1 -> V2 -> N의 경우
	// start -> V2 -> V1 -> N의 경우
	else 
		cout << min(start_to_v[V1] + v1_to_v[V2] + v2_to_v[N], start_to_v[V2] + v2_to_v[V1] + v1_to_v[N]);

}

vector<int> dij(vector<vector<pair<int, int>>>& v, int start_node) {
	vector<int>dist(N + 1, INT_MAX);
	dist[start_node] = 0;
	priority_queue<Info, vector<Info>, comp>pq;
	Info info;
	info.node = start_node; info.cost = 0;
	pq.push(info);
	while (!pq.empty()) {
		int cur_node = pq.top().node;
		int cur_cost = pq.top().cost;
		pq.pop();
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cost = e.second + cur_cost;
			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				Info info;
				info.node = next_node; info.cost = next_cost;
				pq.push(info);
			}
		}
	}
	return dist;
}

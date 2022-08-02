// https://www.acmicpc.net/problem/2307

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
vector<int>parent; // N까지 가는 경로 저장

void solve(vector<vector<pair<int, int>>>& v);
vector<int> dij(vector<vector<pair<int, int>>>& v);
vector<int> dij2(vector<vector<pair<int, int>>>& v, int node1, int node2);

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	parent.resize(N + 1, -1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	parent[1] = 1;
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	vector<int>origin_dist = dij(v);
	int origin_cost = origin_dist[N];
	int answer = 0;
	// 도로 하나씩 막기
	for (int i = N; i != 1; i = parent[i]) {
		int block_node_start = parent[i];
		int block_node_dest = i;
		vector<int>delete_v = dij2(v, block_node_start, block_node_dest);
		int delete_cost = delete_v[N];
		if (delete_cost == INT_MAX) {
			cout << -1;
			return;
		}
		if (delete_cost - origin_cost > answer) {
			answer = delete_cost - origin_cost;
		}
	}
	cout << answer;
}

vector<int> dij(vector<vector<pair<int, int>>>& v) {
	vector<int>dist(N + 1, INT_MAX);
	dist[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
	pq.push({ 1, 0 });
	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cost = e.second + cur_cost;
			if (next_cost < dist[next_node]) {
				parent[next_node] = cur_node;
				dist[next_node] = next_cost;
				pq.push({ next_node, next_cost });
			}
		}
	}
	return dist;
}

vector<int> dij2(vector<vector<pair<int, int>>>& v, int node1, int node2) {
	vector<int>dist(N + 1, INT_MAX);
	dist[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>q;
	q.push({ 1, 0 });
	while (!q.empty()) {
		int cur_node = q.top().first;
		int cur_cost = q.top().second;
		q.pop();
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cost = e.second + cur_cost;
			if ((cur_node == node1 && next_node == node2) || (cur_node == node2 && next_node == node1))
				continue;
			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				q.push({ next_node, next_cost });
			}
		}
	}
	return dist;
}

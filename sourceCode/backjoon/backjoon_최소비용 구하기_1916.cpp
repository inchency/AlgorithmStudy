#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
int target_start, target_dest;

void solve(vector<vector<pair<int, int>>>& v);
struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int start, dest, cost;
		cin >> start >> dest >> cost;
		v[start].push_back(make_pair(dest, cost));
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), compare);
	}
	cin >> target_start >> target_dest;
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
	pq.push(make_pair(target_start, 0));
	vector<int>dist(N + 1, INT_MAX);
	dist[target_start] = 0;
	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		//if (cur_cost > dist[cur_node]) continue; // 이거 주석 풀면 위에 sort 안해도 됨
		for (auto e : v[cur_node]) {
			int next_dest = e.first;
			int next_cost = e.second;
			int candidate_cost = cur_cost + next_cost;
			if (candidate_cost < dist[next_dest]) {
				dist[next_dest] = candidate_cost;
				pq.push(make_pair(next_dest, candidate_cost));
			}
		}
	}
	cout << dist[target_dest];
}
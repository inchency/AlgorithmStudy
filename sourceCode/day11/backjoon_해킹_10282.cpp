#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int T, n, d, c;

// 다익스트라 풀이
void solve(vector<vector<pair<int, int>>>& v);

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> d >> c;
		vector<vector<pair<int, int>>>v(n + 1);
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back(make_pair(a, s));
		}
		solve(v);
	}

	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	vector<int>dist(n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq; // 컴퓨터 번호, total cost
	pq.push(make_pair(c, 0));
	dist[c] = 0;
	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		for (auto e : v[cur_node]) {
			int next_node = e.first;
			int next_cost = e.second;
			if (dist[next_node] > cur_cost + next_cost) {
				dist[next_node] = cur_cost + next_cost;
				pq.push(make_pair(next_node, cur_cost + next_cost));
			}
		}
	}
	int cnt = 0;
	int max_answer = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INT_MAX) {
			cnt++;
			max_answer = max(max_answer, dist[i]);
		}
	}
	cout << cnt << " " << max_answer << "\n";
}
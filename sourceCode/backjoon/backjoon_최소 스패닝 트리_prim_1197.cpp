#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E;

struct Info {
	int start, dest;
	int weight;
};

struct comp {
	bool operator()(const Info& a, const Info& b) {
		return a.weight > b.weight;
	}
};

void solve(vector<vector<pair<int, int>>>&v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> V >> E;
	vector<vector<pair<int, int>>>v(V+1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	solve(v);
;	return 0;
}

// Prim 풀이
void solve(vector<vector<pair<int, int>>>& v) {
	vector<bool>visited(V + 1, false);
	priority_queue<Info, vector<Info>, comp>pq;
	// 1번 노드부터 시작
	visited[1] = true;
	int answer = 0;
	for (auto e : v[1]) {
		Info info;
		info.start = 1;
		info.dest = e.first;
		info.weight = e.second;
		pq.push(info);
	}
	while (!pq.empty()) {
		Info info = pq.top();
		pq.pop();
		if (!visited[info.dest]) {
			answer += info.weight;
			visited[info.dest] = true;
			for (auto e : v[info.dest]) {
				Info info2;
				info2.start = info.dest;
				info2.dest = e.first;
				info2.weight = e.second;
				if (!visited[info2.dest])
					pq.push(info2);
			}
		}
	}
	cout << answer;
}
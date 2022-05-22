// https://www.acmicpc.net/problem/1766

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

struct comp {
	bool operator()(const int& left, const int& right) {
		return left > right;
	}
};

void solve(vector<vector<int>>& adj, vector<int> &indegree_v);

int main() {
	cin >> N >> M;
	vector<vector<int>>adj(N + 1, vector<int>());
	vector<int>indegree_v(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		indegree_v[end] += 1;
	}
	solve(adj, indegree_v);
	return 0;
}

void solve(vector<vector<int>>& adj, vector<int>& indegree_v) {
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 1; i <= N; i++) {
		if (indegree_v[i] == 0) {
			pq.push(i);
		}
	}
	vector<int>answer;
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		answer.push_back(cur);
		for (auto e : adj[cur]) {
			indegree_v[e] -= 1;
			if (indegree_v[e] == 0) {
				pq.push(e);
			}
		}
	}
	for (auto e : answer)
		cout << e << " ";
}

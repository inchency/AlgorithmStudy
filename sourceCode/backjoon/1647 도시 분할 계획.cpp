// https://www.acmicpc.net/problem/1647

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N, M;

struct Info {
	int start, dest, cost;
};

struct comp {
	bool operator()(const Info& a, const Info& b) {
		return a.cost > b.cost;
	}
};

void solve(vector<vector<pair<int, int>>>& v);
int find_root(vector<int>&root_v, int node);
void do_union(vector<int>&root_v, vector<int>&rank_v, int start_node, int dest_node);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	priority_queue<Info, vector<Info>, comp>pq;
	// 간선 pq에 넣기
	for (int start_node = 1; start_node <= N; start_node++) {
		vector<pair<int, int>>s = v[start_node];
		for (pair<int, int>p : s) {
			Info info;
			info.start = start_node;
			info.dest = p.first;
			info.cost = p.second;
			pq.push(info);
		}
	}
	// 초기화
	vector<int>root_v(N + 1);
	for (int i = 1; i <= N; i++) root_v[i] = i;
	vector<int>rank_v(N + 1, 0);
	vector<int>answer_v;

	while (!pq.empty()) {
		Info info = pq.top();
		pq.pop();
		if (find_root(root_v, info.start) != find_root(root_v, info.dest)) {
			do_union(root_v, rank_v, info.start, info.dest);
			answer_v.push_back(info.cost);
		}
	}
	int s = 0;
	int max_num = 0;
	for (auto e : answer_v) {
		max_num = max(max_num, e);
		s += e;
	}
	cout << s - max_num;
}

int find_root(vector<int>&root_v, int node) {
	if (root_v[node] == node) return node;
	root_v[node] = find_root(root_v, root_v[node]);
	return root_v[node];
}

void do_union(vector<int>&root_v, vector<int>&rank_v, int start_node, int dest_node) {
	int start_node_root = root_v[start_node];
	int dest_node_root = root_v[dest_node];
	if (rank_v[start_node_root] > rank_v[dest_node_root])
		root_v[dest_node_root] = start_node_root;
	else if (rank_v[start_node_root] < rank_v[dest_node_root])
		root_v[start_node_root] = dest_node_root;
	else {
		rank_v[start_node_root]++;
		root_v[dest_node_root] = start_node_root;
	}
}

#include <iostream>
#include <vector>
#include <queue>

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

// 크루스칼 풀이
void solve(vector<vector<pair<int, int>>>& v, priority_queue<Info, vector<Info>, comp>& pq);
int find_root(vector<int>& root_v, int node);
void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	priority_queue<Info, vector<Info>, comp>pq;
	for (int i = 0; i < M; i++) {
		int start, dest, cost;
		cin >> start >> dest >> cost;
		v[start].push_back(make_pair(dest, cost));
		v[dest].push_back(make_pair(start, cost));
		Info info;
		info.start = start; info.dest = dest; info.cost = cost;
		pq.push(info);
	}
	solve(v, pq);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v, priority_queue<Info, vector<Info>, comp>& pq){
	// 초기화
	vector<int>rank_v(N + 1, 0);
	vector<int>root_v(N + 1);
	for (int i = 1; i < N; i++) root_v[i] = i;

	vector<int>answer_v;

	while (!pq.empty()) {
		Info info = pq.top();
		pq.pop();
		if (find_root(root_v, info.start) != find_root(root_v, info.dest)) {
			do_union(root_v, rank_v, info.start, info.dest);
			answer_v.push_back(info.cost);
		}
	}
	int answer = 0;
	for (size_t i = 0; i < answer_v.size() - 1; i++)
		answer += answer_v[i];
	cout << answer;
}

int find_root(vector<int>& root_v, int node) {
	if (root_v[node] == node) return node;
	root_v[node] = find_root(root_v, root_v[node]);
	return root_v[node];
}

void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node){
	int start_node_root = find_root(root_v, start_node);
	int dest_node_root = find_root(root_v, dest_node);
	if (rank_v[start_node_root] > rank_v[dest_node_root]) {
		root_v[dest_node_root] = start_node_root;
	}
	else if (rank_v[start_node_root] < rank_v[dest_node_root]) {
		root_v[start_node_root] = dest_node_root;
	}
	else {
		rank_v[start_node_root]++;
		root_v[dest_node_root] = start_node_root;
	}
}
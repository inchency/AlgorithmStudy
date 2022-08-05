// https://www.acmicpc.net/problem/6497

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Info {
	int node1, node2, cost;
};

struct comp {
	bool operator()(const Info& a, const Info& b) {
		return a.cost > b.cost;
	}
};

int N, M;

void solve(vector<vector<pair<int, int>>>& v, priority_queue<Info, vector<Info>, comp>& pq, int total_sum);
int find_root(vector<int>& root_v, int node);
void do_union(vector<int>& root_v, vector<int>& rank_v, int node1, int node2);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> N >> M;
		if (M == 0 && N == 0) return 0;
		vector<vector<pair<int, int>>>v(N);
		priority_queue<Info, vector<Info>, comp>pq;
		int total_sum = 0;
		for (int i = 0; i < M; i++) {
			int node1, node2, cost;
			cin >> node1 >> node2 >> cost;
			v[node1].push_back({ node2, cost });
			v[node2].push_back({ node1, cost });
			Info info;
			info.node1 = node1; info.node2 = node2; info.cost = cost;
			pq.push(info);
			total_sum += cost;
		}
		solve(v, pq, total_sum);
	}
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v, priority_queue<Info, vector<Info>, comp>& pq, int total_sum) {
	vector<int>root_v(N);
	for (int i = 0; i < N; i++) root_v[i] = i;
	vector<int>rank_v(N, 0);
	int road_cost = 0;
	while (!pq.empty()) {
		Info cur_info = pq.top();
		pq.pop();
		if (find_root(root_v, cur_info.node1) != find_root(root_v, cur_info.node2)) {
			do_union(root_v, rank_v, cur_info.node1, cur_info.node2);
			road_cost += cur_info.cost;
		}
	}
	cout << total_sum - road_cost << "\n";
}

int find_root(vector<int>& root_v, int node) {
	if (root_v[node] == node) return node;
	root_v[node] = find_root(root_v, root_v[node]);
	return root_v[node];
}

void do_union(vector<int>& root_v, vector<int>& rank_v, int node1, int node2) {
	int root_node1 = find_root(root_v, node1);
	int root_node2 = find_root(root_v, node2);
	if (rank_v[root_node1] > rank_v[root_node2])
		root_v[root_node2] = root_node1;
	else if (rank_v[root_node1] < rank_v[root_node2])
		root_v[root_node1] = root_node2;
	else {
		rank_v[root_node2]++;
		root_v[root_node1] = root_node2;
	}
}

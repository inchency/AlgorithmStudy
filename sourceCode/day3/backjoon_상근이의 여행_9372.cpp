#include <iostream>
#include <vector>

using namespace std;

int N, M;

void solve(vector<pair<int, int>>& v);

int find_root(vector<int>& root_v, int node);
void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node);

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<pair<int, int>>v(M+1);
		for (int i = 0; i < M; i++) 
			cin >> v[i].first >> v[i].second;
		solve(v);
	}
	return 0;
}

void solve(vector<pair<int, int>>& v) {
	// √ ±‚»≠
	vector<int>root_v(N+1);
	for (int i = 0; i < N; i++) root_v[i] = i;
	vector<int>rank_v(N+1, 0);
	int answer = 0;

	for (auto e : v) {
		if (find_root(root_v, e.first) != find_root(root_v, e.second)) {
			do_union(root_v, rank_v, e.first, e.second);
			answer++;
		}
	}
	cout << answer;
}

int find_root(vector<int>& root_v, int node) {
	if (root_v[node] == node) return node;
	else {
		root_v[node] = find_root(root_v, root_v[node]);
		return root_v[node];
	}
}

void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node) {
	int start_node_root = find_root(root_v, start_node);
	int dest_node_root = find_root(root_v, dest_node);
	if (rank_v[start_node_root] > rank_v[dest_node_root]) root_v[dest_node_root] = start_node_root;
	else if (rank_v[start_node_root] < rank_v[dest_node_root]) root_v[start_node_root] = dest_node_root;
	else {
		rank_v[start_node_root] += 1;
		root_v[dest_node_root] = start_node_root;
	}
}
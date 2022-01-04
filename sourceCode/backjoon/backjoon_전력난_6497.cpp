#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;

bool comp(const vector<int>& a, const vector<int>& b) {
	return a[2] < b[2];
}

void solve(vector<vector<int>>& v);
int find_root(vector<int>& root_v, int node);
void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		vector<vector<int>>v(n, vector<int>(3));
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v[i][0] = x; v[i][1] = y; v[i][2] = z;
		}
		solve(v);
	}

	return 0;
}

void solve(vector<vector<int>>& v) {
	sort(v.begin(), v.end(), comp);
	// √ ±‚»≠
	vector<int>root_v(m);
	for (int i = 0; i < m; i++) root_v[i] = i;
	vector<int>rank_v(m, 0);
	int answer = 0;
	for (auto e : v) {
		int start_node = e[0];
		int dest_node = e[1];
		int weight = e[2];
		if (find_root(root_v, start_node) != find_root(root_v, dest_node)) {
			do_union(root_v, rank_v, start_node, dest_node);
		}
		else answer += weight;
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

	if (rank_v[start_node_root] > rank_v[dest_node_root]) {
		root_v[dest_node_root] = start_node_root;
	}
	else if (rank_v[start_node_root] < rank_v[dest_node_root]) {
		root_v[start_node_root] = dest_node_root;
	}
	else {
		rank_v[start_node_root] += 1;
		root_v[dest_node_root] = start_node_root;
	}
}
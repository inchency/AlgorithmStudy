#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

struct Info {
	int start, dest, cost;
	char color;
};

bool comp(const Info& a, const Info& b) {
	return a.cost < b.cost;
}

void solve(vector<Info>& b0v, vector<Info>& r0v);
int find_root(vector<int>& root, int node);
void do_union(vector<int>& root, vector<int>& rank, int start_node, int dest_node);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) break;
		vector<Info>b0v; // blue cost가 0인 vector
		vector<Info>r0v; // red cost가 0인 vector
		for (int i = 0; i < m; i++) {
			int f, t;
			char c;
			cin >> c >> f >> t;
			Info info1;
			info1.start = f; info1.dest = t; info1.color = c;
			if (c == 'B') info1.cost = 0;
			else info1.cost = 1;
			b0v.push_back(info1);
			Info info2;
			info2.start = f; info2.dest = t; info2.color = c;
			if (c == 'R')info2.cost = 0;
			else info2.cost = 1;
			r0v.push_back(info2);
		}
		sort(b0v.begin(), b0v.end(), comp);
		sort(r0v.begin(), r0v.end(), comp);
		solve(b0v, r0v);
	}

	return 0;
}

void solve(vector<Info>& b0v, vector<Info>& r0v) {
	// 초기화
	vector<int>root(n + 1);
	for (int i = 1; i <= n; i++) root[i] = i;
	vector<int>rank(n + 1);

	// blue의 cost가 0일때
	int blue_cnt_max = 0;
	for (auto e : b0v) {
		if (find_root(root, e.start) != find_root(root, e.dest)) {
			do_union(root, rank, e.start, e.dest);
			if (e.color == 'B') blue_cnt_max++;
		}
	}
	// 초기화
	for (int i = 1; i <= n; i++) root[i] = i;
	for (int i = 1; i < n; i++) rank[i] = 0;

	// red의 cost가 0일때
	int blue_cnt_min = 0;
	for (auto e : r0v) {
		if (find_root(root, e.start) != find_root(root, e.dest)) {
			do_union(root, rank, e.start, e.dest);
			if (e.color == 'B') blue_cnt_min++;
		}
	}
	if (k >= blue_cnt_min && k <= blue_cnt_max) cout << 1 << "\n";
	else cout << 0 << "\n";
}

int find_root(vector<int>& root, int node) {
	if (root[node] == node) return node;
	root[node] = find_root(root, root[node]);
	return root[node];
}

void do_union(vector<int>& root, vector<int>& rank, int start_node, int dest_node) {
	int start_node_root = root[start_node];
	int dest_node_root = root[dest_node];
	if (rank[start_node_root] > rank[dest_node_root])
		root[dest_node_root] = start_node_root;
	else if (rank[start_node_root] < rank[dest_node_root])
		root[start_node_root] = dest_node_root;
	else {
		rank[start_node_root]++;
		root[dest_node_root] = start_node_root;
	}
}

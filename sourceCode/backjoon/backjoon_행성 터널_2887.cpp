#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct Info {
	int x, y, z;
};

struct Node {
	int start, dest, weight;
};

void solve(vector<Info>& v);
void kruskal(vector<Node>& v);
bool comp(const Node & a, const Node& b);
bool comp2(const pair<int, int>& a, const pair<int, int>& b);
int find_root(int node, vector<int>& root);
void do_union(int start_node, int dest_node, vector<int>& root, vector<int>& rank);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<Info>v(N);
	for (int i = 0; i < N; i++) {
		Info info;
		cin >> info.x >> info.y >> info.z;
		v[i] = info;
	}
	solve(v);
	return 0;
}

void solve(vector<Info>& v) {
	vector<pair<int, int>>v_x(N); // 행성번호, 좌표
	vector<pair<int, int>>v_y(N);
	vector<pair<int, int>>v_z(N);

	for (int i = 0; i < N; i++) {
		v_x[i] = make_pair(i, v[i].x);
		v_y[i] = make_pair(i, v[i].y);
		v_z[i] = make_pair(i, v[i].z);
	}
	sort(v_x.begin(), v_x.end(), comp2);
	sort(v_y.begin(), v_y.end(), comp2);
	sort(v_z.begin(), v_z.end(), comp2);

	vector<Node>v2;
	for (int i = 0; i < N - 1; i++) {
		Node node_x;
		node_x.start = v_x[i].first;
		node_x.dest = v_x[i + 1].first;
		node_x.weight = abs(v_x[i].second - v_x[i + 1].second);
		v2.push_back(node_x);

		Node node_y;
		node_y.start = v_y[i].first;
		node_y.dest = v_y[i + 1].first;
		node_y.weight = abs(v_y[i].second - v_y[i + 1].second);
		v2.push_back(node_y);

		Node node_z;
		node_z.start = v_z[i].first;
		node_z.dest = v_z[i + 1].first;
		node_z.weight = abs(v_z[i].second - v_z[i + 1].second);
		v2.push_back(node_z);
	}
	kruskal(v2);
}
void kruskal(vector<Node> &v) {
	sort(v.begin(), v.end(), comp);
	// 초기화
	vector<int>rank(N, 0);
	vector<int>root(N, 0);
	for (int i = 0; i < N; i++) root[i] = i;

	// Union Find
	int answer = 0;
	for (Node node : v) {
		if (find_root(node.start, root) != find_root(node.dest, root)) {
			do_union(node.start, node.dest, root, rank);
			answer += node.weight;
		}
	}
	cout << answer;
}

bool comp(const Node& a, const Node& b) {
	return a.weight < b.weight;
}
bool comp2(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int find_root(int node, vector<int>& root) {
	if (root[node] == node) return node;
	else {
		root[node] = find_root(root[node], root);
		return root[node];
	}
}

void do_union(int start_node, int dest_node, vector<int>& root, vector<int>& rank) {
	int start_node_root = find_root(start_node, root);
	int dest_node_root = find_root(dest_node, root);

	if (rank[start_node_root] < rank[dest_node_root]) {
		root[start_node_root] = dest_node_root;
	}
	else if (rank[start_node_root] > rank[dest_node_root]) {
		root[dest_node_root] = start_node_root;
;	}
	else {
		rank[start_node_root] += 1;
		root[dest_node_root] = start_node_root;
	}
}
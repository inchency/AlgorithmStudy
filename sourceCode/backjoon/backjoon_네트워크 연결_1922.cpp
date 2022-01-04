#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

struct Info {
	int v1, v2;
	int weight;
};

bool comp(const Info& a, const Info& b) {
	return a.weight < b.weight;
}

void solve(vector<Info>& v);
int find_root(vector<int>& root_v, int node);
void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node);

int main() {
	cin >> N >> M;
	vector<Info>v(M);
	for (int i = 0; i < M; i++) {
		Info info;
		cin >> info.v1 >> info.v2 >> info.weight;
		info.v1 -= 1; info.v2 -= 1;
		v[i] = info;
	}
	sort(v.begin(), v.end(), comp);
	solve(v);
	return 0;
}

void solve(vector<Info>& v) {
	// √ ±‚»≠
	vector<int>root_v(N);
	for (int i = 0; i < N; i++) root_v[i] = i;
	vector<int>rank_v(N, 0);
	int answer = 0;

	for (auto e : v) {
		if (find_root(root_v, e.v1) != find_root(root_v, e.v2)) {
			do_union(root_v, rank_v, e.v1, e.v2);
			answer += e.weight;
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
// https://www.acmicpc.net/problem/4386

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

int N;

struct Info {
	int start_node, dest_node;
	double dist;
};


struct comp {
	bool operator()(const Info& a, const Info& b) {
		return a.dist > b.dist;
	}
};

void solve(vector<pair<double, double>>& v, priority_queue<Info, vector<Info>, comp>& pq);
int find_root(vector<int>& root_v, int node);
void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<pair<double, double>>v(N);
	priority_queue<Info, vector<Info>, comp>pq;
	for (int i = 0; i < N; i++) 
		cin >> v[i].first >> v[i].second;
	for (int i = 0; i < N; i++) {
		double cur_x = v[i].first;
		double cur_y = v[i].second;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			double next_x = v[j].first;
			double next_y = v[j].second;
			double dist = sqrt(pow((cur_x - next_x), 2) + pow((cur_y - next_y), 2));
			pq.push(Info{ i, j, dist });
		}
	}
	solve(v, pq);
	return 0;
}

void solve(vector<pair<double, double>>& v, priority_queue<Info, vector<Info>, comp>& pq) {
	// 크루스칼 초기화
	vector<int>rank_v(N, 0);
	vector<int>root_v(N);
	for (int i = 0; i < N; i++) root_v[i] = i;
	double answer = 0;
	while (!pq.empty()) {
		Info info = pq.top();
		pq.pop();
		if (find_root(root_v, info.start_node) != find_root(root_v, info.dest_node)) {
			do_union(root_v, rank_v, info.start_node, info.dest_node);
			answer += info.dist;
		}
	}
	cout << answer;
}

int find_root(vector<int>& root_v, int node) {
	if (root_v[node] == node) return node;
	root_v[node] = find_root(root_v, root_v[node]);
	return root_v[node];
}

void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node) {
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

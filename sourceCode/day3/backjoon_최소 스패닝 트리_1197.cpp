//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int V, E;
//
//struct Info {
//	int v1, v2;
//	int weight;
//};
//
//struct comp {
//	bool operator()(const Info& a, const Info& b) {
//		return a.weight > b.weight;
//	}
//};
//
//void solve(priority_queue<Info, vector<Info>, comp>& pq);
//int find_root(vector<int>& root_v, int node);
//void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node);
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cin >> V >> E;
//	int A, B, C;
//	priority_queue<Info, vector<Info>, comp>pq;
//	for (int i = 0; i < E; i++) {
//		cin >> A >> B >> C;
//		Info info;
//		info.v1 = A-1; info.v2 = B-1; info.weight = C;
//		pq.push(info);
//	}
//	solve(pq);
//	return 0;
//}
//
//void solve(priority_queue<Info, vector<Info>, comp>& pq) {
//	// √ ±‚»≠
//	vector<int>root_v(V);
//	for (int i = 0; i < V; i++) root_v[i] = i;
//	vector<int>rank_v(V, 0);
//	int answer = 0;
//
//	while (!pq.empty()) {
//		Info info = pq.top();
//		pq.pop();
//		if (find_root(root_v, info.v1) != find_root(root_v, info.v2)) {
//			do_union(root_v, rank_v, info.v1, info.v2);
//			answer += info.weight;
//		}
//	}
//	cout << answer;
//}
//
//int find_root(vector<int>& root_v, int node) {
//	if (root_v[node] == node) return node;
//	else {
//		root_v[node] = find_root(root_v, root_v[node]);
//		return root_v[node];
//	}
//}
//
//void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node) {
//	int start_node_root = find_root(root_v, start_node);
//	int dest_node_root = find_root(root_v, dest_node);
//	if (rank_v[start_node_root] > rank_v[dest_node_root]) {
//		root_v[dest_node_root] = start_node_root;
//	}
//	else if (rank_v[start_node_root] < rank_v[dest_node_root]) {
//		root_v[start_node_root] = dest_node_root;
//	}
//	else {
//		rank_v[start_node_root] += 1;
//		root_v[dest_node_root] = start_node_root;
//	}
//}
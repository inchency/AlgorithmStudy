#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N, M, V;

bool comp(const int& a, const int& b) {
	return a < b;
}

void solve(vector<vector<int>>& v);
void dfs_stack(vector<vector<int>>& v);
void dfs_recursive(vector<vector<int>>& v, int cur_node, vector<bool>&visited);
void bfs(vector<vector<int>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> V;
	vector<vector<int>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		vector<int>sort_v = v[i];
		sort(sort_v.begin(), sort_v.end(), comp);
		v[i] = sort_v;
	}
	solve(v);
	return 0;
}

void solve(vector<vector<int>>& v) {
	dfs_stack(v);

	//vector<bool>visited(N + 1, false);
	//visited[V] = true;
	//dfs_recursive(v, V, visited);
	cout << "\n";
	
	bfs(v);
}

void dfs_stack(vector<vector<int>>& v) {
	stack<int>st;
	vector<bool>visited(N + 1, false);
	visited[V] = true;
	st.push(V);
	cout << V << " ";
	while (!st.empty()) {
		int cur_node = st.top();
		st.pop();
		for (auto next_node : v[cur_node]) {
			if (!visited[next_node]) {
				visited[next_node] = true;
				st.push(cur_node);
				st.push(next_node);
				cout << next_node << " ";
				break;
			}
		}
	}
}

void dfs_recursive(vector<vector<int>>& v, int cur_node, vector<bool>&visited) {
	cout << cur_node << " ";
	for (auto next_node : v[cur_node]) {
		if (!visited[next_node]) {
			visited[next_node] = true;
			dfs_recursive(v, next_node, visited);
		}
	}
}

void bfs(vector<vector<int>>& v) {
	queue<int>q;
	vector<bool>visited(N + 1, false);
	visited[V] = true;
	q.push(V);
	cout << V << " ";
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();
		for (auto next_node : v[cur_node]) {
			if (!visited[next_node]) {
				visited[next_node] = true;
				q.push(next_node);
				cout << next_node << " ";
			}
		}
	}
}
// https://youtu.be/tvyDu2JBTpE

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long N;

struct Info {
	long long next;
	long long cost;
};

void solve(vector<vector<Info>>& v);
long long dfs(vector<vector<Info>>& v, long long cur, vector<long long>& sub_tree_v, vector<bool>& visited);
long long bfs(vector<vector<Info>>& v, long long base_node);
void solve2(vector<vector<Info>>& v, vector<long long>& sub_tree_v, long long base_node, long long base_node_total);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<vector<Info>>v(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int start, next, cost;
		cin >> start >> next >> cost;
		Info info;
		info.next = next; info.cost = cost;
		v[start].push_back(info);
		info.next = start; info.cost = cost;
		v[next].push_back(info);
	}
	solve(v);
	return 0;
}

void solve(vector<vector<Info>>& v) {
	vector<long long>sub_tree_v(N + 1);
	vector<bool>visited(N + 1);
	long long base_node = 1;
	visited[base_node] = true;
	dfs(v, base_node, sub_tree_v, visited);
	// base_node 에 해당하는 답 구하기
	long long base_node_total = bfs(v, base_node);
	solve2(v, sub_tree_v, base_node, base_node_total);
}

long long dfs(vector<vector<Info>>& v, long long cur, vector<long long>& sub_tree_v, vector<bool>& visited) {
	if (v[cur].size() == 0) {
		sub_tree_v[cur] = 1;
		return 1;
	}
	for (Info e : v[cur]) {
		long long next = e.next;
		if (!visited[next]) {
			visited[next] = true;
			sub_tree_v[cur] += dfs(v, next, sub_tree_v, visited);
		}
	}
	sub_tree_v[cur] += 1;
	return sub_tree_v[cur];
}

long long bfs(vector<vector<Info>>& v, long long base_node) {
	vector<bool>visited(N + 1);
	vector<long long>dist(N + 1);
	queue<pair<long long, long long>>q; // cur_node, 누적 cost
	visited[base_node] = true;
	q.push({ base_node , 0});
	while (!q.empty()) {
		long long cur = q.front().first;
		long long total_cost = q.front().second;
		q.pop();
		dist[cur] = total_cost;
		for (Info e : v[cur]) {
			long long next = e.next;
			long long next_cost = e.cost + total_cost;
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, next_cost });
			}
		}
	}
	long long s = 0;
	for (long long e : dist) s += e;
	return s;
}

void solve2(vector<vector<Info>>& v, vector<long long>& sub_tree_v, long long base_node, long long base_node_total) {
	vector<long long>answer(N + 1);
	answer[base_node] = base_node_total;
	queue<long long>q;
	q.push(base_node);
	vector<bool>visited(N + 1);
	visited[base_node] = true;
	while (!q.empty()) {
		long long cur = q.front();
		q.pop();
		for (Info e : v[cur]) {
			long long next = e.next;
			if (!visited[next]) {
				visited[next] = true;
				long long cost = e.cost;
				long long add_cnt = N - sub_tree_v[next];
				long long subtract_cnt = sub_tree_v[next];
				long long cnt = add_cnt - subtract_cnt;
				answer[next] = answer[cur] + cost * cnt;
				q.push(next);
			}
		}
	}
	for (long long i = 1; i <= N; i++) cout << answer[i] << "\n";
}

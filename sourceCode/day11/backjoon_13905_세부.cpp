#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, s, e;
int max_weight = 0;

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

// 이분탐색 풀이
void solve(vector<vector<pair<int, int>>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	cin >> s >> e;
	for (int i = 0; i < M; i++) {
		int start, dest, weight;
		cin >> start >> dest >> weight;
		v[start].push_back(make_pair(dest, weight));
		v[dest].push_back(make_pair(start, weight));
		max_weight = max(max_weight, weight);
	}
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	int left = 1;
	int right = max_weight;
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		vector<bool>visited(N + 1, false);
		visited[s] = true;
		queue<int>q;
		q.push(s);
		// bfs
		bool flag = false;
		while (!q.empty()) {
			int cur_node = q.front();
			q.pop();
			// 해당 무게로 도착 가능
			if (cur_node == e) {
				// 무게를 더 늘려보자
				left = mid + 1;
				answer = max(answer, mid);
				flag = true;
				break;
			}
			for (auto pe : v[cur_node]) {
				int next_node = pe.first;
				int next_weight = pe.second;
				if (!visited[next_node] && mid <= next_weight) {
					visited[next_node] = true;
					q.push(next_node);
				}
			}
		}
		if (!flag) {
			// 해당 무게로 도착 불가능
			right = mid - 1;
		}
		
	}
	cout << answer;
}
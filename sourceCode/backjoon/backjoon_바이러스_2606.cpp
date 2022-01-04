#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int answer = 0;

void solve(vector<vector<int>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<vector<int>>v(N + 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int start, dest;
		cin >> start >> dest;
		v[start].push_back(dest);
		v[dest].push_back(start);
	}
	solve(v);
	return 0;
}

void solve(vector<vector<int>>& v) {
	queue<int>q;
	q.push(1);
	vector<bool>visited(N + 1, false);
	visited[1] = true;
	while (!q.empty()) {
		int cur_computer = q.front();
		q.pop();
		for (int next_computer : v[cur_computer]) {
			if (!visited[next_computer]) {
				answer++;
				visited[next_computer] = true;
				q.push(next_computer);
			}
		}
	}
	cout << answer;
}
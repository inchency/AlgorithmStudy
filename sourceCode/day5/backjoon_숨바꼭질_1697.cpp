#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

void solve();

int main() {
	cin >> N >> K;
	solve();
	return 0;
}

void solve() {
	queue<pair<int, int>>q; // 수빈이의 현재 좌표, 초
	vector<int>visited(100001, false);
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		if (cur_x == K) {
			cout << cur_time;
			return;
		}
		// x - 1
		if (cur_x - 1 >= 0 && !visited[cur_x - 1]) {
			visited[cur_x - 1] = true;
			q.push(make_pair(cur_x - 1, cur_time + 1));
		}
		// x + 1
		if (cur_x + 1 <= 100000 && !visited[cur_x + 1]) {
			visited[cur_x + 1] = true;
			q.push(make_pair(cur_x + 1, cur_time + 1));
		}
		// x * 2
		if (cur_x * 2 <= 100000 && !visited[cur_x * 2]) {
			visited[cur_x * 2] = true;
			q.push(make_pair(cur_x * 2, cur_time + 1));
		}
	}
}
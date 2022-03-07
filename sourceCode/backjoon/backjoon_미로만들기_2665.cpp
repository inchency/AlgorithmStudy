#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int n;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void solve(vector<string>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	solve(v);
	return 0;
}

void solve(vector<string>& v) {
	queue<pair<int, int>>q;
	q.push({ 0, 0 });
	vector<vector<int>>visited(n, vector<int>(n, INT_MAX));
	visited[0][0] = 0; // 몇번 벽을 뚫었는지
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) { // 맵 안에 있고
				if (v[next_x][next_y] == '1') { // 빈 방이면
					if (visited[next_x][next_y] > visited[cur_x][cur_y]) { // 벽을 더 적게 뚫으면 갱신
						visited[next_x][next_y] = visited[cur_x][cur_y];
						q.push(make_pair(next_x, next_y));
					}
				}
				else { // 벽이면
					if (visited[next_x][next_y] > visited[cur_x][cur_y] + 1) {
						visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
						q.push(make_pair(next_x, next_y));
					}
				}
			}
		}
	}
	cout << visited[n - 1][n - 1];
}
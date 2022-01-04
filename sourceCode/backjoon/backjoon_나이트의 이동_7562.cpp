#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N;
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

struct Info {
	int x, y;
	int cnt;
};

void solve(vector<vector<int>>&v);

int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> N;
		vector<vector<int>>v(N);
		solve(v);
	}
	return 0;
}

void solve(vector<vector<int>>& v){
	int answer = -1;
	int start_x, start_y, dest_x, dest_y;
	cin >> start_x >> start_y >> dest_x >> dest_y;
	queue<Info>q;
	Info info;
	info.x = start_x; info.y = start_y; info.cnt = 0;
	vector<vector<bool>>visited(N, vector<bool>(N, false));
	q.push(info);
	visited[start_x][start_y] = true;
	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_cnt = q.front().cnt;
		q.pop();
		if (cur_x == dest_x && cur_y == dest_y) {
			answer = cur_cnt;
			break;
		}
		for (int i = 0; i < 8; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
				if (!visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					Info info2;
					info2.x = next_x; info2.y = next_y; info2.cnt = cur_cnt + 1;
					q.push(info2);
				}
			}
		}
	}
	cout << answer << "\n";
}
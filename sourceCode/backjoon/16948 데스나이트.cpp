// https://www.acmicpc.net/problem/16948


#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N;
int r1, c1, r2, c2;
int dr[6] = { -2, -2, 0, 0, 2, 2 };
int dc[6] = { -1, 1, -2, 2, -1, 1 };

struct Info {
	int row, col;
	int cnt;
};

void solve(vector<vector<int>>&v);

int main() {
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
	vector<vector<int>>v(N, vector<int>(N));
	solve(v);
	return 0;
}

void solve(vector<vector<int>>& v) {
	vector<vector<pair<bool, int>>>visited(N, vector<pair<bool, int>>(N, pair<bool, int>(false, INT_MAX)));
	queue<Info>q;
	Info info;
	info.row = r1; info.col = c1; info.cnt = 0;
	q.push(info);
	visited[r1][c1].first = true;
	visited[r1][c1].second = 0;
	while (!q.empty()) {
		int cur_row = q.front().row;
		int cur_col = q.front().col;
		int cur_cnt = q.front().cnt;
		if (cur_row == r2 && cur_col == c2) {
			cout << cur_cnt;
			return;
		}
		q.pop();
		for (int i = 0; i < 6; i++) {
			int next_row = cur_row + dr[i];
			int next_col = cur_col + dc[i];
			int next_cnt = cur_cnt + 1;
			if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
				if (!visited[next_row][next_col].first && visited[next_row][next_col].second > next_cnt) {
					visited[next_row][next_col].first = true;
					visited[next_row][next_col].second = cur_cnt;
					Info info;
					info.row = next_row; info.col = next_col; info.cnt = next_cnt;
					q.push(info);
				}
			}
		}
	}
	cout << -1;
}

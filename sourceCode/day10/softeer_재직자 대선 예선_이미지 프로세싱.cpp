#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, W, Q;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

void solve(vector<vector<int>>& v, int row, int col, int change_color, int origin_color);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> H >> W;
	vector<vector<int>>v(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> v[i][j];
		}
	}
	cin >> Q;
	int row, col, color;
	for (int i = 0; i < Q; i++) {
		cin >> row >> col >> color;
		solve(v, row-1, col-1, color, v[row-1][col-1]);
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

void solve(vector<vector<int>>& v, int row, int col, int change_color, int origin_color) {
	queue<pair<int, int>>q;
	q.push(make_pair(row, col));
	vector<vector<bool>>visited(H, vector<bool>(W, false));
	visited[row][col] = true;
	v[row][col] = change_color;
	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (next_row >= 0 && next_row < H && next_col >= 0 && next_col < W) {
				if (!visited[next_row][next_col] && v[next_row][next_col] == origin_color) {
					visited[next_row][next_col] = true;
					v[next_row][next_col] = change_color;
					q.push(make_pair(next_row, next_col));
				}
			}
		}
	}
}

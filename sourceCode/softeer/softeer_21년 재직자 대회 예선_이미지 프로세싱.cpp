#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, W, Q;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

struct Info{
	int row, col;
	int color;
};

void solve(vector<vector<int>>& v);

int main() {
	ios::sync_with_stdio(0);
	cin >> H >> W;
	vector<vector<int>>v(H + 1, vector<int>(W + 1));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> v[i][j];
		}
	}
	solve(v);
	return 0;
}

void solve(vector<vector<int>>& v) {
	cin >> Q;
	int row, col, change_color;
	for (int i = 0; i < Q; i++) {
		cin >> row >> col >> change_color;
		vector<vector<int>>visited(H + 1, vector<int>(W + 1, false));
		queue<Info>q;
		Info info;
		info.row = row; info.col = col; info.color = v[row][col];
		q.push(info);
		while (!q.empty()) {
			int cur_row = q.front().row;
			int cur_col = q.front().col;
			int cur_color = q.front().color;
			q.pop();
			visited[cur_row][cur_col] = true;
			v[cur_row][cur_col] = change_color;
			for (int j = 0; j < 4; j++) {
				int next_row = cur_row + d_row[j];
				int next_col = cur_col + d_col[j];
				if (next_row >= 1 && next_row <= H && next_col >= 1 && next_col <= W) {
					if (!visited[next_row][next_col] && v[next_row][next_col] == cur_color) {
						Info info;
						info.row = next_row; info.col = next_col; info.color = cur_color;
						q.push(info);
					}
				}
			}
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
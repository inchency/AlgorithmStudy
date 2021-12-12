#include <iostream>
#include <vector>

using namespace std;

int T, N, M, K;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

void solve(vector<vector<int>>& v, vector<vector<bool>>& visited, int cur_row, int cur_col);

int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		vector<vector<int>>v(N, vector<int>(M, 0));
		vector<vector<bool>>visited(N, vector<bool>(M, false));
		for (int i = 0; i < K; i++) {
			int row, col;
			cin >> col >> row;
			v[row][col] = 1;
		}
		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[i][j] == 1 && !visited[i][j]) {
					visited[i][j] = true;
					solve(v, visited, i, j);
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}

void solve(vector<vector<int>>& v, vector<vector<bool>>& visited, int cur_row, int cur_col) {
	for (int i = 0; i < 4; i++) {
		int next_row = cur_row + d_row[i];
		int next_col = cur_col + d_col[i];
		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
			if (v[next_row][next_col] == 1 && !visited[next_row][next_col]) {
				visited[next_row][next_col] = true;
				solve(v, visited, next_row, next_col);
			}
		}
	}
}
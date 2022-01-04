#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int T, N;
int problem = 1;
int d_row[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int d_col[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void solve(vector<vector<char>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		vector<vector<char>>v(N, vector<char>(N, '.'));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[i][j];
			}
		}
		solve(v);
	}

	return 0;
}

void solve(vector<vector<char>>& v) {
	// 숫자 입력하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == '.') {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int next_row = i + d_row[k];
					int next_col = j + d_col[k];
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
						if (v[next_row][next_col] == '*') cnt++;
					}
				}
				v[i][j] = cnt + '0';
			}
		}
	}
	int answer = 0;
	queue<pair<int, int>>q;
	vector<vector<bool>>visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == '0' && !visited[i][j]) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
				answer++;
				while (!q.empty()) {
					int cur_row = q.front().first;
					int cur_col = q.front().second;
					q.pop();
					if (v[cur_row][cur_col] == '0') {
						for (int k = 0; k < 8; k++) {
							int next_row = cur_row + d_row[k];
							int next_col = cur_col + d_col[k];
							if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
								if (!visited[next_row][next_col]) {
									visited[next_row][next_col] = true;
									q.push(make_pair(next_row, next_col));
								}
							}
						}
					}
					
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] != '0' && v[i][j] != '*' && !visited[i][j]) answer++;
		}
	}
	cout << "#" << problem++ << " " << answer << "\n";
}
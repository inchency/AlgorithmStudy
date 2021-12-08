#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

void solve(vector<string>& v);

struct Info {
	int row, col;
	int cnt;
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<string>v(N);
	for (int i = 0; i < N; i++) 
		cin >> v[i];
	solve(v);
	return 0;
}

void solve(vector<string>& v) {
	int target_row = N - 1;
	int target_col = M - 1;
	queue<Info>q;
	vector<vector<bool>>visited(N, vector<bool>(M, false));
	Info info;
	info.row = 0; info.col = 0; info.cnt = 1;
	q.push(info);
	visited[0][0] = true;
	int answer = INT_MAX;
	while (!q.empty()) {
		int cur_row = q.front().row;
		int cur_col = q.front().col;
		int cur_cnt = q.front().cnt;
		q.pop();
		if (cur_row == target_row && cur_col == target_col) 
			answer = min(answer, cur_cnt);
		
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
				if (v[next_row][next_col] == '1' && !visited[next_row][next_col]) {
					visited[next_row][next_col] = true;
					Info info;
					info.row = next_row; info.col = next_col; info.cnt = cur_cnt + 1;
					q.push(info);
				}
			}
		}
	}
	cout << answer;
}

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int answer = INT_MAX;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

void solve(vector<vector<int>>& v);
int sum_dir(vector<vector<bool>>& visited, vector<vector<int>>& v, int row, int col);
void find_next_flower_dir(int row, int col, int total_cost, vector<vector<bool>>& visited, vector<vector<int>>& v, int flower_cnt);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<vector<int>>v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	solve(v);
	cout << answer;
	return 0;
}

void solve(vector<vector<int>>& v) {
	vector<vector<bool>>visited(N, vector<bool>(N, false));
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (!visited[i][j]) {
				int sum_cost = sum_dir(visited, v, i, j);
				// ���� �� ã��
				find_next_flower_dir(i, j, sum_cost, visited, v, 1);
				// ��Ʈ��ŷ (�湮 �ʱ�ȭ)
				for (int k = 0; k < 4; k++) {
					int next_row = i + d_row[k];
					int next_col = j + d_col[k];
					visited[next_row][next_col] = false;
				}
				visited[i][j] = false;
			}
		}
	}
}

int sum_dir(vector<vector<bool>>& visited, vector<vector<int>>& v, int row, int col) {
	// ���� ���� ���� ��
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (visited[next_row][next_col]) {
			return -1;
		}
	}
	// �� ��ġ ���� �� ��
	visited[row][col] = true;
	int s = v[row][col];
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		visited[next_row][next_col] = true;
		s += v[next_row][next_col];
	}
	return s;
}

void find_next_flower_dir(int row, int col, int total_cost, vector<vector<bool>>& visited, vector<vector<int>>& v, int flower_cnt) {
	// �� ���� �� �ɾ����� ���� ����
	if (flower_cnt == 3) {
		answer = min(answer, total_cost);
		return;
	}
	for (int i = row; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (!visited[i][j]) {
				int sum_cost = sum_dir(visited, v, i, j);
				// ���� ���׾����� ���� �� ã��
				if (sum_cost != -1) {
					find_next_flower_dir(i, j, sum_cost + total_cost, visited, v, flower_cnt + 1);
					// ��Ʈ��ŷ (�湮 �ʱ�ȭ)
					for (int k = 0; k < 4; k++) {
						int next_row = i + d_row[k];
						int next_col = j + d_col[k];
						visited[next_row][next_col] = false;
					}
					visited[i][j] = false;
				}
			}
		}
	}
}
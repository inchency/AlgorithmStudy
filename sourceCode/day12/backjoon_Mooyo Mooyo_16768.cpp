#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int N, K;
bool check_cnt;
bool pop_check = false;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

void solve(vector<string>& v);
void do_pop(int row, int col, vector<string>& v, vector<vector<bool>>& visited, stack<pair<int, int>>&s, int cur_num);
void do_gravity(vector<string>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	vector<string>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	solve(v);
	return 0;
}

void solve(vector<string>& v) {
	while (1) {
		check_cnt = false; // K개 미만이면 종료 조건
		// 0이 아닌 것 탐색하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				if (v[i][j] != '0') {
					vector<vector<bool>>visited(N, vector<bool>(10, false));
					stack<pair<int, int>>s;
					s.push(make_pair(i, j));
					visited[i][j] = true;
					pop_check = false;
					do_pop(i, j, v, visited, s, v[i][j]);
				}
			}
		}
		// 중력 적용
		do_gravity(v);
		if (!check_cnt) break;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}
}

void do_pop(int row, int col, vector<string>& v, vector<vector<bool>>& visited, stack<pair<int, int>>&s, int cur_num) {
	if (pop_check) {
		check_cnt = true;
		while (!s.empty()) {
			int del_row = s.top().first;
			int del_col = s.top().second;
			s.pop();
			v[del_row][del_col] = '0';
		}
	}
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < 10) {
			if (!visited[next_row][next_col] && v[next_row][next_col] == cur_num) {
				visited[next_row][next_col] = true;
				s.push(make_pair(next_row, next_col));
				if (s.size() >= K) pop_check = true;
				do_pop(next_row, next_col, v, visited, s, cur_num);
			}
		}
	}
}

void do_gravity(vector<string>& v) {
	for (int j = 0; j < 10; j++) {
		stack<int>s; // '0'이 아닌 좌표의 숫자 찾기
		for (int i = 0; i < N; i++) {
			if (v[i][j] != '0') {
				s.push(v[i][j]);
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			if (s.empty()) {
				v[i][j] = '0';
			}
			else {
				int num = s.top();
				s.pop();
				v[i][j] = num;
			}
		}
	}
}
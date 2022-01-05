#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int R, C, answer = 0;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };
vector<bool>visited(26, false);

void solve(vector<string>& v, int cur_row, int cur_col, int cnt);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	vector<string>v(R);
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		v[i] = s;
	}
	visited[v[0][0] - 'A'] = true;
	solve(v, 0, 0, 1);
	cout << answer;
	return 0;
}

void solve(vector<string>& v, int cur_row, int cur_col, int cnt){
	answer = max(answer, cnt);
	for (int i = 0; i < 4; i++) {
		int next_row = cur_row + d_row[i];
		int next_col = cur_col + d_col[i];
		if (next_row >= 0 && next_row < R && next_col >= 0 && next_col < C) {
			char next_alphabet = v[next_row][next_col];
			int next_index = next_alphabet - 'A';
			if (!visited[next_index]) {
				visited[next_index] = true;
				solve(v, next_row, next_col, cnt + 1);
				visited[next_index] = false;
			}
		}
	}
}

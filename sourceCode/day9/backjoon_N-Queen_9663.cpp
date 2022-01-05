#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = 0;

void solve(vector<int>&v, int cur_row);
bool is_available(vector<int>& v, int cur_row);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N, -1);
	solve(v, 0);
	cout << answer;
	return 0;
}

void solve(vector<int>&v, int cur_row) {
	if (cur_row == N) {
		answer++;
		return;
	}
	for (int col = 0; col < N; col++) {
		v[cur_row] = col;
		if (is_available(v, cur_row)) {
			solve(v, cur_row + 1);
		}
	}
}

bool is_available(vector<int>& v, int cur_row) {
	for (int i = 0; i < cur_row; i++) {
		if (v[cur_row] == v[i] || abs(v[cur_row] - v[i]) == abs(cur_row - i)) 
			return false;
	}
	return true;
}

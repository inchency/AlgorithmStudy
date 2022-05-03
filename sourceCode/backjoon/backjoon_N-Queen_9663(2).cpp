// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, answer = 0;

void solve(vector<int>& v, int cur_row);
bool isAvailable(vector<int>& v, int cur_row);

int main() {
	cin >> N;
	vector<int>v(N, -1);
	solve(v, 0);
	cout << answer;
	return 0;
}

void solve(vector<int>& v, int cur_row) {
	if (cur_row == N) {
		answer++;
		return;
	}
	for (int col = 0; col < N; col++) {
		v[cur_row] = col;
		if (isAvailable(v, cur_row))
			solve(v, cur_row + 1);
	}
}

bool isAvailable(vector<int>& v, int cur_row) {
	for (int i = 0; i < cur_row; i++) {
		if (v[cur_row] == v[i] || cur_row - i == abs(v[cur_row] - v[i])) 
			return false;
	}
	return true;
}

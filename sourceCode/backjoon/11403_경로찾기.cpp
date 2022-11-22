// https://www.acmicpc.net/problem/11403

#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N;

void solve(vector<vector<int>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<vector<int>>v(N, vector<int>(N, INF));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			if (v[i][j] == 0) v[i][j] = INF;
		}
	}
	solve(v);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == INF) v[i][j] = 0;
			else v[i][j] = 1;
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

void solve(vector<vector<int>>& v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (v[j][i] != INF && v[i][k] != INF) {
					v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
				}
			}
		}
	}
}

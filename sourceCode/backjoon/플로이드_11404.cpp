// https://www.acmicpc.net/problem/11404

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#define INF 987654321

using namespace std;

int N, M;

void solve(vector<vector<int>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>>v(N + 1, vector<int>(N + 1, INF));
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = v[a][b] > c ? c : v[a][b];
	}

	solve(v);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || v[i][j] == INF)
				cout << 0 << " ";
			else
				cout << v[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

void solve(vector<vector<int>>& v) {
	for (int i = 1; i <= N; i++) { // 거쳐가는 노드
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if(v[j][i] != INF && v[i][k] != INF)
					v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
			}
		}
	}
}

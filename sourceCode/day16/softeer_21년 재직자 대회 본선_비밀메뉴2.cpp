#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	vector<int>v_n(N);
	vector<int>v_m(M);
	for (int i = 0; i < N; i++) 
		cin >> v_n[i];
	for (int i = 0; i < M; i++)
		cin >> v_m[i];
	vector<vector<int>>v(N, vector<int>(M, 0));
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v_n[i] == v_m[j]) {
				if (i == 0 || j == 0) 
					v[i][j] = 1;
				else 
					v[i][j] = v[i - 1][j - 1] + 1;
			}
			answer = max(answer, v[i][j]);
		}
	}
	cout << answer;
	return 0;
}
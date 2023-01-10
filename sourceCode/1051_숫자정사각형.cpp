// https://www.acmicpc.net/problem/1051

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;

void solve(vector<string>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<string>v(N);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v[i] = s;
	}
	solve(v);
	return 0;
}

void solve(vector<string>& v) {
	int start_num = 0;
	bool n_is_small = false;
	if (N < M)
		start_num = N - 1;
	else
		start_num = M - 1;

	for (int i = start_num; i >= 0; i--) {
		for (int j = 0; j < N - i; j++) {
			for (int k = 0; k < M - i; k++) {
				char lu = v[j][k];
				char ru = v[j][k + i];
				char ld = v[j + i][k];
				char rd = v[j + i][k + i];
				if (lu == ru && lu == ld && lu == rd) {
					if (ru == ld && ru == rd) {
						if (ld == rd) {
							cout << pow(i + 1, 2);
							return;
						}
					}
				}
			}
		}
	}
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

void solve(vector<string>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	vector<string>v(R);
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		v[i] = s;
	}
	solve(v);
	return 0;
}

void solve(vector<string>& v) {
	bool flag = true;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < R; j++) {
			if (v[i][j] == 'S') {
				for (int k = 0; k < 4; k++) {
					int next_row = i + d_row[k];
					int next_col = j + d_col[k];
					if (next_row >= 0 && next_row < R && next_col >= 0 && next_col < C) {
						if (v[next_row][next_col] == 'W') {
							flag = false;
							cout << "0";
							return;
						}
						else {
							if (v[next_row][next_col] == '.') {
								v[next_row][next_col] = 'D';
							}
						}
					}
				}
			}
		}
	}
	if (flag) {
		cout << "1" << "\n";
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << v[i][j];
			}
			cout << "\n";
		}
	}
}
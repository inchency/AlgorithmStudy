#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, Q;

struct ID {
	int status = 0; // 0 = æ»∏‘¿Ω, 1 = ¿ÃπÃ π‰∏‘¿Ω, 2 = π‰∏‘¥¬¡ﬂ
	int x;
	int y;
};

vector<ID>v_id(10001);

bool success_eat(vector<vector<int>>&v, vector<ID>&v_id, int pid);
int nearnest(vector<vector<int>>& v, int x, int y);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> Q;
	vector<vector<int>>v(N+2, vector<int>(M+2, 0));
	for (int i = 0; i < Q; i++) {
		string in_out;
		int pid;
		cin >> in_out >> pid;
		if (in_out == "In") {
			if (v_id[pid].status == 2) {
				cout << pid << " already seated.\n";
			}
			else if (v_id[pid].status == 1) {
				cout << pid << " already ate lunch.\n";
			}
			else { // status == 0 ¿œ∂ß
				if (!success_eat(v, v_id, pid)) {
					cout << "There are no more seats.\n";
				}
				else {
					cout << pid << " gets the seat (" << v_id[pid].x << ", " << v_id[pid].y << ").\n";
				}
			}
		}
		else { // Out
			if (v_id[pid].status == 0) {
				cout << pid << " didn't eat lunch.\n";
			}
			else if (v_id[pid].status == 1) {
				cout << pid << " already left seat.\n";
			}
			else {
				cout << pid << " leaves from the seat (" << v_id[pid].x << ", " << v_id[pid].y << ").\n";
				v[v_id[pid].x][v_id[pid].y] = 0;
				//v_id[pid].status = 1;
			}
		}
	}
	return 0;
}

bool success_eat(vector<vector<int>>& v, vector<ID>& v_id, int pid) {
	int dist_max = 0;
	int x = 0, y = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (v[i][j] == 0 && v[i-1][j] == 0 && v[i+1][j] == 0 && v[i][j-1] == 0 && v[i][j+1] == 0) {
				int dist = nearnest(v, i, j);
				if (dist_max < dist) {
					dist_max = dist;
					x = i;
					y = j;
				}
			}
		}
	}
	if (dist_max == 0) {
		return false;
	}
	else {
		v_id[pid].status = 2;
		v_id[pid].x = x;
		v_id[pid].y = y;
		v[x][y] = 1;
		return true;
	}
}

int nearnest(vector<vector<int>>& v, int x, int y) {
	int dist_min = INT_MAX;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < M; j++) {
			if (v[i][j] == 1) {
				int dist = (x - i) * (x - i) + (y - j) * (y - j);
				if (dist < dist_min) {
					dist_min = dist;
				}
			}
		}
	}
	return dist_min;
}
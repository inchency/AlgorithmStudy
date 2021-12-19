//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//int N;
//int prob_num = 1;
//int d_row[4] = { -1, 1, 0, 0 };
//int d_col[4] = { 0, 0, -1, 1 };
//
//
//struct Info {
//	int row, col;
//	int cost;
//};
//
//struct comp {
//	bool operator()(const Info& a, const Info& b) {
//		return a.cost > b.cost;
//	}
//};
//
//void solve(vector<vector<int>>& v);
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	while (1) {
//		cin >> N;
//		if (N == 0) return 0;
//		vector<vector<int>>v(N, vector<int>(N));
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> v[i][j];
//			}
//		}
//		solve(v);
//	}
//	return 0;
//}
//
//void solve(vector<vector<int>>& v){
//	priority_queue<Info, vector<Info>, comp>pq;
//	Info info;
//	info.row = 0; info.col = 0; info.cost = v[0][0];
//	pq.push(info);
//	vector<vector<int>>dist(N, vector<int>(N, INT_MAX));
//	dist[0][0] = 0;
//	while (!pq.empty()) {
//		int cur_row = pq.top().row;
//		int cur_col = pq.top().col;
//		int cur_cost = pq.top().cost;
//		pq.pop();
//		for (int i = 0; i < 4; i++) {
//			int next_row = cur_row + d_row[i];
//			int next_col = cur_col + d_col[i];
//			if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
//				int next_cost = cur_cost + v[next_row][next_col];
//				if (next_cost < dist[next_row][next_col]) {
//					dist[next_row][next_col] = next_cost;
//					Info info;
//					info.row = next_row; info.col = next_col; info.cost = next_cost;
//					pq.push(info);
//				}
//			}
//		}
//	}
//	cout << "Problem " << prob_num++ << ": " << dist[N - 1][N - 1] << "\n";
//}
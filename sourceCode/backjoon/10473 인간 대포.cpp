// https://www.acmicpc.net/problem/10473

#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <cmath>
#include <cfloat>

#define INF DBL_MAX

using namespace std;

double start_x, start_y, dest_x, dest_y;
int N;

struct Info {
	int next_node;
	double next_x;
	double next_y;
};

void solve(vector<pair<double, double>>& v, vector<vector<Info>>& adj);


struct comp {
	bool operator()(const pair<int, double>& a, const pair<int, double>& b) {
		return a.second > b.second;
	}

};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> start_x >> start_y;
	cin >> dest_x >> dest_y;
	cin >> N;
	vector<pair<double, double>>v(N + 2);
	v[0] = { start_x, start_y };
	v[N + 1] = { dest_x, dest_y };
	for (int i = 1; i <= N; i++) 
		cin >> v[i].first >> v[i].second;
	vector<vector<Info>>adj(N+2);
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			if (i == j) continue;
			Info info = { j, v[j].first, v[j].second };
			adj[i].push_back(info);
		}
	}
	solve(v, adj);
	return 0;
}

void solve(vector<pair<double, double>>& v, vector<vector<Info>>& adj) {
	vector<double>time(N + 2, INF);
	int start_node = 0;
	time[start_node] = 0;
	priority_queue<pair<int, double>, vector<pair<int, double>>, comp>pq; // 현재 node, total time
	pq.push(make_pair(start_node, 0));
	while (!pq.empty()) {
		int cur_node = pq.top().first;
		double cur_total_time = pq.top().second;
		double cur_x = v[cur_node].first;
		double cur_y = v[cur_node].second;
		pq.pop();
		for (Info info : adj[cur_node]) {
			int next_node = info.next_node;
			double next_x = info.next_x;
			double next_y = info.next_y;
			double each_node_dist = sqrt((cur_x - next_x) * (cur_x - next_x) + (cur_y - next_y) * (cur_y - next_y));
			// 걸어서만 가기
			double only_walk_time = each_node_dist / 5;
			// 로켓 + 걸어서 가기
			double rocket_time = 2;
			double remain_dist = abs(each_node_dist - 50);
			double walk_time = remain_dist / 5;
			double min_time = only_walk_time < rocket_time + walk_time ? only_walk_time : rocket_time + walk_time;
			double add_time = cur_total_time + min_time;
			if (cur_node == 0) add_time = only_walk_time;
			if (time[next_node] > add_time) {
				time[next_node] = add_time;
				pq.push({ next_node, add_time });
			}
		}
	}
	cout << time[N + 1];
}

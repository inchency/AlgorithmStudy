// https://school.programmers.co.kr/learn/courses/30/lessons/62050

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int d_r[4] = { -1, 1, 0, 0 };
int d_c[4] = { 0, 0, -1, 1 };

struct Info {
	int cost, start_num = NULL, dest_num;
};

struct comp {
	bool operator()(const Info& a, const Info& b) {
		return a.cost > b.cost;
	}
};

int find_root(vector<int>& root_v, int node) {
	if (root_v[node] == node) return node;
	root_v[node] = find_root(root_v, root_v[node]);
	return root_v[node];
}

void do_union(vector<int>& root_v, vector<int>& rank_v, int start_node, int dest_node) {
	int start_node_root = root_v[start_node];
	int dest_node_root = root_v[dest_node];
	if (rank_v[start_node_root] > rank_v[dest_node_root]) {
		root_v[dest_node_root] = start_node_root;
	}
	else if (rank_v[start_node_root] < rank_v[dest_node_root]) {
		root_v[start_node_root] = dest_node_root;
	}
	else {
		rank_v[start_node_root]++;
		root_v[dest_node_root] = start_node_root;
	}
}

int solution(vector<vector<int>> land, int height) {
	int answer = 0;
	queue<pair<int, int>>q;
	size_t y_size = land.size();
	size_t x_size = land[0].size();
	vector<vector<int>>visited(y_size, vector<int>(x_size, 0));
	int land_num = 0;
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++) {
			if (!visited[i][j]) {
				land_num++;
				visited[i][j] = land_num;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int cur_row = q.front().first;
					int cur_col = q.front().second;
					int cur_num = land[cur_row][cur_col];
					q.pop();
					for (int i = 0; i < 4; i++) {
						int next_row = cur_row + d_r[i];
						int next_col = cur_col + d_c[i];
						if (next_row >= 0 && next_row < y_size && next_col >= 0 && next_col < x_size) {
							if (!visited[next_row][next_col]) {
								int next_num = land[next_row][next_col];
								int cha = abs(next_num - cur_num);
								if (cha <= height) {
									visited[next_row][next_col] = land_num;
									q.push(make_pair(next_row, next_col));
								}
							}
						}
					}
				}
			}
		}
	}
	//for (int i = 0; i < y_size; i++) {
	//	for (int j = 0; j < x_size; j++) {
	//		cout << visited[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	// 인접하는 다른 땅 번호의 사다리의 비용 리스트 구하기
	map<set<int>, int>m; //map<set<start num, end num>, cost >
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++) {
			int cur_num = visited[i][j];
			for (int k = 0; k < 4; k++) {
				int next_row = i + d_r[k];
				int next_col = j + d_c[k];
				if (next_row >= 0 && next_row < y_size && next_col >= 0 && next_col < x_size) {
					int next_num = visited[next_row][next_col];
					if (cur_num != next_num) {
						int cost = abs(land[i][j] - land[next_row][next_col]);
						set<int>temp_s;
						temp_s.insert(cur_num);
						temp_s.insert(next_num);
						if(m.find(temp_s) == m.end())
							m[temp_s] = cost;
						else 
							m[temp_s] = min(m[temp_s], cost);
					}
				}
			}
		}
	}
	//for (auto s : m) {
	//	for (auto e : s.first) {
	//		cout << e << " ";
	//	}
	//	cout << " : " << s.second << endl;;
	//}
	//cout << "---------------------------------------------\n";
	// 크루스칼 풀이
	// map -> vector로 변환
	vector<Info>info_v;
	for (auto s : m) {
		Info info;
		info.cost = s.second;
		for (auto e : s.first) {
			if (info.start_num == NULL)
				info.start_num = e;
			else
				info.dest_num = e;
		}
		info_v.push_back(info);
	}
	// priority_queue에 push
	priority_queue<Info, vector<Info>, comp>pq;
	for (Info info : info_v) 
		pq.push(info);

	// 초기화
	int N = land_num;
	vector<int>rank_v(N + 1, 0);
	vector<int>root_v(N + 1);
	for (int i = 1; i <= N; i++) root_v[i] = i;

	while (!pq.empty()) {
		Info info = pq.top();
		pq.pop();
		if (find_root(root_v, info.start_num) != find_root(root_v, info.dest_num)) {
			do_union(root_v, rank_v, info.start_num, info.dest_num);
			answer += info.cost;
		}
	}
	//cout << answer;
	return answer;
}

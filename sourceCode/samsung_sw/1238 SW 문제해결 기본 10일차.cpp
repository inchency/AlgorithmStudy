// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15B1cKAKwCFAYD&categoryId=AV15B1cKAKwCFAYD&categoryType=CODE&problemTitle=%EC%9D%BC%EC%B0%A8&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=3

#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

int T = 10;
int n, start_node;
int from, to;

void solve(vector<set<int>>& v, int prob_num);

int main() {
	for (int i = 1; i <= T; i++) {
		cin >> n >> start_node;
		vector<set<int>>v(101);
		for (int j = 0; j < n / 2; j++) {
			cin >> from >> to;
			v[from].insert(to);
		}
		solve(v, i);
	}
	return 0;
}

void solve(vector<set<int>>& v, int prob_num) {
	vector<bool>visited(101, false);
	queue<pair<int, int>>q; // cur_node, cnt;
	visited[start_node] = true;
	q.push({ start_node, 1 });
	map<int, set<int>>m; // key : cnt, value : set<node>
	while (!q.empty()) {
		int cur_node = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();
		for (int next_node : v[cur_node]) {
			if (!visited[next_node]) {
				visited[next_node] = true;
				if (m.find(cur_cnt + 1) == m.end())
					m[cur_cnt + 1] = set<int>();
				m[cur_cnt + 1].insert(next_node);
				q.push({ next_node, cur_cnt + 1 });
			}
		}
	}
	auto answer_it = --m.end();
	auto answer_s = answer_it->second;
	int answer = *(--answer_s.end());
	cout << "#" << prob_num << " " << answer << "\n";
}

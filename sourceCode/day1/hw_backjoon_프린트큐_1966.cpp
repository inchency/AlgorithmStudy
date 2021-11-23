#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, T;

void solve(vector<pair<int, bool>>&v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<pair<int, bool>>v(N);
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			v[i] = make_pair(temp, false);
		}
		solve(v);
	}

	return 0;
}

void solve(vector<pair<int, bool>>&v) {
	// 찾아야할 num 기록해두기
	v[M].second = true;
	int answer = 0;
	queue<pair<int,bool>>q;
	priority_queue<int>pq;
	for (auto e : v) {
		q.push(e);
		pq.push(e.first);
	}
	while (1) {
		int front_num = q.front().first;
		int target_flag = q.front().second;
		int max_num = pq.top();
		if (max_num != front_num) {
			q.pop();
			q.push(make_pair(front_num, target_flag));
			continue;
		}
		if (target_flag) {
			answer++; // 프린트
			cout << answer << "\n";
			return;
		}
		else {
			// 프린트
			answer++;
			q.pop();
			pq.pop();
		}
	}
}

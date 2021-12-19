#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int N, M;

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

void solve(vector<vector<pair<int, int>>>& v);
bool is_prime(int num);
int next_prime(int num);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<pair<int, int>>>v(N + 1);
	for (int i = 0; i < M; i++) {
		int start, dest, cost;
		cin >> start >> dest >> cost;
		v[start].push_back(make_pair(dest, cost));
		v[dest].push_back(make_pair(start, cost));
	}
	solve(v);
	return 0;
}

void solve(vector<vector<pair<int, int>>>& v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
	pq.push(make_pair(1, 0));
	vector<int>dist(N + 1, INT_MAX);
	dist[1] = 0;
	while (!pq.empty()) {
		int cur_gym = pq.top().first;
		int cur_need_level = pq.top().second;
		pq.pop();
		for (auto e : v[cur_gym]) {
			int next_gym = e.first;
			int next_need_level = e.second + 1;
			int next_need_prime_level = next_prime(next_need_level);
			if (dist[next_gym] > max(cur_need_level, next_need_prime_level)) {
				dist[next_gym] = max(cur_need_level, next_need_prime_level);
				pq.push(make_pair(next_gym, max(cur_need_level, next_need_prime_level)));
			}
		}
	}
	for (auto e : dist) cout << e << " ";
	//cout << *(dist.end() - 1);
}

bool is_prime(int num) {
	if (num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int next_prime(int num) {
	while (!is_prime(num)) num++;
	return num;
}

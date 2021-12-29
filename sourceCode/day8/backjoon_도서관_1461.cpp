#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

struct comp {
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	priority_queue<int, vector<int>, comp>minus_q;
	priority_queue<int>plus_q;
	int max_num = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (max_num < abs(num)) max_num = abs(num);
		if (num > 0) plus_q.push(num);
		else minus_q.push(num);
	}
	int walk = 0;
	while (!minus_q.empty()) {
		int top = abs(minus_q.top());
		walk += top;
		for (int i = 0; i < M; i++) {
			if (minus_q.empty()) break;
			minus_q.pop();
		}
	}
	while (!plus_q.empty()) {
		int top = plus_q.top();
		walk += top;
		for (int i = 0; i < M; i++) {
			if (plus_q.empty()) break;
			plus_q.pop();
		} 
	}
	walk =  walk * 2 - max_num;
	cout << walk;

	return 0;
}

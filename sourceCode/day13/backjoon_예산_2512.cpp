#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, total_max;

void solve(vector<int>& v, int left, int right);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N);
	int max_num = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		max_num = max(max_num, v[i]);
	}
	cin >> total_max;
	solve(v, 1, max_num);
	return 0;
}

// binary search
void solve(vector<int>& v, int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		int total_cost = 0;
		for (auto num : v) {
			int cost = min(mid, num);
			total_cost += cost;
		}
		// 가능하면 예산을 늘린다.
		if (total_cost <= total_max)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left - 1;
}
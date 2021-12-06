#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M;

void binary_search_solve(vector<long long>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<long long>v(N);
	for (long long i = 0; i < N; i++) {
		cin >> v[i];
	}
	binary_search_solve(v);
	return 0;
}

void binary_search_solve(vector<long long>& v) {
	long long right = *max_element(v.begin(), v.end());
	long long left = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long get_tree = 0;
		for (auto e : v) {
			if(e > mid)
				get_tree += e - mid;
		}
		if (get_tree >= M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left - 1;
}

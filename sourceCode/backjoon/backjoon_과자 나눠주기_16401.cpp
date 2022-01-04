#include <iostream>
#include <vector>

using namespace std;

int M, N;

void solve(vector<long long>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	vector<long long>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	solve(v);
	return 0;
}

void solve(vector<long long>& v) {
	long long right = 0;
	for (auto e : v) right += e;
	long long left = 1;
	while (left <= right) {
		long long mid = (left + right) / 2;
		int cookie_cnt = 0;
		for (auto e : v) 
			cookie_cnt += e / mid;
		if (cookie_cnt >= M) left = mid + 1;
		else right = mid - 1;
	}
	cout << left - 1;
}
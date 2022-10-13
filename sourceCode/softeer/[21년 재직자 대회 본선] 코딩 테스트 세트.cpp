// https://softeer.ai/practice/info.do?idx=1&eid=630

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T;

void solve(vector<long long>& v, vector<long long>& c, vector<long long>& d);
bool isPossible(vector<long long>& c, vector<long long> d, long long target);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> T;
	for (int i = 0; i < T; i++) {
		vector<long long>v(2 * N);
		vector<long long>c(N + 1);
		vector<long long>d(N);
		bool flag = false;
		int c_ind = 1; int d_ind = 1;
		for (int j = 1; j < 2 * N; j++) {
			cin >> v[j];
			if (!flag) {
				c[c_ind++] = v[j];
				flag = true;
			}
			else {
				d[d_ind++] = v[j];
				flag = false;
			}
		}
		solve(v, c, d);
	}

	return 0;
}

void solve(vector<long long>& v, vector<long long>& c, vector<long long>& d) {
	long long left = 0;
	long long right = *max_element(v.begin(), v.end()) * 3; // 전 현재 후
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (isPossible(c, d, mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left - 1 << "\n";
}

bool isPossible(vector<long long>& c, vector<long long> d, long long target) {
	for (size_t i = 1; i < c.size(); i++) {
		// 가변적인 난이도(n-1 ~ n) 먼저 소진 시키기
		long long remain = target - d[i - 1];
		if (remain <= 0) continue;
		// 고정적인 난이도 소진
		remain = remain - c[i];
		if (remain <= 0) continue;
		// 가변적인 난이도(n, n+1) 소진시키기
		if (i != c.size() - 1) {
			if (remain > d[i]) return false;
			else {
				d[i] = d[i] - remain;
			}
		}
		// 마지막에는 d[i]가 없음
		else return false;
	}

	return true;
}

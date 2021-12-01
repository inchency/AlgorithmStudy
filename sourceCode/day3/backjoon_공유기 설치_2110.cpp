#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

void solve(vector<int>& v, int right);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> C;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int total_gap = 0;
	for (int i = 1; i < N; i++) {
		total_gap += v[i] - v[i-1];
	}
	solve(v, total_gap);
	return 0;
}

void solve(vector<int>& v, int right) {
	int left = 0;
	while (left <= right) {
		int target = (left + right) / 2;
		int gap_sum = 0;
		int share_cnt = 1; // 시작은 0번째 인덱스부터
		bool flag = true;
		for (int i = 1; i < N; i++) {
			gap_sum += v[i] - v[i - 1];
			if (gap_sum >= target) {
				share_cnt++;
				gap_sum = 0;
				if (share_cnt == C) {
					left = target + 1;
					flag = false;
					break;
				}
			}
		}
		// 끝까지 돌았는데 공유기 설치 다 못하면
		if(flag)
			right = target - 1;
	}
	cout << left-1;
}


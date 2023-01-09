// https://www.acmicpc.net/problem/2343

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;

void solve(vector<int>& v);
bool is_possible(vector<int>& v, int target);
bool comp(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<int>v(N);
	for (int i = 0; i < N; i++) 
		cin >> v[i];
	solve(v);
	return 0;
}

void solve(vector<int>& v) {
	int answer = INT_MAX;
	int left = INT_MAX, right = 0;
	for (int n : v) {
		right += n;
		left = min(left, n);
	}
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (is_possible(v, mid)) {
			right = mid - 1;
			answer = min(answer, mid);
		}
		else 
			left = mid + 1;
	}
	cout << answer;
}

bool is_possible(vector<int>& v, int target) {
	int total = 0;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		total += v[i];
		if (total > target) {
			total = 0;
			cnt++;
			i--;
		}
		if (cnt > M) return false;
	}
	return true;
}

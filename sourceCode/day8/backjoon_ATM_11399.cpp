#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int answer = 0;
	int cur_total_time = 0;
	for (int time : v) {
		cur_total_time += time;
		answer += cur_total_time;
	}
	cout << answer;
	return 0;
}

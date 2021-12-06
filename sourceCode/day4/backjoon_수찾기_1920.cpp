#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int target;
		cin >> target;
		cout << binary_search(v.begin(), v.end(), target) << "\n";
	}
	return 0;
}
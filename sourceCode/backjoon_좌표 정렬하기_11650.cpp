#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>>v(N);
	
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[i].first = x; v[i].second = y;
	}
	sort(v.begin(), v.end(), comp);
	for (auto e : v) cout << e.first << " " << e.second << "\n";
	return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool comp(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string N;
	cin >> N;
	int len = N.length();
	vector<int>v(len);
	for (int i = 0; i < len; i++) {
		v[i] = N[i] - '0';
	}
	//sort(v.begin(), v.end(), greater<int>());
	sort(v.begin(), v.end(), comp);
	for (auto e : v) cout << e;

	return 0;
}
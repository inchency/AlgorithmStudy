#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int>v(1001);
	v[1] = 1; v[2] = 3;
	if (n <= 2) {
		cout << v[n];
		return 0;
	}
	for (int i = 3; i <= n; i++) 
		v[i] = (v[i - 1] + v[i - 2] * 2) % 10007;
	cout << v[n];

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	else if (n == 2) {
		cout << 2;
		return 0;
	}
	vector<int>v(n + 1);
	v[0] = 0; v[1] = 1; v[2] = 2;
	for (int i = 3; i <= n; i++) {
		v[i] = (v[i - 2] + v[i - 1]) % 10007;
	}
	cout << v[n];
	return 0;
}

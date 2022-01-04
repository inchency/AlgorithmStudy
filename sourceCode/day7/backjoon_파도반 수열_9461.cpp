#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<long long>v(101, 0);
		v[1] = 1; v[2] = 1; v[3] = 1;
		for (int i = 4; i <= 100; i++) v[i] = v[i - 3] + v[i - 2];
		cout << v[n] << "\n";
	}
	return 0;
}

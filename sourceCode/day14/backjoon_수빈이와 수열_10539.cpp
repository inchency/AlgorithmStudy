#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int>v(N);
	cin >> v[0];
	int s = v[0];
	cout << v[0] << " ";
	for (int i = 1; i < N; i++) {
		int b_num;
		cin >> b_num;
		int product_num = i + 1;
		int get_num = b_num * product_num - s;
		cout << get_num << " ";
		s += get_num;
	}
	
	return 0;
}

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	set<int>s;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int answer;
		int target_num;
		cin >> target_num;
		if (s.find(target_num) != s.end()) cout << "1\n";
		else cout << "0\n";
	}
		

	return 0;
}

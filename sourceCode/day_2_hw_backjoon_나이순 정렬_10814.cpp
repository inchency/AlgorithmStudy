#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int age;
	string name;
	int join_order;
};

bool comp(const Info& a, const Info& b) {
	if (a.age == b.age) {
		return a.join_order < b.join_order;
	}
	else return a.age < b.age;
}

int main() {
	ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<Info>v(N);
	for (int i = 0; i < N; i++) {
		Info info;
		cin >> info.age >> info.name;
		info.join_order = i + 1;
		v[i] = info;
	}
	sort(v.begin(), v.end(), comp);
	for (auto e : v) {
		cout << e.age << " " << e.name << "\n";
	}

	return 0;
}
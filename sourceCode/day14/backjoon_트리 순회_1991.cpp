#include <iostream>
#include <vector>

using namespace std;

int N;

// 전위 순회
void pre_order(vector<pair<int, int>>& v, int node_index);
// 중위 순회
void in_order(vector<pair<int, int>>& v, int node_index);
// 후위 순회
void post_order(vector<pair<int, int>>& v, int node_index);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<pair<int, int>>v(N);
	for (int i = 0; i < N; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		v[parent - 'A'].first = left - 'A';
		v[parent - 'A'].second = right - 'A';
	}
	pre_order(v, 0);
	cout << "\n";
	in_order(v, 0);
	cout << "\n";
	post_order(v, 0);
	return 0;
}

void pre_order(vector<pair<int, int>>& v, int node_index) {
	char convert_char = node_index + 'A';
	if (convert_char != '.') {
		cout << convert_char;
		pre_order(v, v[node_index].first);
		pre_order(v, v[node_index].second);
	}
}
void in_order(vector<pair<int, int>>& v, int node_index) {
	char convert_char = node_index + 'A';
	if (convert_char != '.') {
		in_order(v, v[node_index].first);
		cout << convert_char;
		in_order(v, v[node_index].second);
	}
}

void post_order(vector<pair<int, int>>& v, int node_index) {
	char convert_char = node_index + 'A';
	if (convert_char != '.') {
		post_order(v, v[node_index].first);
		post_order(v, v[node_index].second);
		cout << convert_char;
	}
}
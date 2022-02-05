#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int T;
string s;

void solve(string s);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	getline(cin, s);
	while (T--) {
		getline(cin, s);
		solve(s);
		cout << "\n";
	}

	return 0;
}

void solve(string s) {
	int s_size = s.size();
	stack<char>c_stack;
	for (size_t i = 0; i < s_size; i++) {
		if (s[i] != ' ') {
			c_stack.push(s[i]);
		}
		else {
			while (!c_stack.empty()) {
				char c = c_stack.top();
				c_stack.pop();
				cout << c;
			}
			cout << " ";
		}
	}
	while (!c_stack.empty()) {
		char c = c_stack.top();
		c_stack.pop();
		cout << c;
	}
}
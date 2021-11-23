#include <string>
#include <iostream>
#include <stack>
#include <deque>

using namespace std;

string s;

void solve(string &s);

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		solve(s);
		cout << "\n";
	}

	return 0;
}

void solve(string& s) {
	stack<char>left_s;
	stack<char>right_s;
	for (char c : s) {
		if (c == '<') {
			if (!left_s.empty()) {
				int top = left_s.top();
				left_s.pop();
				right_s.push(top);
			}
		}
		else if (c == '>') {
			if (!right_s.empty()) {
				int top = right_s.top();
				right_s.pop();
				left_s.push(top);
			}
		}
		else if (c == '-') {
			if (!left_s.empty()) {
				left_s.pop();
			}
		}
		else {
			left_s .push(c);
		}
	}
	deque<char>answer;
	while (!left_s.empty()) {
		answer.push_front(left_s.top());
		left_s.pop();
	}
	while (!right_s.empty()) {
		answer.push_back(right_s.top());
		right_s.pop();
	}
	for (auto c : answer) cout << c;
}

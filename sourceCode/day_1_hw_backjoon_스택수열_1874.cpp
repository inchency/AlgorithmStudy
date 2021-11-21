#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int n;

int main() {
	cin >> n;
	queue<int>q;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		q.push(num);
	}
	stack<int>s;
	vector<char>answer;
	for (int i = 1; i <= n+1;) {
		if (s.empty()) {
			answer.push_back('+');
			s.push(i);
			i++;
			continue;
		}
		int stack_top = s.top();
		if (stack_top == q.front()) {
			answer.push_back('-');
			s.pop();
			q.pop();
			if (q.empty()) break;
		}
		else {
			answer.push_back('+');
			s.push(i);
			i++;
		}
	}
	if (!q.empty()) cout << "NO";
	else {
		for (auto e : answer) cout << e << "\n";
	}
	return 0;
}

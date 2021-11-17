#include<iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string answer="";
	int before_num;
	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;
		if (i == 0) {
			if (num == 1) {
				answer = "ascending";
				before_num = num;
			}
			else if (num == 8) {
				answer = "descending";
				before_num = num;
			}
			else {
				answer = "mixed";
				break;
			}
		}
		else {
			if (answer == "ascending") {
				if (before_num > num) {
					answer = "mixed";
					break;
				}
				else {
					before_num = num;
				}
			}
			else {
				if (before_num < num) {
					answer = "mixed";
					break;
				}
				else {
					before_num = num;
				}
			}
		}
	}
	cout << answer;
	return 0;
}

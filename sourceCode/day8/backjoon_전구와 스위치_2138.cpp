//#include <iostream>
//#include <vector>
//#include <string>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int answer = INT_MAX;
//string s, target_s;
//
//void solve(string cur_s, int cnt);
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cin >> N;
//	string s;
//	cin >> s;
//	cin >> target_s;
//	// 첫번째 전구 누르지 않는 경우
//	solve(s, 0);
//	// 첫번째 전구 누르는 경우
//	string temp_s = s;
//	if (temp_s[0] == '0') temp_s[0] = '1'; else temp_s[0] = '0';
//	if (temp_s[1] == '0') temp_s[1] = '1'; else temp_s[1] = '0';
//	solve(temp_s, 1);
//	if (answer == INT_MAX) cout << -1;
//	else cout << answer;
//	return 0;
//}
//
//void solve(string cur_s, int cnt) {
//	for (int i = 1; i < N; i++) {
//		if (cur_s[i - 1] != target_s[i - 1]) {
//			// i-1 이 다르면 스위치 누름
//			cnt++;
//			cur_s[i - 1] = cur_s[i - 1] == '0' ? '1' : '0';
//			cur_s[i] = cur_s[i] == '0' ? '1' : '0';
//			if (i != N - 1)
//				cur_s[i + 1] = cur_s[i + 1] == '0' ? '1' : '0';
//		}
//	}
//	if (cur_s == target_s) answer = min(answer, cnt);
//}
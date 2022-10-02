// https://softeer.ai/practice/info.do?idx=1&eid=804

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string key_s, message_s;

void solve(vector<vector<char>>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> message_s >> key_s;
	vector<vector<char>>v(5, vector<char>(5));
	solve(v);
	return 0;
}

void solve(vector<vector<char>>& v) {
	vector<bool>visited(26, false);
	// 'J' 는 사용 X
	visited['J' - 'A'] = true;
	int row = 0, col = 0;
	for (size_t i = 0; i < key_s.size(); i++) {
		if (col == 5) {
			col = 0;
			row++;
		}
		if (row >= 5) break;
		char cur_c = key_s[i];
		if(!visited[cur_c - 'A']) {
			v[row][col] = cur_c;
			visited[cur_c - 'A'] = true;
			col++;
		}
	}
	// 나머지 문자 채우기
	for (int i = 0; i < 26; i++) {
		if (col == 5) {
			col = 0;
			row++;
		}
		if (row >= 5) break;
		char cur_c = i + 'A';
		if (!visited[i]) {
			v[row][col] = cur_c;
			visited[i] = true;
			col++;
		}
	}
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	// 메세지 나누기
	vector<string>encryption_v;
	for (size_t i = 0; i < message_s.size(); i++) {
		string s = "";
		char cur_c = message_s[i];
		if (i == message_s.size() - 1) {
			s.push_back(cur_c); s.push_back('X');
			encryption_v.push_back(s);
			break;
		}
		char next_c = message_s[i + 1];
		if (cur_c != next_c) {
			s.push_back(cur_c); s.push_back(next_c);
			encryption_v.push_back(s);
			i++;
		}
		else {
			if (cur_c != 'X') {
				s.push_back(cur_c); s.push_back('X');
				encryption_v.push_back(s);
			}
			else {
				s.push_back('X'); s.push_back('Q');
				encryption_v.push_back(s);
			}
		}
	}
	//for (auto e : encryption_v)
	//	cout << e << " ";
	//cout << endl;

	// 암호화 하기
	string answer = "";
	for (string s : encryption_v) {
		int first_c = s[0];
		int second_c = s[1];
		int first_row = -1, first_col = -1;
		int second_row = -1, second_col = -1;
		int find_cnt = 0;
		for (int i = 0; i < 5 && find_cnt < 2; i++) {
			for (int j = 0; j < 5 && find_cnt < 2; j++) {
				if (first_c == v[i][j]) {
					first_row = i;
					first_col = j;
					find_cnt++;
				}
				if (second_c == v[i][j]) {
					second_row = i;
					second_col = j;
					find_cnt++;
				}
			}
		}
		/*
			1. 만약, 두 글자가 표에서 같은 행에 존재하면, 오른쪽으로 한 칸 이동한 칸에 적힌 글자로 암호화된다. 
			예를 들어 HE를 암호화하면 EI가 되고, XX를 암호화하면 ZZ가 된다. 위치가 다섯 번째 열이라면 첫 번째 열로 이동하게 된다.
		*/
		char first_enc_c = '0', second_enc_c = '0';
		if (first_row == second_row) {
			if (first_col == 4) 
				first_enc_c = v[first_row][0];
			else 
				first_enc_c = v[first_row][first_col + 1];
			if (second_col == 4)
				second_enc_c = v[second_row][0];
			else
				second_enc_c = v[second_row][second_col + 1];
		}
		/*
			2. 1.의 경우를 만족하지 않으면서 두 글자가 표에서 같은 열에 존재하면, 아래쪽으로 한 칸 이동한 칸에 적힌 글자로 암호화된다. 
			예를 들어 LO를 암호화하면 RV가 된다. 위치가 다섯 번째 행이라면 첫 번째 행으로 이동하게 된다.
		*/
		else if (first_col == second_col) {
			if (first_row == 4)
				first_enc_c = v[0][first_col];
			else
				first_enc_c = v[first_row + 1][first_col];
			if (second_row == 4)
				second_enc_c = v[0][second_col];
			else
				second_enc_c = v[second_row + 1][second_col];
		}
		/*
			3. 1, 2의 경우를 만족하지 않으면서, 두 글자가 표에서 서로 다른 행, 열에 존재하면, 두 글자가 위치하는 칸의 열이 서로 교환된 위치에 적힌 글자로 암호화된다. 
			예를 들어 LX를 암호화하면 YV가 된다.
		*/
		else {
			first_enc_c = v[first_row][second_col];
			second_enc_c = v[second_row][first_col];
		}
		answer.push_back(first_enc_c); answer.push_back(second_enc_c);
	}
	for (auto e : answer) cout << e << "";
}

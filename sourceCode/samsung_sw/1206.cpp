// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T = 10;
int n;

void solve(vector<int>& v, int prob_num);

int main() {
	while (T--) {
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		//v;
		solve(v, 10 - T);
	}
	return 0;
}

void solve(vector<int>& v, int prob_num) {
	int cnt = 0;
	for (int i = 2; i < n - 2; i++) {
		int cur_floor = v[i];
		int left_left_floor = v[i - 2];
		int left_floor = v[i - 1];
		int right_right_floor = v[i + 2];
		int right_floor = v[i + 1];
		int max_floor = left_left_floor;
		max_floor = max(max_floor, left_floor);
		max_floor = max(max_floor, right_right_floor);
		max_floor = max(max_floor, right_floor);
		if (cur_floor > max_floor) {
			int temp = cur_floor - max_floor;
			cnt += temp;
		}
		
	}
	cout << "#" << prob_num << " " << cnt << "\n";
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int answer = 0;

void solve(vector<int>& v, int cur_sum, int card_cnt, int cur_ind);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	solve(v, 0, 0, 0);
	cout << answer;
	return 0;
}
void solve(vector<int>& v, int cur_sum, int card_cnt, int cur_ind) {
	if (card_cnt == 3) {
		if (cur_sum <= M) {
			answer = max(answer, cur_sum);
		}
		return;
	}
	if (cur_ind >= N) return;
	// 카드 뽑을경우
	solve(v, cur_sum + v[cur_ind], card_cnt + 1, cur_ind + 1);
	// 카드 안뽑을 경우
	solve(v, cur_sum, card_cnt, cur_ind + 1);
}


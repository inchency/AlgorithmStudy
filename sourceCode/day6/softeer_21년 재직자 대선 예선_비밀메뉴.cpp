#include <iostream>
#include <vector>

using namespace std;

int M, N, K;

int main() {
	ios::sync_with_stdio(0);
	cin >> M >> N >> K;
	vector<int>answer(M);
	vector<int>candi(N);
	for (int i = 0; i < M; i++) cin >> answer[i];
	for (int i = 0; i < N; i++) cin >> candi[i];
	bool flag = false;
	for (int i = 0; i < N; i++) {
		int cur_candi_num = candi[i];
		int temp_i = i;
		for (int j = 0; j < M; j++) {
			int cur_answer_num = answer[j];
			if (cur_candi_num != cur_answer_num) 
				break;
			else {
				if (j == M - 1)
					flag = true;
				else
					cur_candi_num = candi[++temp_i];
			}
		}
		if (flag) break;
	}
	if (flag) cout << "secret";
	else cout << "normal";
	return 0;
}
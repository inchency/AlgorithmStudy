#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct RGB {
	int R, G, B;
};

void solve(vector<RGB>& v);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<RGB>v(N);
	for (int i = 0; i < N; i++) {
		RGB rgb;
		cin >> rgb.R >> rgb.G >> rgb.B;
		v[i] = rgb;
	}
	solve(v);
	return 0;
}

void solve(vector<RGB>& v) {
	vector<int>dp_r(N);
	vector<int>dp_g(N);
	vector<int>dp_b(N);
	dp_r[0] = v[0].R; dp_g[0] = v[0].G; dp_b[0] = v[0].B;
	for (int i = 1; i < N; i++) {
		// dp의 r값 구하기 (g랑 b에서 올 수 있음)
		dp_r[i] = min(dp_g[i - 1] + v[i].R, dp_b[i - 1] + v[i].R);
		// dp의 g값 구하기 (r랑 b에서 올 수 있음)
		dp_g[i] = min(dp_r[i - 1] + v[i].G, dp_b[i - 1] + v[i].G);
		// dp의 b값 구하기 (r랑 g에서 올 수 있음)
		dp_b[i] = min(dp_r[i - 1] + v[i].B, dp_g[i - 1] + v[i].B);
	}
	vector<int>answer;
	answer.push_back(*(dp_r.end() - 1));
	answer.push_back(*(dp_g.end() - 1));
	answer.push_back(*(dp_b.end() - 1));
	cout << *min_element(answer.begin(), answer.end());
}
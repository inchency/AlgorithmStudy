#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

bool isPrime(int n);
void solve(int a, int b); // a는 첫번째 자리수, b는 진행하고 있는 자리수 1의 자리면 1 2의 자리면 2

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 2; i <= 7; i++) {
		if (i == 2 || i == 3 || i == 5 || i == 7) {
			solve(i, 1);
		}
	}
	return 0;
}

void solve(int a, int b) {
	if (b == N) // 물어본 자리수와 일치하면
		cout << a << endl;
	int temp;
	// 홀수만 비교
	for (int i = 1; i <= 9; i += 2) {
		temp = a * 10 + i;
		if (isPrime(temp))
			solve(temp, b + 1);
	}
}

bool isPrime(int n) {
	if (n < 2) return false;
	else if (n == 2) return true;
	for (int i = 3; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>>v(n + 1, vector<int>(m + 1));
    for (auto e : puddles) {
        int row = e[1];
        int col = e[0];
        v[row][col] = -1;
    }
    v[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == 0) {
                int up = v[i - 1][j];
                int left = v[i][j - 1];
                if (up == -1) up = 0;
                if (left == -1) left = 0;
                v[i][j] = (up + left) % 1000000007;
            }
        }
    }
    answer = v[n][m];
    return answer;
}
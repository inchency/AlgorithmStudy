// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=cpp 
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int d_row[4] = { -1, 1, 0, 0 };
int d_col[4] = { 0, 0, -1, 1 };

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    int y = 1;
    int x = total / y;
    while (x >= y) {
        vector<vector<bool>>visited(y, vector<bool>(x, false));
        visited[0][0] = true;
        for (int i = 1; i < y - 1; i++) {
            for (int j = 1; j < x - 1; j++) {
                visited[i][j] = true;
            }
        }
        queue<pair<int, int>>q;
        q.push({ 0, 0 });
        int sum_brown = 1;
        
        while (!q.empty()) {
            int now_row = q.front().first;
            int now_col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int next_row = now_row + d_row[i];
                int next_col = now_col + d_col[i];
                if (next_row >= 0 && next_row < y && next_col >= 0 && next_col < x) {
                    if (!visited[next_row][next_col]) {
                        visited[next_row][next_col] = true;
                        sum_brown++;
                        q.push({ next_row, next_col });
                    }
                }
            }
        }
        int sum_yellow = total - sum_brown;
        if (sum_yellow == yellow && sum_brown == brown) {
            answer.push_back(x);
            answer.push_back(y);
        }
        do {
            y++;
            x = total / y;
        } while (x * y != total);
    }
    return answer;
}

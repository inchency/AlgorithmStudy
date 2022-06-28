
// https://programmers.co.kr/learn/courses/30/lessons/17679
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Info {
    int row, col;
    char user;
};

bool is_square(vector<string>& board, vector<vector<bool>>& visited, int row, int col, int m, int n) {
    char cur_user = board[row][col];
    if (row + 1 < m && col + 1 < n) {
        if (board[row + 1][col] == cur_user && board[row][col + 1] == cur_user && board[row + 1][col + 1] == cur_user) {
            visited[row][col] = true;
            visited[row + 1][col] = true;
            visited[row][col + 1] = true;
            visited[row + 1][col + 1] = true;
            return true;
        }
    }
    return false;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check = true;
    while (check) {
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        check = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '*') {
                    if (is_square(board, visited, i, j, m, n))
                        check = true;
                }
            }
        }

        // visited = true인거 user 삭제
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) {
                    board[i][j] = '*';
                }
            }
        }

        // '*' 공간 채우기
        for (int col = 0; col < n; col++) {
            stack<char>temp_stack;
            for (int row = 0; row < m; row++) {
                if (board[row][col] != '*') {
                    temp_stack.push(board[row][col]);
                }
            }
            int reset_row = m - 1;
            while (!temp_stack.empty()) {
                char cur = temp_stack.top();
                temp_stack.pop();
                board[reset_row--][col] = cur;
            }
            while (reset_row >= 0)
                board[reset_row--][col] = '*';

        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '*')
                answer++;
        }
    }

    return answer;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>cnt_v(n + 1, 1);
    vector<bool>reserve_check(n + 1, false);
    for (int ind : reserve) {
        cnt_v[ind]++;
        reserve_check[ind] = true;
    }
    for (int ind : lost) {
        cnt_v[ind] -= 1;
        reserve_check[ind] = false;
    }
    for (int i = 1; i < n + 1; i++) {
        if (cnt_v[i] == 0) {
            if (i - 1 >= 1 && cnt_v[i - 1] >= 1 && reserve_check[i - 1]) {
                answer++;
                cnt_v[i - 1]--;
            }
            else if (i + 1 <= n && cnt_v[i + 1] >= 1 && reserve_check[i + 1]) {
                answer++;
                cnt_v[i + 1]--;
            }
        }
        else {
            answer++;
            cnt_v[i]--;
        }
    }
    return answer;
}

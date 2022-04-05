// https://programmers.co.kr/learn/courses/30/lessons/1835

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Info {
    char a_name;
    char b_name;
    char cond;
    char cond_num;
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<Info>info_v;
    for (int i = 0; i < n; i++) {
        Info info;
        info.a_name = data[i].substr(0, 1)[0];
        info.b_name = data[i].substr(2, 1)[0];
        info.cond = data[i].substr(3, 1)[0];
        info.cond_num = data[i].substr(4, 1)[0];
        info_v.push_back(info);
    }

    // 모든 경우의 수 구하기
    vector<char>base_v;
    base_v.push_back('A'); base_v.push_back('C'); base_v.push_back('F'); base_v.push_back('J');
    base_v.push_back('M'); base_v.push_back('N'); base_v.push_back('R'); base_v.push_back('T');
    do {
        vector<int>char_ind_v(26);
        for (size_t i = 0; i < base_v.size(); i++) {
            char_ind_v[base_v[i] - 'A'] = i;
        }
        // 반복문 돌며 조건 만족하는지 체크
        bool flag = true;
        for (Info info : info_v) {
            int diff = abs(char_ind_v[info.a_name - 'A'] - char_ind_v[info.b_name - 'A']) - 1;
            if (info.cond == '=') {
                if (diff != info.cond_num - '0') {
                    flag = false;
                    break;
                }
            }
            else if (info.cond == '>') {
                if (diff <= info.cond_num - '0') {
                    flag = false;
                    break;
                }
            }
            else {
                if (diff >= info.cond_num - '0') {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
            answer++;
    } while (next_permutation(base_v.begin(), base_v.end()));
    return answer;
}

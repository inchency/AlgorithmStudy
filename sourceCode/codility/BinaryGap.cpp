// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    string s = "";
    while (N / 2 > 0) {
        s += to_string(N % 2);
        N = N / 2;
    }
    s += "1";
    reverse(s.begin(), s.end());
    int answer = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            int zero_cnt = 0;
            if (i + 1 < s.length()) {
                i++;
                if (s[i] == '0') zero_cnt++;
                while (1) {
                    if (i + 1 == s.length()) break;
                    if (s[i + 1] == '1') {
                        answer = max(answer, zero_cnt);
                        break;
                    }
                    zero_cnt++;
                    i++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}

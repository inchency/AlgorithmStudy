https://school.programmers.co.kr/learn/courses/9899
// https://school.programmers.co.kr/learn/courses/9899/lessons/55837

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int multi_n(int N, int cnt) {
    int res = N;
    int mul = 10;
    for (int i = 1; i < cnt; i++) {
        res = res + mul * N;
        mul *= 10;
    }
    return res;
}

int get_Ns(int N, int idx) { 
    // NN(idx==1), NNN(idx==2), NNNN(idx==3)...과 같은 형태만드는 함수
    int result = N; 
    for (int i = 1; i <= idx; i++) { 
        result = result * 10 + N; 
    } 
    return result; 
} 

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>>dp(10);
    dp[1].insert(N);
    // cout << *dp[1].begin();
    for (int i = 1; i <= 8; i++) {
        dp[i].insert(multi_n(N, i));
        for (int j = 1; j < i; j++) {
            int k = i - j;
            if(k==0) continue;
            for (int e : dp[j]) {
                for (int ee : dp[k]) {
                    dp[i].insert(e * ee);
                    dp[i].insert(e + ee);
                    if (e - ee > 0)
                        dp[i].insert(e - ee);
                    if (e / ee > 0)
                        dp[i].insert(e / ee);
                }
            }
        }
        if(dp[i].find(number) != dp[i].end())
            return i;
    }
    return -1;
}

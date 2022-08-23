// Part2
// https://school.programmers.co.kr/learn/courses/9899
// https://school.programmers.co.kr/learn/courses/9899/lessons/55821

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>cnt_v(n+1, 1);
    for(int i : lost)
        cnt_v[i] -= 1;
    for(int i : reserve)
        cnt_v[i] += 1;
    for(int i=1; i<= n; i++){
        if(cnt_v[i] == 0){
            if(i-1 >= 1 && cnt_v[i-1] >= 2){
                cnt_v[i-1] -= 1;
                cnt_v[i] += 1;
                continue;
            }
            else if(i+1 <= n && cnt_v[i+1] >= 2){
                cnt_v[i+1] -= 1;
                cnt_v[i] += 1;
                continue;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(cnt_v[i] >= 1) answer++;
    }
    return answer;
}

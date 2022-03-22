// https://programmers.co.kr/learn/courses/30/lessons/42889
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const pair<int, double> & a, const pair<int, double> & b){
    if(a.second == b.second){
        if(a.first < b.first) return true;
        else return false;
    }
    else{
        if(a.second > b.second) return true;
        else return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> fail_v; // 스테이지, 실패율
    int size = stages.size();
    for(int stage = 1; stage <= N; stage++){
        double total_cnt = 0;
        double fail_cnt = 0;
        for(int i=0; i<size; i++){
            if(stages[i] >= stage) total_cnt++;
            if(stages[i] == stage) fail_cnt++;
        }
        if(total_cnt == 0) 
            fail_v.push_back({stage, 0});
        else   
            fail_v.push_back({stage, fail_cnt / total_cnt});
    }
    sort(fail_v.begin(), fail_v.end(), comp);
    for(auto e : fail_v) answer.push_back(e.first);
    return answer;
}

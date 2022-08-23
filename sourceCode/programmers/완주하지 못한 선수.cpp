// https://school.programmers.co.kr/learn/courses/9899/lessons/55817

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int>m;
    for(string name : participant){
        if(m.find(name) == m.end())
            m[name] = 0;
        m[name] += 1;
    }
    for(string name : completion)
        m[name] -= 1;
    for(pair<string, int>p : m){
        if(p.second >= 1){
            answer = p.first;
            break;
        }
    }
    return answer;
}

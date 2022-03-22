// https://programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int size = new_id.size();
    // 1단계 && 2단계
    for(int i=0; i<size; i++){
        char cur_char = new_id[i];
        if(cur_char >= 'A' && cur_char <= 'Z')
            answer.push_back(tolower(cur_char));
        else {
            if(cur_char >= 'a' && cur_char <= 'z')
                answer.push_back(tolower(cur_char));
            else if(cur_char >= '0' && cur_char <= '9')
                answer.push_back(tolower(cur_char));
            else if(cur_char == '-' || cur_char == '_' || cur_char == '.')
                answer.push_back(tolower(cur_char));
        }
    }
    // 3단계
    bool flag = false;
    string answer2 = "";
    for(size_t i=0; i<answer.size(); i++){
        char cur_char = answer[i];
        if(cur_char == '.') {
            if(!flag) {
                flag = true;
                answer2.push_back(cur_char);
            }
        }
        else {
            flag = false;
            answer2.push_back(cur_char);
        }
    }
    // 4단계
    if(answer2[answer2.size()-1] == '.') answer2.pop_back();
    if(answer2[0] == '.') answer2.erase(0, 1);
    // 5단계
    if(answer2 == "") answer2.push_back('a');
    // 6단계
    string answer3 = "";
    for(size_t i=0; i<answer2.size(); i++){
        char cur_char = answer2[i];
        if(i < 15) answer3.push_back(cur_char);
    }
    if(answer3[answer3.size()-1] == '.') answer3.pop_back();
    // 7단계
    string answer4 = answer3;
    if(answer3.size() <= 2){
        char last_char = answer3[answer3.size()-1];
        while(1){
            answer4.push_back(last_char);
            if(answer4.size() == 3) break;
        }
    }
    return answer4;
}

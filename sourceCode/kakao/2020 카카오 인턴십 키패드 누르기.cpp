// https://programmers.co.kr/learn/courses/30/lessons/67256
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


void map_init(map<char, pair<int, int>>&m){
    m['*'] = {0, 0}; m['0'] = {1, 0}; m['#'] = {2, 0};
    m['7'] = {0, 1}; m['8'] = {1, 1}; m['9'] = {2, 1};
    m['4'] = {0, 2}; m['5'] = {1, 2}; m['6'] = {2, 2};
    m['1'] = {0, 3}; m['2'] = {1, 3}; m['3'] = {2, 3};
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<char, pair<int, int>>m; // 숫자, 좌표
    map_init(m);
    char cur_left_dir = '*';
    char cur_right_dir = '#';
    set<char>left_s;
    left_s.insert('1'); left_s.insert('4'); left_s.insert('7');
    set<char>right_s;
    right_s.insert('3'); right_s.insert('6'); right_s.insert('9');
    for(int number_int : numbers){
        char number = number_int + '0';
        if(left_s.find(number) != left_s.end()){
            cur_left_dir = number;
            answer.push_back('L');
        }
        else if(right_s.find(number) != right_s.end()){
            cur_right_dir = number;
            answer.push_back('R');
        }
        else{
            pair<int, int> cur_left_coordinate = m[cur_left_dir]; // 현재 왼 손가락 좌표
            pair<int, int> cur_right_coordinate = m[cur_right_dir]; // 현재 오른 손가락 좌표
            pair<int, int> next_number_coordinate = m[number]; // 다음 number의 좌표
            int left_diff = abs(cur_left_coordinate.first - next_number_coordinate.first)
                + abs(cur_left_coordinate.second - next_number_coordinate.second);
            int right_diff = abs(cur_right_coordinate.first - next_number_coordinate.first)
                + abs(cur_right_coordinate.second - next_number_coordinate.second);
            if(left_diff == right_diff){
                if(hand == "left"){
                    cur_left_dir = number;
                    answer.push_back('L');
                }
                else{
                    cur_right_dir = number;
                    answer.push_back('R');
                }
            }
            else if(left_diff < right_diff){
                cur_left_dir = number;
                answer.push_back('L');
            }
            else{
                cur_right_dir = number;
                answer.push_back('R');
            }
        }
    }
    
    return answer;
}

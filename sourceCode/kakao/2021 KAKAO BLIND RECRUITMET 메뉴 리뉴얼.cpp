// https://programmers.co.kr/learn/courses/30/lessons/72411

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
set<vector<char>>s;

bool comp(const string &a, const string &b){
    if(a < b) return true;
    else return false;
}

void combination(vector<char>&all_orders, vector<char>cur_v, int target_num, int cur_cnt, int cur_ind){
    if(target_num == cur_cnt){
        // sort(v.begin(), v.end(), comp);
        s.insert(cur_v);
        return;
    }
    else if(cur_ind == all_orders.size()) return;
    // 해당 인덱스 선택할 경우
    cur_v.push_back(all_orders[cur_ind]);
    combination(all_orders, cur_v, target_num, cur_cnt+1, cur_ind+1);
    // 해당 인덱스 선택 안할 경우
    cur_v.pop_back();
    combination(all_orders, cur_v, target_num, cur_cnt, cur_ind+1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    set<char>temp_s;
    for(string order : orders){
        for(char c : order){
            temp_s.insert(c);
        }
    }
    vector<char>empty_v;
    // combination(all_orders, empty_v, 3, 0, 0);
    for(int order_cnt : course){
        map<string, int>m;
        s.clear();
        // 13,14,15 시간초과 -> 컴비네이션의 개수를 줄이자! 전체경우로 하면 시간초과
        for(string order : orders){
            vector<char>all_orders;
            for(char c : order)
                all_orders.push_back(c);
            sort(all_orders.begin(), all_orders.end());
            combination(all_orders, empty_v, order_cnt, 0, 0);
        }
        for(vector<char>c_v : s){
            string str = "";
            for(char c : c_v){
                str += c;
            }
            m[str] = 0;
        }
        // 갯수 세기
        for(pair<string, int>p : m){
            for(string order : orders){
                int cnt = 0;
                for(char c : p.first){
                    if(order.find(c) != string::npos) 
                        cnt++;
                }
                if(cnt == p.first.length())
                    m[p.first] += 1;
            }
        }
        // for(pair<string, int>p : m) cout << p.first << ":" << p.second << ", ";
        // cout << endl;
        int max_num = 0;
        for(pair<string, int>p : m){
            max_num = max(max_num, p.second);
        }
        if(max_num > 1){
            for(pair<string, int>p : m){
                if(p.second == max_num) answer.push_back(p.first);
            }
        }
    }
    sort(answer.begin(), answer.end(), comp);
    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct Info {
    vector<bool>candidate_visited;
    vector<string>candidate_answer;
    string cur_place;
};

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<pair<string, int>>>um; // pair는 티켓의 인덱스 (해당 티켓 썼는지 확인하기 위함)
    int ind = 0;
    for (auto e : tickets) {
        if (um.find(e[0]) == um.end()) {
            vector<pair<string, int>>temp_v;
            temp_v.push_back(make_pair(e[1], ind));
            um[e[0]] = temp_v;
        }
        else
            um[e[0]].push_back(make_pair(e[1], ind));
        ind++;
    }
    for (auto it = um.begin(); it != um.end(); it++) {
        string key = it->first;
        vector<pair<string, int>>temp_v = (*it).second;
        sort(temp_v.begin(), temp_v.end());
        um[key] = temp_v;
    }
    // test 출력문
    for (auto it = um.begin(); it != um.end(); it++) {
        string key = it->first;
        vector<pair<string, int>>temp_v = (*it).second;
        cout << key << " : ";
        for (auto e : temp_v) {
            cout << e.first << " " << e.second << "  ";
        }
        cout << "\n";
    }
    int total_tickets_cnt = tickets.size();
    queue<Info>q;
    vector<bool>visited(total_tickets_cnt, false);
    Info info;
    vector<string>temp_v;
    temp_v.push_back("ICN");
    info.candidate_visited = visited;
    info.candidate_answer = temp_v;
    info.cur_place = "ICN";
    q.push(info);
    while (!q.empty()) {
        vector<bool>candidate_visited = q.front().candidate_visited;
        vector<string>candidate_answer = q.front().candidate_answer;
        string cur_place = q.front().cur_place;
        q.pop();
        if (candidate_answer.size() - 1 == total_tickets_cnt) {
            for (auto e : candidate_answer) cout << e << " ";
            cout << endl;
            answer = candidate_answer;
            break;
        }
        vector<pair<string, int>>temp_v = um[cur_place];
        for (auto e : temp_v) {
            string next_place = e.first;
            int next_ticket_ind = e.second;
            if (!candidate_visited[next_ticket_ind]) {
                candidate_visited[next_ticket_ind] = true;
                candidate_answer.push_back(next_place);
                Info info2;
                info2.candidate_visited = candidate_visited;
                info2.candidate_answer = candidate_answer;
                info2.cur_place = next_place;
                q.push(info2);
                candidate_visited[next_ticket_ind] = false;
                candidate_answer.pop_back();
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<string>> tickets;
    vector<string>temp_v;
    temp_v.push_back("ICN"); temp_v.push_back("SFO");
    tickets.push_back(temp_v);

    temp_v.clear();
    temp_v.push_back("ICN"); temp_v.push_back("ATL");
    tickets.push_back(temp_v);

    temp_v.clear();
    temp_v.push_back("SFO"); temp_v.push_back("ATL");
    tickets.push_back(temp_v);

    temp_v.clear();
    temp_v.push_back("ATL"); temp_v.push_back("ICN");
    tickets.push_back(temp_v);

    temp_v.clear();
    temp_v.push_back("ATL"); temp_v.push_back("SFO");
    tickets.push_back(temp_v);

    solution(tickets);
    return 0;
}
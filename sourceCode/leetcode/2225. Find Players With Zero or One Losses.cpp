// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int>w_m;
        map<int, int>l_m;
        for (vector<int> e : matches) {
            int win_user = e[0];
            int lose_user = e[1];
            if (w_m.find(win_user) == w_m.end()) {
                w_m[win_user] = 0;
            }
            w_m[win_user] += 1;
            if (l_m.find(lose_user) == l_m.end()) {
                l_m[lose_user] = 0;
            }
            l_m[lose_user] += 1;
        }
        vector<vector<int>>answer(2);
        for (pair<int, int>w_p : w_m) {
            int win_user = w_p.first;
            if (l_m.find(win_user) == l_m.end()) {
                answer[0].push_back(win_user);
            }
        }
        for (pair<int, int>l_p : l_m) {
            int lose_user = l_p.first;
            int lose_user_cnt = l_p.second;
            if (lose_user_cnt == 1) {
                answer[1].push_back(lose_user);
            }
        }
        return answer;
    }
};

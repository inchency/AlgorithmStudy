#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int>um;
    for (string s : phone_book) {
        for (size_t i = 0; i < s.length(); i++) {
            string sub_s = s.substr(0, i);
            if (um.find(sub_s) == um.end()) {
                um[sub_s] = 1;
            }
        }
    }
    for (string s : phone_book) {
        if (um.find(s) != um.end()) {
            answer = false;
            break;
        }
    }
    return answer;
}